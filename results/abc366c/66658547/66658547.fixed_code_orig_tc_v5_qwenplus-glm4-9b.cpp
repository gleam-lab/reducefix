#include <iostream>
#include <set>
using namespace std;

int main() {
    int q; cin >> q;
    set<int> st;
    while (q--) {
        int x; cin >> x;
        if (x == 1) {
            // No need to read the value t, just insert x into the set
            st.insert(x);
        } else if (x == 2) {
            // No need to read the value t, just erase x from the set
            st.erase(x);
        } else if (x == 3) {
            // Print the size of the set which represents the number of different integers
            cout << st.size() << "\n";
        }
    }
    return 0;
}