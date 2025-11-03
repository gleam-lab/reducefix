//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cstring>
#include <cmath>
#include <set>
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#define rep(i, n) for (int i=0; i<n; ++i)
using namespace std;


int main() {
  int N;
  cin >> N;
  //vector<long long> t = {-1, -1, -3};
 
  long long ans = 0, syo, amari, pos = 0;
  rep(i, N){
    long long H;
    cin >> H;
    syo = H / 5;
    ans += syo*3;
    amari = H % 5;
    if (amari == 1 && (pos == 0 || pos == 1)){
      ans++;
      pos++;
    }
    else if (amari == 2 && pos == 0){
      ans += 2;
      pos += 2;
    }
    else if (amari == 2 && pos != 0){
      ans += 2;
      pos += 2;
      pos %= 3;
    }
    else if (amari == 3 && (pos == 0 || pos == 1)){
      ans += 3;
      pos += 3;
      pos %= 3;
    }
    else if (amari == 3 && pos == 2){
      ans += 1;
      pos = 0;
    }
    else if (amari == 4 && pos == 0){
      ans += 3;
      pos += 3;
      pos %= 3;
    }
    else if (amari == 4 && (pos == 1 || pos == 2)){
      ans += 2;
      pos += 2;
      pos %= 3;
    }
  }
  cout << ans << endl;
      
    
}
