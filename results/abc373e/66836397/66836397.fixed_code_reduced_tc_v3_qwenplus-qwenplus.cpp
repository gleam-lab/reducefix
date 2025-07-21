#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, limit) for (int i = (x); i < (limit); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
#define spa ' '

using ll = long long;

const ll infl = 1LL << 60;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    ll total = 0;
    for (ll i = 0; i < N; ++i) {
        cin >> A[i];
        total += A[i];
    }
    ll rem = K - total;

    // Create sorted list of current votes
    vector<ll> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());

    // Build prefix sums
    vector<ll> prefix(N + 1, 0);
    for (ll i = 0; i < N; ++i)
        prefix[i + 1] = prefix[i] + sorted_A[i];

    // For each candidate, binary search on minimum needed votes
    vector<ll> res(N, -1);
    for (ll idx = 0; idx < N; ++idx) {
        ll lo = 0, hi = rem;
        ll ans = -1;
        ll a_i = A[idx];

        while (lo <= hi) {
            ll mid = (lo + hi) / 2;
            ll new_vote = a_i + mid;

            // Find how many candidates have strictly more votes than new_vote
            ll r = upper_bound(sorted_A.begin(), sorted_A.end(), new_vote) - sorted_A.begin();

            // Total number of candidates with more votes is N - r
            if (N - r < M) {
                // Already good, we can try to use less additional votes
                ans = mid;
                hi = mid - 1;
            } else {
                // Need more votes
                lo = mid + 1;
            }
        }

        if (ans <= rem)
            res[idx] = (ans == -1 ? -1 : ans);
    }

    for (ll i = 0; i < N; ++i) {
        if (i > 0) cout << ' ';
        cout << res[i];
    }
    cout << el;

    return 0;
}