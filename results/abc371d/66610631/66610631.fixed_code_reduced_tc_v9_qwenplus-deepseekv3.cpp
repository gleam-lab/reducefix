#include <bits/stdc++.h>
using namespace std;
using LL = __int128;
typedef long long ll;
const int N = 1e6+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n;
    vector<int> a(n+1, 0), b(n+1, 0);
    vector<ll> c(n+1, 0); // Use long long to prevent overflow
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        c[i] = c[i-1] + b[i];
    }
    
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        auto l_it = lower_bound(a.begin() + 1, a.end(), l);
        auto r_it = upper_bound(a.begin() + 1, a.end(), r);
        
        int l_idx = l_it - a.begin();
        int r_idx = r_it - a.begin();
        
        if (l_idx > r_idx) {
            cout << 0 << endl;
        } else if (l_idx == 1 && r_idx == n + 1) {
            cout << c[n] << endl;
        } else if (l_idx == 1) {
            cout << c[r_idx - 1] << endl;
        } else if (r_idx == n + 1) {
            cout << c[n] - c[l_idx - 2] << endl;
        } else {
            cout << c[r_idx - 1] - c[l_idx - 2] << endl;
        }
    }
    
    return 0;
}