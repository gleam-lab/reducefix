#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    int q;
    cin >> q;
    multiset<int> ms;
    set<int> st;
    rep(i, q) {
        int type, x;
        cin >> type;
        if (type == 1) {
            cin >> x;
            ms.insert(x);
            st.insert(x);
        } else if (type == 2) {
            cin >> x;
            auto it = ms.find(x);
            if (it != ms.end()) {
                ms.erase(it);
                if (ms.count(x) == 0) {
                    st.erase(x);
                }
            }
        } else if (type == 3) {
            cout << st.size() << endl;
        }
    }
}