#include <bits/stdc++.h>
using namespace std;

void solve() {
    int q;
    cin >> q;
    map<int, int> freq;  // To track frequency of each number
    set<int> unique;     // To maintain distinct numbers in the bag

    for (int i = 0; i < q; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            int x;
            cin >> x;
            if (freq[x] == 0) {
                unique.insert(x);
            }
            freq[x]++;
        } else if (a == 2) {
            int y;
            cin >> y;
            freq[y]--;
            if (freq[y] == 0) {
                unique.erase(y);
            }
        } else if (a == 3) {
            cout << unique.size() << endl;
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