#include <bits/stdc++.h>
using namespace std;

void solve() {
    int q;
    cin >> q;
    
    multiset<int> bag;
    unordered_map<int, int> countMap;

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            bag.insert(x);
            countMap[x]++;
        } else if (type == 2) {
            int x;
            cin >> x;
            auto it = bag.find(x);
            if (it != bag.end()) {
                bag.erase(it);
                countMap[x]--;
                if (countMap[x] == 0) {
                    countMap.erase(x);
                }
            }
        } else if (type == 3) {
            cout << countMap.size() << "\n";
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