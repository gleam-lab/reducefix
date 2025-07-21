#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    cin >> Q;

    set<int> st;
    for (int i = 0; i < Q; ++i) {
        int x;
        cin >> x;
        if (x == 1) {
            int t;
            cin >> t;
            st.insert(t);
        } else if (x == 2) {
            int t;
            cin >> t;
            st.erase(t);
        } else if (x == 3) {
            cout << st.size() << "\n";
        }
    }

    return 0;
}