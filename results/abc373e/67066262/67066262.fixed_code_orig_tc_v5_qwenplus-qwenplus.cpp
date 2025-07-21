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

    vector<ll> sorted_A = A;
    sort(all(sorted_A));

    vector<ll> prefix_sum(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + sorted_A[i];
    }

    vector<ll> result(N);
    for (int i = 0; i < N; ++i) {
        ll candidate_votes = A[i];
        // Binary search on required votes X
        ll low = 0, high = K;
        ll answer = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll total_after = candidate_votes + mid;

            // Find how many candidates have strictly more votes than total_after
            ll upper_count = N - (upper_bound(all(sorted_A), candidate_votes + mid) - sorted_A.begin());

            if (upper_count < M) {
                // We can win
                answer = mid;
                high = mid - 1;
            } else {
                // Not enough, try higher
                low = mid + 1;
            }
        }

        result[i] = (answer == -1 || answer > K) ? -1 : answer;
    }

    for (int i = 0; i < N; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
}