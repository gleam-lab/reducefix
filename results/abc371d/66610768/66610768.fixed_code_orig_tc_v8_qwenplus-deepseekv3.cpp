#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    vector<ll> c(n + 1, 0);
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        c[i] = c[i - 1] + b[i];
    }
    
    int m;
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        
        auto it_l = lower_bound(a.begin() + 1, a.end(), l);
        int i = it_l - a.begin();
        
        auto it_r = upper_bound(a.begin() + 1, a.end(), r);
        int j = it_r - a.begin();
        
        if (i > n) {
            cout << "0\n";
        } else if (j <= i) {
            cout << "0\n";
        } else {
            cout << c[j - 1] - c[i - 1] << "\n";
        }
    }
    
    return 0;
}