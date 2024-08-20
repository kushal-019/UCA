#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 1024

void init_ncurses() {
    initscr();                // Initialize the window
    raw();                    // Disable line buffering
    keypad(stdscr, TRUE);     // Enable special keys handling
    noecho();                 // Don't echo user input
    scrollok(stdscr, TRUE);  // Enable scrolling
}

void cleanup_ncurses() {
    endwin();                 // End ncurses mode
}

void display_text(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int y = 0;
    while (fgets(line, sizeof(line), file)) {
        mvprintw(y++, 0, "%s", line);
        if (y >= LINES - 1) { // Prevent overflow of the window
            break;
        }
    }
    fclose(file);
}

void edit_text(const char *filename) {
    char buffer[MAX_LINE_LENGTH];
    int row = 0, col = 0;
    FILE *file = fopen(filename, "a+");
    if (!file) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    // Read existing content into buffer
    fseek(file, 0, SEEK_SET);
    while (fgets(buffer, sizeof(buffer), file)) {
        mvprintw(row++, 0, "%s", buffer);
        if (row >= LINES - 1) { // Prevent overflow of the window
            break;
        }
    }

    // Main editing loop
    while (1) {
        int ch = getch();
        switch (ch) {
            case KEY_BACKSPACE:
            case 127:
                if (col > 0) {
                    mvdelch(row, --col);
                }
                break;
            case KEY_ENTER:
            case '\n':
                if (row < LINES - 1) {
                    row++;
                    col = 0;
                }
                break;
            case 27: // Escape key to exit
                fclose(file);
                return;
            default:
                if (ch >= 32 && ch <= 126) { // Printable characters
                    mvaddch(row, col++, ch);
                    // Save the character to file (you may want to handle this differently)
                    fputc(ch, file);
                }
                break;
        }
        move(row, col);
        refresh();
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];

    init_ncurses();

    printw("Opening file '%s'...\n", filename);
    display_text(filename);
    printw("\nEditing file '%s'...\n", filename);

    edit_text(filename);

    cleanup_ncurses();
    return EXIT_SUCCESS;
}
