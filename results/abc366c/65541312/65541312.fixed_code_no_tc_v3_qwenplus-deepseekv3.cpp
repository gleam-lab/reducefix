#include<bits/stdc++.h>
using namespace std;

void solve() {
    int q;
    cin >> q;
    unordered_map<int, int> count_map;
    int unique_count = 0;
    for (int i = 0; i < q; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            int x;
            cin >> x;
            count_map[x]++;
            if (count_map[x] == 1) {
                unique_count++;
            }
        } else if (a == 2) {
            int y;
            cin >> y;
            count_map[y]--;
            if (count_map[y] == 0) {
                unique_count--;
            }
        } else if (a == 3) {
            cout << unique_count << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}