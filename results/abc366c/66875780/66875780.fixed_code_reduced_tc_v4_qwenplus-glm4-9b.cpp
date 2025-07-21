#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int Q;
    cin >> Q;
    unordered_map<int, bool> bag;
    while (Q--) {
        int query;
        cin >> query;
        if (query == 1) {
            int x;
            cin >> x;
            bag[x] = true;  // Mark the ball with integer x as present
        } else if (query == 2) {
            int x;
            cin >> x;
            bag.erase(x);  // Remove the ball with integer x from the bag
        } else {
            cout << bag.size() << "\n";  // Output the number of different integers in the bag
        }
    }
    return 0;
}