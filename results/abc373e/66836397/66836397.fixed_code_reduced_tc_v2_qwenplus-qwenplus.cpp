#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, limit) for (int i = (x); i < (limit); i++)
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " = " << x << '\n'

using ll = long long;
const ll infl = 1LL << 60;

int main() {
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    ll total = 0;
    for (auto &a : A) {
        cin >> a;
        total += a;
    }
    ll rem = K - total;

    vector<pair<ll, int>> sorted_A;
    for (ll i = 0; i < N; ++i) {
        sorted_A.emplace_back(A[i], i);
    }
    sort(all(sorted_A));

    vector<ll> prefix_sum(N + 1, 0);
    for (ll i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + sorted_A[i].first;
    }

    vector<ll> result(N);

    rep(i, 0, N) {
        ll idx_in_sorted;
        for (ll j = 0; j < N; ++j) {
            if (sorted_A[j].second == i) {
                idx_in_sorted = j;
                break;
            }
        }

        ll low = 0, high = rem;
        ll answer = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll required = 0;
            ll current_votes = A[i] + mid;

            // We need to ensure at least (M) candidates have strictly fewer votes than current_votes
            // So we find the number of candidates with votes < current_votes in the current state
            ll pos = lower_bound(all(sorted_A), make_pair(current_votes, -1)) - sorted_A.begin();

            // Exclude our candidate from the list if needed
            if (idx_in_sorted < pos) {
                pos--;
            }

            ll need = M;
            if (pos >= need) {
                // Enough candidates already have fewer votes than current_votes
                answer = mid;
                high = mid - 1;
            } else {
                // Need to increase some candidates' votes to be >= current_votes
                ll additional_needed = need - pos;
                ll l = N - additional_needed;
                ll total_cost = current_votes * (N - l) - (prefix_sum[N] - prefix_sum[l]);

                if (total_cost <= rem - mid) {
                    answer = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }

        result[i] = (answer <= rem) ? answer : -1;
    }

    rep(i, 0, N) {
        cout << result[i] << " ";
    }
    cout << '\n';

    return 0;
}