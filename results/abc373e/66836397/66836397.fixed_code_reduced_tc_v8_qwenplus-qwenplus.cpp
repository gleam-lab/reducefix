#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for (ll i = 0; i < N; ++i) {
        cin >> A[i];
        K -= A[i];
    }

    vector<pll> sorted_A(N);
    for (ll i = 0; i < N; ++i) {
        sorted_A[i] = {A[i], i};
    }
    sort(sorted_A.begin(), sorted_A.end());

    vector<ll> res(N, -1);

    // Prefix sums of the sorted votes
    vector<ll> prefix(N + 1, 0);
    for (ll i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i].first;
    }

    for (ll i = 0; i < N; ++i) {
        ll left = 0, right = K + 1;
        while (left < right) {
            ll mid = (left + right) / 2;

            // Simulate adding `mid` votes to candidate i
            ll new_vote = A[i] + mid;

            // Binary search to find how many candidates have votes > new_vote
            ll l = 0, r = N;
            while (l < r) {
                ll m = (l + r) / 2;
                if (sorted_A[m].first > new_vote)
                    r = m;
                else
                    l = m + 1;
            }
            ll cnt_greater = N - l;

            if (cnt_greater >= M) {
                // Not enough, need more votes
                left = mid + 1;
            } else {
                // Might be enough, try fewer votes
                right = mid;
            }
        }

        // Check if it's possible with left votes
        if (left <= K) {
            res[i] = left;
        } else {
            res[i] = -1;
        }
    }

    for (ll i = 0; i < N; ++i) {
        cout << res[i] << " ";
    }
    cout << "\n";

    return 0;
}