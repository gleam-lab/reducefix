#include<bits/stdc++.h>
#define ll long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define sp ' '
using namespace std;

void solve(){
ll N;
cin>>N;
vector<ll> a(N), b(N-1);
for(ll &x : a){
  cin>>x;
}
for(ll &x : b){
  cin>>x;
}
sort(a.begin(), a.end());
sort(b.begin(), b.end());

ll j = 0;
for(ll i = 0; i < N; ++i){
  while(j < N-1 && a[i] > b[j]) ++j;
  if(j == N-1 || a[i] > b[j]){
    cout<<-1<<'\n';
    return;
  }
  ++j;
}
cout<<a.back()<<'\n';
}

int main(){
ios::sync_with_stdio(0);
cin.tie(0);

solve();

return 0;
}