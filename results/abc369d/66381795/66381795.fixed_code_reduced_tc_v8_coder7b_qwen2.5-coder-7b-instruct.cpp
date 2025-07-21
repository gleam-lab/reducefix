#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
int n, a;
int main(){
 cin >> n;
 vector<ll> data(n);
 rep(i, n){
   cin >> data[i];
 } 
 ll sum = 0;
 rep(i, n-1){
   if(data[i+1]*2 > data[i]+data[i+1]){
      sum += data[i+1]*2;
      i++;
   } else {
      sum += data[i];
   }
 }
 sum += data[n-1]; // Add the last element separately
 cout << sum << endl;
 return 0;
}