#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, x, limit) for (int i = (x); i < (limit); i++)

void solve() {
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    ll total = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total += A[i];
    }
    ll rem = K - total;

    vector<pair<ll, int>> sortedA(N);
    for (int i = 0; i < N; ++i) {
        sortedA[i] = {A[i], i};
    }
    sort(sortedA.begin(), sortedA.end());

    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sortedA[i].first;
    }

    vector<ll> res(N);

    for (int idx = 0; idx < N; ++idx) {
        ll a_i = A[idx];

        // Binary search for minimum X
        ll low = 0;
        ll high = rem;
        ll ans = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_score = a_i + mid;
            ll remaining = rem - mid;

            // Find how many candidates have votes > new_score
            int l = 0, r = N;
            while (l < r) {
                int m = (l + r) / 2;
                if (sortedA[m].first > new_score)
                    r = m;
                else
                    l = m + 1;
            }
            int greater_count = N - l;

            if (greater_count >= M) {
                // Not enough to guarantee win
                low = mid + 1;
                continue;
            }

            int need_to_limit = M - greater_count - 1;
            if (need_to_limit <= 0) {
                // Already in top M
                ans = mid;
                high = mid - 1;
                continue;
            }

            // There are `need_to_limit` candidates that we must restrict to <= new_score
            int pos = lower_bound(sortedA.begin(), sortedA.end(), make_pair(new_score + 1, -1)) - sortedA.begin();
            int available = pos - (N - need_to_limit);
            if (available < 0) {
                // Not enough candidates to restrict
                low = mid + 1;
                continue;
            }

            ll required_votes = (new_score + 1) * need_to_limit - (prefix[pos] - prefix[pos - need_to_limit]);
            if (remaining >= required_votes) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        res[idx] = (ans == -1 ? -1 : ans);
    }

    for (int i = 0; i < N; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}