#include <set>
#include <iostream>
using namespace std;

int main() {
    int q; cin >> q; // Read the number of queries
    set<int> st;    // Use set to store unique integers

    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;

        if (x == 1) {
            int t;
            cin >> t; // Read the integer value to be added
            st.insert(t); // Add the integer to the set
        } else if (x == 2) {
            int t;
            cin >> t; // Read the integer value to be removed
            st.erase(t); // Remove the integer from the set
        } else if (x == 3) {
            cout << st.size() << endl; // Output the number of unique integers
        }
    }

    return 0;
}