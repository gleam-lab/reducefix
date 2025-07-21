#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    cin >> n;
    
    vector<ll> x(n), p(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    
    vector<ll> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + p[i];
    }
    
    cin >> q;
    while (q--) {
        ll L, R;
        cin >> L >> R;
        
        int l = lower_bound(x.begin(), x.end(), L) - x.begin();
        int r = upper_bound(x.begin(), x.end(), R) - x.begin();
        
        ll sum = prefix_sum[r] - prefix_sum[l];
        cout << sum << '\n';
    }
    
    return 0;
}