#include <iostream>
#include <set>
using namespace std;

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int q;
    cin >> q;
    set<int> st;
    multiset<int> bag;
    
    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int x;
            cin >> x;
            bag.insert(x);
            st.insert(x);
        } else if (type == 2) {
            int x;
            cin >> x;
            auto it = bag.find(x);
            if (it != bag.end()) {
                bag.erase(it);
                if (bag.count(x) == 0) {
                    st.erase(x);
                }
            }
        } else if (type == 3) {
            cout << st.size() << '\n';
        }
    }
}

int main() {
    solve();
    return 0;
}