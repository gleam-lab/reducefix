#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> st;
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        if (x == 1) {
            int t; cin >> t; // This line is actually redundant and can be removed
            st.insert(t); // This line should be st.insert(x);
        } else if (x == 2) {
            int t; cin >> t; // This line is actually redundant and can be removed
            st.erase(t); // This line should be st.erase(x);
        } else if (x == 3) {
            cout << st.size() << "\n";
        }
    }
    return 0;
}