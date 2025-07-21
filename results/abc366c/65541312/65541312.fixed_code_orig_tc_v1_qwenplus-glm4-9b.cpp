#include <bits/stdc++.h>
using namespace std;

void solve() {
    ios::sync_with_stdio(false); // speed up input
    cin.tie(NULL);

    int q;
    cin >> q;
    set<int> st;
    vector<int> results;

    for (int i = 0; i < q; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            int x;
            cin >> x;
            st.insert(x);
        } else if (a == 2) {
            int y;
            cin >> y;
            st.erase(y);
        } else if (a == 3) {
            results.push_back(st.size());
        }
    }

    for (int result : results) {
        cout << result << endl;
    }
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}