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

    // For each candidate, we'll compute the answer separately
    vector<ll> res(N, -1);

    // Precompute prefix sums of sorted votes
    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i)
        prefix[i + 1] = prefix[i] + SA[i].first;

    // Process each candidate
    for (int idx = 0; idx < N; ++idx) {
        ll lo = 0, hi = K + 1;
        ll target_votes = SA[idx].first;
        int original_idx = SA[idx].second;

        auto is_guaranteed_winner = [&](ll additional_votes) {
            ll total = target_votes + additional_votes;
            
            // Binary search to find how many candidates have votes > total
            int l = 0, r = N, m;
            while (l < r) {
                m = (l + r) / 2;
                if (SA[m].first > total)
                    r = m;
                else
                    l = m + 1;
            }
            return l >= N - M;
        };

        // Binary search for minimum X
        ll answer = -1;
        while (lo <= hi) {
            ll mid = (lo + hi) / 2;
            if (is_guaranteed_winner(mid)) {
                answer = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        res[original_idx] = (answer <= K) ? answer : -1;
    }

    // Print result
    for (ll val : res)
        cout << val << ' ';
    cout << '\n';

    return 0;
}