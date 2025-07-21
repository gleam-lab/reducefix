#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  map<int, int> a; // Using map instead of set to keep track of count
  
  while(n--){
    int x; cin >> x;
    if(x == 1){
      int y; cin >> y;
      a[y]++; // Increment count of y
    }
    
    else if(x == 2){
      int y; cin >> y;
      a[y]--; // Decrement count of y
      if(a[y] == 0)
        a.erase(y); // If count becomes zero, erase y from map
    }
    
    else if(x == 3){
      cout << a.size() << endl; // Number of unique elements in map
    }
  }

  return 0;
}