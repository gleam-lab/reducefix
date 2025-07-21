#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define ll long long
#define rep1(i, a) for (ll i = 0; i < a; i++)
#define rep2(i, a, b) for (ll i = a; i < b; i++)
#define rrep1(i, a) for (ll i = a - 1; i >= 0; i--)
#define rrep2(i, a, b) for (ll i = a - 1; i >= b; i--)
#define all(v) v.begin(), v.end()

ll inf = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> A(n), B(n);
        rep1(i, n) cin >> A[i];
        rep1(i, n) cin >> B[i];

        sort(all(A));  // Sort A for the largest element at A[k-1]
        vector<ll> B_sorted(B.begin(), B.end());

        //çåç¼å
        vector<ll> prefix_sum(n + 1, 0);
        for (ll i = 1; i <= n; i++) {
            prefix_sum[i] = prefix_sum[i - 1] + B_sorted[i - 1];
        }

        ll ans = inf;
        // éåææå¯è½çæå°åkä¸ªBçå
        for (ll i = 0; i <= k; i++) {
            ll sum_B = prefix_sum[i + k - 1];
            ll max_A = A[k - 1];
            ans = min(ans, max_A * sum_B);
        }

        cout << ans << '\n';
    }

    return 0;
}