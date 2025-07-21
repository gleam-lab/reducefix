#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void Solve() {
    unordered_map<int, bool> bag; // Map to store the balls
    int Q;
    cin >> Q;
    while (Q--) {
        int a;
        cin >> a;
        if (a == 1) {
            int x;
            cin >> x;
            bag[x] = true; // Put a ball with value x into the bag
        } else if (a == 2) {
            int x;
            cin >> x;
            bag.erase(x); // Remove a ball with value x from the bag
        } else {
            cout << bag.size() << "\n"; // Output the number of different integers
        }
    }
}

int main() {
    Solve();
    return 0;
}