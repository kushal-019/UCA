#include<bits/stdc++.h>
using namespace std;

int main(){

  int n;
  cin>>n;
  vector<int>arr;
  for(int i=0;i<n;i++){
      int x;
      cin>>x;
      arr.push_back(x);
  }
  
  unordered_map<int,int>mp;
  
  int start = 0 , ans = -1;
  
  for(int i=0;i<n;i++){
    mp[arr[i]] ++;
    if(mp.size() > 2){
      mp[arr[start]]--;
      if(mp[arr[start]] == 0)mp.erase(arr[start]);
      start++;
    }
      ans = max(ans , i-start +1);
  }
  cout<<ans;
  return 0;  
}

