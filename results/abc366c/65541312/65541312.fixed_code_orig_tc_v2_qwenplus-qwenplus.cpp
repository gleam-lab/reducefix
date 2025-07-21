#include <bits/stdc++.h>
using namespace std;

void solve() {
    int q;
    cin >> q;
    unordered_map<int, int> freq; // To keep track of frequency of each number
    int distinct_count = 0;      // To store the current count of distinct integers

    for (int i = 0; i < q; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            int x;
            cin >> x;
            if (freq[x] == 0) {
                distinct_count++; // First occurrence, increase distinct count
            }
            freq[x]++;
        } else if (a == 2) {
            int y;
            cin >> y;
            freq[y]--;
            if (freq[y] == 0) {
                distinct_count--; // No more occurrences, decrease distinct count
            }
        } else if (a == 3) {
            cout << distinct_count << endl;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}