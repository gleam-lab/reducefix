#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    set<int> st;
    unordered_map<int, int> freqMap;

    rep(i, q) {
        int type, x;
        cin >> type;
        if (type == 1) {
            cin >> x;
            if (freqMap[x] > 0) {
                st.erase(st.find(x));
            }
            st.insert(x);
            freqMap[x]++;
        } else if (type == 2) {
            cin >> x;
            if (freqMap[x] > 0) {
                st.erase(st.find(x));
                freqMap[x]--;
                if (freqMap[x] == 0) {
                    freqMap.erase(x);
                }
            }
        } else if (type == 3) {
            cout << st.size() << endl;
        }
    }

    return 0;
}