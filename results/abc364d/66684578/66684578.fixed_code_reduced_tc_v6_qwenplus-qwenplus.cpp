#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define all(c) begin(c), end(c)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N, Q;
    cin >> N >> Q;

    vll A(N);
    rep(i, N) cin >> A[i];
    sort(all(A));

    rep(q, Q) {
        ll b, k;
        cin >> b >> k;

        // Binary search on distance
        ll left = 0, right = 2e14 + 5;
        while (left < right) {
            ll mid = (left + right) / 2;

            // Find number of elements in A within [b - mid, b + mid]
            ll low = lower_bound(all(A), b - mid) - A.begin();
            ll up = upper_bound(all(A), b + mid) - A.begin();
            ll count = up - low;

            if (count >= k)
                right = mid;
            else
                left = mid + 1;
        }

        cout << left << "\n";
    }
}