#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> va(n), vb(n-1);
    for(int i=0; i<n; ++i) cin >> va[i];
    for(int i=0; i<n-1; ++i) cin >> vb[i];

    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());

    int l = 1, r = 1e9;
    while(l <= r) {
        int m = (l + r) / 2;
        bool ok = true;
        for(int i=0; i<n-1; ++i) {
            auto it = lower_bound(va.begin(), va.end(), vb[i]);
            if(it == va.end() || *it > m) {
                ok = false;
                break;
            }
        }
        if(ok) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    if(l > 1e9) cout << -1 << '\n';
    else cout << l << '\n';

    return 0;
}