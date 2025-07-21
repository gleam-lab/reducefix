#include <bits/stdc++.h>
using namespace std;

void solve() {
    int q;
    cin >> q;
    unordered_map<int, int> freq; // To keep track of frequencies of each number
    int distinct_count = 0;

    for (int i = 0; i < q; ++i) {
        int a;
        cin >> a;
        if (a == 1) {
            int x;
            cin >> x;
            if (freq[x] == 0) {
                distinct_count++;
            }
            freq[x]++;
        } else if (a == 2) {
            int y;
            cin >> y;
            freq[y]--;
            if (freq[y] == 0) {
                distinct_count--;
            }
        } else if (a == 3) {
            cout << distinct_count << endl;
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