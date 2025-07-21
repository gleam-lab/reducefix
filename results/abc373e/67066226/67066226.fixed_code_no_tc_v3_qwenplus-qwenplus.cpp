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
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Total remaining votes
    ll total_remaining = K;
    for (ll a : A) total_remaining -= a;

    vector<int> ord(N);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return A[i] < A[j]; });
    vector<ll> sorted_A = A;
    sort(all(sorted_A));

    vector<ll> prefix_sum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + sorted_A[i];
    }

    vector<ll> result(N, -1);

    for (int idx = 0; idx < N; ++idx) {
        ll a_i = sorted_A[idx];
        int original_index = ord[idx];

        ll low = 0;
        ll high = total_remaining;
        ll answer = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_score = a_i + mid;

            // Binary search to find how many candidates have score >= new_score
            int left = 0, right = N;
            while (left < right) {
                int m = (left + right) / 2;
                if (sorted_A[m] >= new_score) right = m;
                else left = m + 1;
            }
            int pos = left; // First index where A[index] >= new_score

            // We want at least (N - M) candidates with score >= new_score
            // So we need at least (N - M) candidates not exceeding new_score - 1
            // Which means candidate i must be in the top M candidates
            // => At most M-1 candidates can have strictly more than new_score
            // => The number of candidates with >= new_score must be >= (N - (M - 1)) = N - M + 1

            int count_ge = N - pos;
            int needed_ge = N - M + 1;

            if (count_ge >= needed_ge) {
                // Try smaller X
                answer = mid;
                high = mid - 1;
            } else {
                // Need more votes
                low = mid + 1;
            }
        }

        if (answer > total_remaining) {
            result[original_index] = -1;
        } else if (answer <= 0) {
            result[original_index] = 0;
        } else {
            result[original_index] = answer;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << result[i] << " ";
    }
    cout << "\n";

    return 0;
}