#include <iostream>
#include <set>
using namespace std;

int main() {
    int q;
    cin >> q;
    set<int> st; // Using set to automatically handle duplicates and maintain unique integers.
    
    while (q--) {
        int x;
        cin >> x;
        if (x == 1) {
            int t;
            cin >> t;
            st.insert(t); // Inserting the integer into the set, which will automatically handle duplicates.
        } else if (x == 2) {
            int t;
            cin >> t;
            st.erase(t); // Removing the integer from the set.
        } else if (x == 3) {
            cout << st.size() << "\n"; // Outputting the number of unique integers in the set.
        }
    }
    
    return 0;
}