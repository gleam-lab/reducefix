#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,k,m,d,dmin=100000000;
  cin>>n>>k;
  vector<int>a(n);
  m=n-k;
  // if(m==1){
  //   cout<<0<<endl;
  //   return 0;
  // }
  
  for(int i=0;i<n;i++)cin>>a[i];
  sort(a.begin(),a.end());
  for(int i=0;i<k+1;i++){
    d=a[i+m-1] - a[i];
    dmin=min(dmin,d);
  }
  cout<<dmin<<endl;
}