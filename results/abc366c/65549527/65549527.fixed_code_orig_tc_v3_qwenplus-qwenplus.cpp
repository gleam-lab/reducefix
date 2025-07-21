#include <bits/stdc++.h>
using namespace std;

void solve() {
    int q;
    cin >> q;
    unordered_map<int, int> freq;
    int distinct = 0;

    for (int i = 0; i < q; ++i) {
        int a;
        cin >> a;
        if (a == 1) {
            int x;
            cin >> x;
            if (freq[x] == 0)
                distinct++;
            freq[x]++;
        } else if (a == 2) {
            int x;
            cin >> x;
            freq[x]--;
            if (freq[x] == 0)
                distinct--;
        } else if (a == 3) {
            cout << distinct << "\n";
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}