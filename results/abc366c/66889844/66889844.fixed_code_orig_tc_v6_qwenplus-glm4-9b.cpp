#include <iostream>
#include <set>
using namespace std;

int main() {
    int Q;
    cin >> Q;
    set<int> a; // This will store the different integers written on the balls.
    for (int i = 0; i < Q; i++) {
        int queryType;
        cin >> queryType;
        if (queryType == 1) {
            int x;
            cin >> x;
            a.insert(x); // Insert the ball with integer x into the bag.
        } else if (queryType == 2) {
            int x;
            cin >> x;
            a.erase(x); // Remove the ball with integer x from the bag.
        } else if (queryType == 3) {
            cout << a.size() << endl; // Print the number of different integers in the bag.
        }
    }
    return 0;
}