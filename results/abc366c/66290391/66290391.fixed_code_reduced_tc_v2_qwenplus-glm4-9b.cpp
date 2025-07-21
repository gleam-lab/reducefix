#include <iostream>
#include <set>

using namespace std;

int main() {
    int q;
    cin >> q;
    set<int> st;
    while (q--) {
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
    }
    return 0;
}