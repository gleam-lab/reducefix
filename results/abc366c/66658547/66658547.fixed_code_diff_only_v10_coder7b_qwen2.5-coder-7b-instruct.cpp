#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<int> st;
    int q; cin >> q;
    while(q--) {
        int x; cin >> x;
        if(x == 1) {
            int t; cin >> t;
            st.insert(t); // Insert operation is correct
        } else if(x == 2) {
            int t; cin >> t;
            auto it = st.find(t); // Correctly find the element before erasing
            if(it != st.end()) {
                st.erase(it); // Erase operation is correct
            }
        } else if(x == 3) {
            cout << st.size() << "\n"; // Size of set gives the number of unique elements
        }
    }

    return 0;
}