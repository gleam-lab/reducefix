#include <bits/stdc++.h>
using namespace std;

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int q;
    cin >> q;
    unordered_map<int, int> count;
    int distinct = 0;
    
    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            if (count[x] == 0) {
                distinct++;
            }
            count[x]++;
        } else if (type == 2) {
            int x;
            cin >> x;
            if (count[x] == 1) {
                distinct--;
            }
            count[x]--;
        } else if (type == 3) {
            cout << distinct << '\n';
        }
    }
}

int main() {
    solve();
    return 0;
}