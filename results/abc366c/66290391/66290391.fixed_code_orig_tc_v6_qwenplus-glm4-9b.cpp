#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    set<int> st;
    for (int type, x; q--;) {
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
    }
}