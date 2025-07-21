#include<bits/stdc++.h>
using namespace std;

void solve() {
    int q;
    cin >> q;
    set<int> st;
    for (int i = 0; i < q; i++) {
        int query_type, value;
        cin >> query_type;
        if (query_type == 1) {
            cin >> value;
            st.insert(value);
        } else if (query_type == 2) {
            cin >> value;
            st.erase(value);
        } else if (query_type == 3) {
            cout << st.size() << endl;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}