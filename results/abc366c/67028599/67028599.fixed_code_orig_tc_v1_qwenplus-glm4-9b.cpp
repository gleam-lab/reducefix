#include<bits/stdc++.h>

using namespace std;

int main() {
    // Disable synchronization with C++ standard library I/O
    ios_base::sync_with_stdio(false);
    // Unbuffered input and output
    cin.tie(NULL);

    // Read the number of queries
    int q;
    cin >> q;

    // Create a set to store unique integers
    set<int> h;

    while(q--) {
        int type, x;
        cin >> type;
        if (type == 1) {
            cin >> x;
            // Insert the integer into the set
            h.insert(x);
        } else if (type == 2) {
            cin >> x;
            // Remove the integer from the set
            h.erase(x);
        } else {
            // Output the size of the set for each query of the third type
            cout << h.size() << endl;
        }
    }

    return 0;
}