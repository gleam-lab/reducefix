#include<bits/stdc++.h>
using namespace std;
using LL = __int128;
typedef long long ll;
const int N = 2e5 + 7;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, q;
    cin >> n;
    vector<ll> x(n + 1), p(n + 1), prefix_sum(n + 1);

    for(int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for(int i = 1; i <= n; ++i) {
        cin >> p[i];
        prefix_sum[i] = prefix_sum[i - 1] + p[i];
    }

    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        
        auto it_l = lower_bound(x.begin() + 1, x.end(), l);
        auto it_r = upper_bound(x.begin() + 1, x.end(), r);
        
        int idx_l = it_l - x.begin();
        int idx_r = it_r - x.begin() - 1;
        
        if(idx_l > n || idx_r < 1) continue; // Handle out-of-bounds cases
        
        ll result = prefix_sum[idx_r] - prefix_sum[idx_l - 1];
        cout << result << '\n';
    }

    return 0;
}