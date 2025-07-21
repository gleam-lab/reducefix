#include<bits/stdc++.h>
using namespace std;

void solve() {
    int q;
    cin >> q;
    set<int> st;
    for (int i = 0; i < q; i++) {
        int query_type;
        cin >> query_type;
        if (query_type == 1) {
            int x;
            cin >> x;
            st.insert(x);
        } else if (query_type == 2) {
            int x;
            cin >> x;
            st.erase(x);
        } else if (query_type == 3) {
            cout << st.size() << endl;
        }
    }
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}