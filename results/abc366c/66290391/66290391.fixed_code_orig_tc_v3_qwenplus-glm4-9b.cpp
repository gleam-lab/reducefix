#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int q;
    cin >> q;
    set<int> st;
    bool started = false; // To keep track of whether we have started adding balls

    while (q--) {
        int type, x;
        cin >> type;
        if (type == 1) {
            if (!started) {
                started = true; // We have started adding balls now
            }
            cin >> x;
            st.insert(x);
        } else if (type == 2) {
            cin >> x;
            st.erase(x);
        } else if (type == 3) {
            if (started) { // Only process type 3 if we have started adding balls
                cout << st.size() << endl;
            }
        }
    }

    return 0;
}