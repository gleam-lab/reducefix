#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int n; cin >> n;
  unordered_set<int> a; // Using unordered_set for faster insert and erase operations
  
  rep(i,n){
    int x; cin >> x;
    if(x == 1){
      int y; cin >> y;
      a.insert(y); // Inserting the element into the set
    }
    
    else if(x == 2){
      int y; cin >> y;
      a.erase(y); // Erasing the element from the set
    }
    
    else if(x == 3){
      cout << a.size() << endl; // Printing the size of the set which represents the number of unique elements
    }
  }
}