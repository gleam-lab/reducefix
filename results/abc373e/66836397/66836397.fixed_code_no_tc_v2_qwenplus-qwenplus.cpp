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
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total += A[i];
    }
    ll remaining = K - total;

    vector<pair<ll, int>> sortedA(N);
    for (int i = 0; i < N; ++i) {
        sortedA[i] = {A[i], i};
    }
    sort(all(sortedA));

    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sortedA[i].first;
    }

    vector<ll> result(N);

    for (int idx = 0; idx < N; ++idx) {
        ll a_i = A[idx];
        ll low = 0, high = remaining;
        ll ans = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_vote = a_i + mid;

            // Find how many candidates have votes > new_vote
            // Binary search in sortedA to find the first index where votes > new_vote
            int l = 0, r = N;
            while (l < r) {
                int m = (l + r) / 2;
                if (sortedA[m].first > new_vote)
                    r = m;
                else
                    l = m + 1;
            }
            int greater_count = N - l;

            if (greater_count >= M) {
                // Too many candidates with more votes, need more votes
                low = mid + 1;
                continue;
            }

            // Need to make sure at most M-1 candidates have more than us
            // So we can allow up to (M - 1 - greater_count) more candidates to have > new_vote
            int max_allowed_more = M - 1 - greater_count;
            if (max_allowed_more < 0) {
                low = mid + 1;
                continue;
            }

            // Take top `max_allowed_more` candidates who have <= new_vote and increase them to new_vote + 1
            // These are the ones that can potentially surpass our candidate
            int pos = l - 1;
            ll needed = 0;
            for (int j = 0; j < max_allowed_more && pos >= 0; ++j, --pos) {
                needed += (new_vote + 1 - sortedA[pos].first);
            }

            if (needed <= remaining - mid) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        result[idx] = (ans == -1 ? -1 : ans);
    }

    for (int i = 0; i < N; ++i) {
        if (i > 0) cout << " ";
        cout << result[i];
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}