#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5 + 7;

int n, q;
ll x[maxn], p[maxn], sum[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> x[i] >> p[i];
    
    // Initialize prefix sum array
    sum[0] = 0;
    for (int i = 1; i <= n; ++i)
        sum[i] = sum[i - 1] + p[i];
    
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        
        // Find the first position where x[i] >= l using lower bound
        auto it_l = lower_bound(x + 1, x + n + 1, l);
        // Find the first position where x[i] > r using upper bound
        auto it_r = upper_bound(x + 1, x + n + 1, r);
        
        // Calculate the total number of villagers in the range [l, r]
        ll ans = sum[it_r - x - 1] - sum[it_l - x - 1];
        cout << ans << '\n';
    }
    return 0;
}