#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int q;
    cin >> q;
    set<int> bag;  // Set to store unique integers
    vector<int> results;

    for (int i = 0; i < q; ++i) {
        int type, x;
        cin >> type;
        
        if (type == 1) {  // Add operation
            cin >> x;
            bag.insert(x);
        } else if (type == 2) {  // Remove operation
            cin >> x;
            bag.erase(x);
        } else if (type == 3) {  // Count operation
            results.push_back(bag.size());
        }
    }

    // Output the results of all count operations
    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}