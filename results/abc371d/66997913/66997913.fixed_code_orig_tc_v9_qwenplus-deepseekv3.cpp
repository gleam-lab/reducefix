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
    vector<ll> p(n), prefix(n+1);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        prefix[i+1] = prefix[i] + p[i];
    }
    
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        int right_idx = upper_bound(x.begin(), x.end(), r) - x.begin();
        int left_idx = lower_bound(x.begin(), x.end(), l) - x.begin();
        ll sum = prefix[right_idx] - prefix[left_idx];
        cout << sum << '\n';
    }
    
    return 0;
}