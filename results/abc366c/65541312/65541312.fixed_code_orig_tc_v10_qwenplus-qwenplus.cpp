#include <bits/stdc++.h>
using namespace std;

void solve() {
    int q;
    cin >> q;
    unordered_map<int, int> freq;
    unordered_set<int> distinctCount;

    for (int i = 0; i < q; ++i) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            if (freq[x] == 0)
                distinctCount.insert(x);
            freq[x]++;
        } else if (op == 2) {
            int x;
            cin >> x;
            freq[x]--;
            if (freq[x] == 0)
                distinctCount.erase(x);
        } else if (op == 3) {
            cout << distinctCount.size() << "\n";
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

    solve();
}