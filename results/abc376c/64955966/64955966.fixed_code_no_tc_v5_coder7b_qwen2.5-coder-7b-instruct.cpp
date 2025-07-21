#include<bits/stdc++.h>
#define ll long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define sp ' '
using namespace std;

void solve(){
  ll N;
  cin >> N;
  vector<ll> a(N), b(N - 1);
  for(int i = 0; i < N; ++i){
    cin >> a[i];
  }
  for(int i = 0; i < N - 1; ++i){
    cin >> b[i];
  }
  
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  bool found = false;
  for(ll x = a[0]; x <= a.back(); ++x){
    vector<bool> used(N - 1, false);
    int j = 0;
    for(int i = 0; i < N && j < N - 1; ++i){
      while(j < N - 1 && (used[j] || a[i] > b[j])){
        ++j;
      }
      if(j == N - 1){
        break;
      }
      used[j++] = true;
    }
    if(j == N - 1){
      cout << x << endl;
      found = true;
      break;
    }
  }

  if(!found){
    cout << -1 << endl;
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}