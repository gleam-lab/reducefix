#include <bits/stdc++.h>
using namespace std;

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int q;
    cin >> q;
    unordered_map<int, int> count;
    int distinct = 0;
    
    for (int i = 0; i < q; ++i) {
        int a;
        cin >> a;
        if (a == 1) {
            int x;
            cin >> x;
            if (count[x] == 0) {
                distinct++;
            }
            count[x]++;
        } else if (a == 2) {
            int y;
            cin >> y;
            if (count[y] == 1) {
                distinct--;
            }
            count[y]--;
        } else if (a == 3) {
            cout << distinct << '\n';
        }
    }
}

int main() {
    solve();
    return 0;
}