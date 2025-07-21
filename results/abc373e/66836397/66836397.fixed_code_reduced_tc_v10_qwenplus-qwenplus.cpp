#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, x, limit) for (int i = (x); i < (limit); i++)
#define all(x) x.begin(), x.end()

void solve() {
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    ll total = 0;
    for (auto &a : A) {
        cin >> a;
        total += a;
    }
    ll rem = K - total;

    vector<pair<ll, int>> sortedA(N);
    for (ll i = 0; i < N; ++i)
        sortedA[i] = {A[i], i};
    sort(all(sortedA));

    vector<ll> prefix(N + 1);
    for (ll i = 0; i < N; ++i)
        prefix[i + 1] = prefix[i] + sortedA[i].first;

    vector<ll> res(N);

    for (ll idx = 0; idx < N; ++idx) {
        ll a_i = sortedA[idx].first;
        ll pos = sortedA[idx].second;

        // Binary search
        ll low = 0, high = rem;
        ll ans = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll votes_needed = 0;
            ll required = M - 1;

            // Binary search upper bound in sortedA
            ll l = 0, r = N;
            while (l < r) {
                ll m = (l + r) / 2;
                if (sortedA[m].first > a_i + mid)
                    r = m;
                else
                    l = m + 1;
            }
            ll greater_count = N - l;

            if (greater_count >= M) {
                low = mid + 1;
                continue;
            }

            required -= greater_count;
            if (required <= 0) {
                ans = mid;
                high = mid - 1;
                continue;
            }

            // Need to boost this candidate's vote count so that at most M-1 have more
            ll left = max(0LL, idx - required);
            ll count_boost = required;
            ll needed = (a_i + mid + 1) * count_boost - (prefix[idx] - prefix[left]);
            if (needed <= rem - mid) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        res[sortedA[idx].second] = (ans == -1 ? -1 : ans);
    }

    for (ll i = 0; i < N; ++i)
        cout << max(0LL, res[i]) << " ";
    cout << "\n";
}

int main() {
    solve();
    return 0;
}