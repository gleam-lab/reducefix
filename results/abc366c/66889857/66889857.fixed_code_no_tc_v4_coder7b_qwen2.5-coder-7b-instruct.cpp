#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int n; cin >> n;
  unordered_set<int> a; // Changed set to unordered_set for better performance
  
  rep(i,n){
    int x; cin >> x;
    if(x == 1){
      int y; cin >> y;
      a.insert(y); // Insert operation remains the same
    }
    
    else if(x == 2){
      int y; cin >> y;
      a.erase(y); // Erase operation remains the same
    }
    
    else if(x == 3){
      cout << a.size() << endl; // Size operation remains the same
    }
  }
}