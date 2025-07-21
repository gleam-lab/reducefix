#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    set<int> st;
    for (int i = 0; i < q; ++i) {
        int type, x;
        cin >> type;
        if (type == 1) {
            cin >> x;
            st.insert(x);
        } else if (type == 2) {
            cin >> x;
            st.erase(x);
        } else if (type == 3) {
            cout << st.size() << endl;
        }
        // No need to exit the loop because the insertion/deletion is already done.
    }
}