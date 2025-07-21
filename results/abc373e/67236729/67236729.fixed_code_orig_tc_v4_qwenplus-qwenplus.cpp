#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int N;
    cin >> N;
    int M;
    cin >> M;
    i64 K;
    cin >> K;
    
    vector<i64> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort the candidates' votes in descending order
    vector<i64> sorted_A = A;
    sort(sorted_A.rbegin(), sorted_A.rend());

    // Compute prefix sums for efficient range sum queries
    vector<i64> prefix_sum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + sorted_A[i];
    }

    vector<int> result(N);
    for (int i = 0; i < N; ++i) {
        i64 current_votes = A[i];

        // Binary search to find minimum X such that candidate i can win
        i64 left = 0;
        i64 right = K + 1; // upper bound for binary search

        while (left < right) {
            i64 mid = (left + right) / 2;
            i64 remaining = K - mid;

            if (remaining < 0) {
                left = mid + 1;
                continue;
            }

            // Use lower_bound to find first candidate with more than current_votes + mid
            int idx = lower_bound(sorted_A.begin(), sorted_A.end(), current_votes + mid, greater<i64>()) - sorted_A.begin();

            // Number of candidates with strictly more votes
            int strict_more = idx;

            if (strict_more < M) {
                // Already has enough votes to be in top (N-M+1)
                result[i] = 0;
                break;
            }

            // Need to beat the weakest candidate in the top M
            i64 needed_votes = max((i64)0, sorted_A[M - 1] - current_votes + 1 - mid);

            if (needed_votes <= remaining) {
                // Can afford to beat the threshold candidate
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        if (left > K) {
            result[i] = -1; // Cannot guarantee victory
        } else {
            result[i] = left;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}