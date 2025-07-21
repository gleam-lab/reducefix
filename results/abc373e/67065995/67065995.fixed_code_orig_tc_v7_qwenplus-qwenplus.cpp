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

    vector<ll> results(N, -1);

    // Create a list of candidate indices sorted by current votes in descending order
    vector<int> indices(N);
    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(), [&](int i, int j) { return A[i] > A[j]; });

    // Total sum of votes already used
    ll total_used = accumulate(A.begin(), A.end(), 0LL);

    // For each candidate, determine the minimum additional votes needed to guarantee election
    for (int i = 0; i < N; ++i) {
        int rank = 0; // How many candidates currently have more votes than A[i]
        ll needed_votes = 0;

        // Binary search on the number of additional votes required
        ll low = 0, high = K + 1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll curr_total = A[i] + mid;

            // Count how many other candidates have more than curr_total votes
            int count = 0;
            for (int j = 0; j < N && count < M; ++j) {
                if (i != j && A[j] > curr_total) {
                    ++count;
                }
            }

            if (count < M) {
                // Candidate i is elected with mid additional votes
                results[i] = mid;
                high = mid - 1;
            } else {
                // Need more votes
                low = mid + 1;
            }
        }

        // If even after giving all remaining votes it's not enough
        ll max_possible = A[i] + K;
        int count = 0;
        for (int j = 0; j < N; ++j) {
            if (i != j && A[j] > max_possible) {
                ++count;
            }
        }
        if (count >= M) {
            results[i] = -1;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << results[i] << " ";
    }
}