#include <bits/stdc++.h>
using namespace std;

void solve() {
    int q;
    cin >> q;
    
    unordered_map<int, int> freq;
    int distinct = 0;

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            if (freq[x] == 0) {
                ++distinct;
            }
            ++freq[x];
        } else if (type == 2) {
            int x;
            cin >> x;
            if (freq[x] > 0) {
                --freq[x];
                if (freq[x] == 0) {
                    --distinct;
                }
            }
        } else if (type == 3) {
            cout << distinct << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}