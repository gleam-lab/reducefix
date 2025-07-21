#include<bits/stdc++.h>
#define ll long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define sp ' '
using namespace std;

void solve(){
ll N;
cin>>N;
ll a[N], b[N-1];
for(int i=0;i<N;i++){
  cin>>a[i];
}
for(int i=0;i<N-1;i++){
  cin>>b[i];
}
sort(a, a+N);
sort(b, b+N-1);
if(b[N-2]<a[N-1]){
  cout<<-1<<endl;
  return;
}
ll ans = max(a[N-1], b[N-2]);
cout<<ans<<endl;
}

int main(){
ios::sync_with_stdio(0);
cin.tie(0);

solve();

return 0;
}