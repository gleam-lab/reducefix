#include<bits/stdc++.h>
using namespace std;

void solve() {
    int q;
    cin >> q;
    set<int>st;
    for (int i = 0; i < q; i++) {
        int a;
        cin >> a;  // Read the query type
        if (a == 1) {
            int x;
            cin >> x;  // Read the integer x for the '1 x' query
            st.insert(x);
        } else if (a == 2) {
            int y;
            cin >> y;  // Read the integer y for the '2 y' query
            st.erase(y);
        } else if (a == 3) {
            cout << st.size() << endl;  // Output the size of the set
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}