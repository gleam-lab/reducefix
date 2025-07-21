#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        if (x == 1) {
            int t; cin >> t;
            // Insert or check if the ball with integer t is already in the bag
            auto it = lower_bound(st.begin(), st.end(), t);
            if (it != st.end() && *it == t) {
                st.erase(it);  // Remove the existing ball if it exists
            } else {
                st.insert(t);  // Insert the new ball if it doesn't exist
            }
        } else if (x == 2) {
            int t; cin >> t;
            // Remove the ball with integer t from the bag
            auto it = lower_bound(st.begin(), st.end(), t);
            if (it != st.end() && *it == t) {
                st.erase(it);
            }
        } else if (x == 3) {
            // Output the number of different integers in the bag
            cout << st.size() << "\n";
        }
    }
    return 0;
}