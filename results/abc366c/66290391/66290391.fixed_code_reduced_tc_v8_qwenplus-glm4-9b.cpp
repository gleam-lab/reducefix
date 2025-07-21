#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    int q;
    cin >> q;
    set<int> st;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            st.insert(x);
        } else if (type == 2) {
            int x;
            cin >> x;
            st.erase(x);
        } else if (type == 3) {
            cout << st.size() << endl;
        }
    }
    return 0;
}