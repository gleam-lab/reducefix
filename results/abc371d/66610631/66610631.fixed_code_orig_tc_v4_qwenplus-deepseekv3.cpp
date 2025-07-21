#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<ll> a(n+1), b(n+1), c(n+2, 0);
    
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        c[i] = c[i-1] + b[i];
    }
    
    int m;
    cin >> m;
    while (m--) {
        ll l, r;
        cin >> l >> r;
        
        int left_pos = lower_bound(a.begin()+1, a.end(), l) - a.begin();
        int right_pos = upper_bound(a.begin()+1, a.end(), r) - a.begin();
        
        if (left_pos > right_pos) {
            cout << "0\n";
        } else if (left_pos > n) {
            cout << "0\n";
        } else {
            ll sum = c[right_pos-1] - (left_pos > 1 ? c[left_pos-2] : 0);
            cout << sum << '\n';
        }
    }
    
    return 0;
}