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
    ll total = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total += A[i];
    }
    ll remaining = K - total;

    // Sort A and prepare an index array to track original positions
    vector<int> idx(N);
    iota(all(idx), 0);
    sort(all(idx), [&](int x, int y) { return A[x] < A[y]; });
    vector<ll> sorted_A = A;
    sort(all(sorted_A));

    vector<ll> prefix_sum(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + sorted_A[i];
    }

    vector<ll> res(N, -1);

    for (int j = 0; j < N; ++j) {
        int i = idx[j];
        ll lo = 0, hi = remaining;
        ll ans = -1;
        ll current_votes = A[i];

        while (lo <= hi) {
            ll mid = (lo + hi) / 2;
            ll new_vote = current_votes + mid;

            // Find how many candidates can possibly have more than new_vote
            // All except possibly M top ones can be forced to be above new_vote
            // So we try to give enough to M candidates to be > new_vote

            // Binary search for first candidate with votes > new_vote
            int l = 0, r = N;
            while (l < r) {
                int m = (l + r) / 2;
                if (sorted_A[m] > new_vote)
                    r = m;
                else
                    l = m + 1;
            }
            int pos = l;

            // Try to make M-1 candidates have > new_vote
            // These would be the highest candidates excluding i itself
            int upper_limit = N - M;
            if (pos >= N && mid == 0) {
                // Already secure
                ans = 0;
                break;
            }

            if (pos > upper_limit) {
                // Too many people already have more
                hi = mid - 1;
                continue;
            }

            ll required = 0;
            // The top (N - M) candidates should not exceed new_vote
            // If some do, we can reduce their votes by taking from remaining votes
            // So we calculate how much we need to bring those down
            for (int k = upper_limit; k < N; ++k) {
                if (sorted_A[k] > new_vote)
                    required += sorted_A[k] - new_vote;
            }

            if (required <= remaining - mid) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        res[i] = ans;
    }

    for (auto x : res)
        cout << x << " ";
    cout << "\n";

    return 0;
}