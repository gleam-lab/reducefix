#include<bits/stdc++.h>
using namespace std;

void solve() {
    int q;
    cin >> q;
    set<int> st;
    for (int i = 0; i < q; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            int x;
            cin >> x;
            st.insert(x);  // The set will automatically handle the insertion and uniqueness
        } else if (a == 2) {
            int y;
            cin >> y;
            st.erase(y);  // The set will automatically handle the deletion
        } else if (a == 3) {
            cout << st.size() << endl;  // The size of the set will give us the number of different integers
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    solve();
    return 0;
}