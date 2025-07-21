#include <iostream>
#include <set>
using namespace std;

int main() {
    int q; cin >> q;
    set<int> st;
    while (q--) {
        int x; cin >> x;
        if (x == 1) {
            int t; cin >> t;
            st.insert(t);
        } else if (x == 2) {
            int t; cin >> t;
            st.erase(t);
        } else if (x == 3) {
            cout << st.size() << "\n";
        }
    }
    return 0;
}