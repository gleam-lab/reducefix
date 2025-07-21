#include <iostream>
#include <set>
using namespace std;

void solve() {
    int q;
    cin >> q;
    set<int> st;
    int x;
    for (int i = 0; i < q; i++) {
        cin >> x; // Read the type code of the query
        switch (x) {
            case 1: {
                cin >> x; // Read the value x for the add operation
                st.insert(x);
                break;
            }
            case 2: {
                cin >> x; // Read the value x for the remove operation
                st.erase(x);
                break;
            }
            case 3: {
                cout << st.size() << endl; // Output the number of elements in the set
                break;
            }
        }
    }
}

int main() {
    // Read the number of test cases
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}