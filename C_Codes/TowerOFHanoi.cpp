#include<bit/stdc++.h>

long long toh(int n, int from, int to, int aux) {
    long long count = 1;
    if(n == 0 || n == 1){
        cout<<"move disk "<<n<<" from rod "<<from<<" to rod "<<to<<endl;
        return count;
    }
    count += toh(n-1 , from , aux , to);
    cout<<"move disk "<<n<<" from rod "<<from<<" to rod "<<to<<endl;
    count += toh(n-1 , aux , to , from);
    return count;
        
}

int main()
{
  int n;
  cin>>n;
  
  cout<<toh(n,1,2,3);
  
  return 0;
}
