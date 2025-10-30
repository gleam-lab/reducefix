#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int N;
  cin >> N;
  vector<ll> H(N);
  for(int i=0;i<N;i++){
    cin >> H[i];
  }
  
  ll T=0;

  for(ll &h:H){
    ll set=h/5;
    T+=set*3;
    h-=set*5;

    while(h>0){
      T++;
      if(T%3==0) h-=3;
      else h-=1;
    }
  }
  cout << T << endl;
  return 0;
}