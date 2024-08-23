class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bitCount(32, 0);
        int negative = 0;

        for (int num : nums) {
            for (int i = 0; i < 32; ++i) {
                if(num <0 )num = abs(num) , negative++;
                if ((num >> i) & 1) {
                    bitCount[i]++;
                }
            }
        }

        int result = 0;
        for (int i = 0; i < 32; ++i) {
            if (bitCount[i] % 3) {
                result |= (1 << i);
            }
        }
        if(result < 0)return result;
        if ( negative % 3 ) {
            result *= -1;
        }

        return result;
    }
};

