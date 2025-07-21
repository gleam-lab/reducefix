#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    vector<ll> p(n), s(n+1, 0);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        s[i+1] = s[i] + p[i];
    }
    
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        int rt = upper_bound(x.begin(), x.end(), r) - x.begin();
        int lt = lower_bound(x.begin(), x.end(), l) - x.begin();
        cout << s[rt] - s[lt] << '\n';
    }
    return 0;
}