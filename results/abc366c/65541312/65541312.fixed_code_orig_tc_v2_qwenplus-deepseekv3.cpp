#include<bits/stdc++.h>
using namespace std;

void solve() {
    int q;
    cin >> q;
    unordered_map<int, int> count_map;
    int distinct_count = 0;
    for (int i = 0; i < q; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            int x;
            cin >> x;
            if (count_map[x] == 0) {
                distinct_count++;
            }
            count_map[x]++;
        } else if (a == 2) {
            int x;
            cin >> x;
            if (count_map[x] > 0) {
                count_map[x]--;
                if (count_map[x] == 0) {
                    distinct_count--;
                }
            }
        } else if (a == 3) {
            cout << distinct_count << endl;
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