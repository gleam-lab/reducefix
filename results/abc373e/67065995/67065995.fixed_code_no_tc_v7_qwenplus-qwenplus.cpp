#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for (ll &a : A) {
        cin >> a;
        K -= a;
    }

    // Create sorted version of A
    vector<pair<ll, int>> SA(N);
    for (int i = 0; i < N; ++i)
        SA[i] = {A[i], i};
    sort(all(SA));

    vector<ll> ans(N, -1);

    // Prepare prefix sums of sorted votes
    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i)
        prefix[i + 1] = prefix[i] + SA[i].first;

    auto get_min_votes = [&](int idx) {
        ll low = 0, high = K + 1;
        ll target = SA[idx].first;
        int pos = idx;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll need = mid;
            ll required_score = target + mid;

            // We want at least (N - M) candidates not exceeding our score
            // So at most (M - 1) candidates can have strictly more than us
            // Binary search the number of candidates that have score > required_score
            int left = 0, right = N;
            while (left < right) {
                int m = (left + right) / 2;
                if (SA[m].first > required_score)
                    right = m;
                else
                    left = m + 1;
            }
            int strictly_more = N - left;

            if (strictly_more >= M) {
                // Too many candidates have more votes, we don't win
                low = mid + 1;
                continue;
            }

            // To ensure we win, we need to make sure that even in worst case,
            // no more than M-1 candidates have more votes than us

            // We'll try to cap top (M-1) candidates above us at our score
            int cap_candidates = M - strictly_more;
            ll total_needed = 0;

            // Binary search for the threshold index
            int l = 0, r = N;
            while (l < r) {
                int m = (l + r) / 2;
                if (SA[m].first > required_score)
                    l = m + 1;
                else
                    r = m;
            }

            // Now SA[l..N-1] are candidates with score <= required_score
            // We need to reduce top (cap_candidates) of those above us to be <= us
            int from = max(0, l - cap_candidates);
            for (int i = l - 1; i >= from && cap_candidates > 0; --i, --cap_candidates) {
                if (SA[i].first > required_score) {
                    total_needed += SA[i].first - required_score;
                }
            }

            if (total_needed + mid <= K)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low <= K ? low : -1;
    };

    // Compute answer for each candidate
    for (int i = 0; i < N; ++i) {
        ll res = get_min_votes(i);
        ans[SA[i].second] = res == -1 ? -1 : res;
    }

    for (ll x : ans)
        cout << x << ' ';
    cout << '\n';

    return 0;
}