#include <iostream>
#include <set>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  set<int> balls;
  int queryType, value;

  for (int i = 0; i < n; i++) {
    cin >> queryType;
    if (queryType == 1) {
      cin >> value;
      balls.insert(value);
    } else if (queryType == 2) {
      cin >> value;
      balls.erase(value);
    } else if (queryType == 3) {
      cout << balls.size() << endl;
    }
  }

  return 0;
}