#include<bits/stdc++.h>
using namespace std;

void solve() {
    int q;
    cin >> q;
    map<int, int> mp;
    
    for (int i = 0; i < q; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            int x;
            cin >> x;
            mp[x]++;
        } else if (a == 2) {
            int y;
            cin >> y;
            if (mp[y] > 0) {
                mp[y]--;
                if (mp[y] == 0) {
                    mp.erase(y);
                }
            }
        } else if (a == 3) {
            cout << mp.size() << endl;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}