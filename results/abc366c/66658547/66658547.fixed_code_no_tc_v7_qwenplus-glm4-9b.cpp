#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int q;
    cin >> q;
    set<int> st;
    vector<int> results;

    while (q--) {
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
            results.push_back(st.size());
        }
    }

    for (int result : results) {
        cout << result << "\n";
    }

    return 0;
}