#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
#define all(a) a.begin(), a.end()
#define INF (1LL << 60)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, Q;
    cin >> N >> Q;

    vll A(N);
    rep(i, N) {
        cin >> A[i];
    }
    sort(all(A));

    rep(q, Q) {
        ll b, k;
        cin >> b >> k;

        // Binary search on distance
        ll left = 0;
        ll right = 2e8 + 10; // Sufficient upper bound

        while (left < right) {
            ll mid = (left + right) / 2;

            // Count number of points within [b - mid, b + mid]
            ll l = lower_bound(all(A), b - mid) - A.begin();
            ll r = upper_bound(all(A), b + mid) - A.begin();
            ll count = r - l;

            if (count >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        cout << left << "\n";
    }

    return 0;
}