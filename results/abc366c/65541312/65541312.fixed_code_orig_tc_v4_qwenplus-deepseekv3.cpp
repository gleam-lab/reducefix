#include <bits/stdc++.h>
using namespace std;

void solve() {
    int q;
    cin >> q;
    unordered_map<int, int> count;
    int distinct = 0;
    for (int i = 0; i < q; i++) {
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
            int x;
            cin >> x;
            if (count[x] > 0) {
                count[x]--;
                if (count[x] == 0) {
                    distinct--;
                }
            }
        } else if (a == 3) {
            cout << distinct << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}