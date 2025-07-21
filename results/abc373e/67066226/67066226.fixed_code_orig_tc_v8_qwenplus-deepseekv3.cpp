#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    ll total = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total += A[i];
    }
    ll remaining = K - total;
    vector<ll> sorted_A = A;
    sort(all(sorted_A), greater<ll>());

    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }

    vector<ll> ans(N, -1);
    for (int i = 0; i < N; ++i) {
        ll current = A[i];

        // Binary search for the minimal X
        ll low = 0, high = remaining;
        ll best_X = remaining + 1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = current + mid;

            // Find the number of candidates with votes > new_votes
            auto it = upper_bound(all(sorted_A), new_votes, greater<ll>());
            int cnt = it - sorted_A.begin();

            if (cnt < M) {
                best_X = mid;
                high = mid - 1;
            } else {
                // Need to ensure that at least M candidates are <= new_votes
                // So find the sum of votes of the first M candidates that are > new_votes
                // and set them to new_votes + 1, but this isn't directly possible.
                // Instead, we need to calculate the required votes to reduce the top M candidates to <= new_votes.
                ll sum_needed = prefix[cnt] - cnt * new_votes;
                if (cnt > M) {
                    sum_needed -= (prefix[cnt] - prefix[M] - (cnt - M) * new_votes);
                }
                if (sum_needed <= remaining - mid) {
                    best_X = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        if (best_X <= remaining) {
            ans[i] = best_X;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << ans[i] << ' ';
    }
    return 0;
}