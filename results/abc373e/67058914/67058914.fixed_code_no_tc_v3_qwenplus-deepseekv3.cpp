#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
ll K;

int main() {
    cin >> N >> M >> K;

    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<pair<ll, int>> sorted_A(N);
    for (int i = 0; i < N; ++i) {
        sorted_A[i] = {A[i], i};
    }
    sort(sorted_A.begin(), sorted_A.end());

    vector<ll> prefix_sum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + sorted_A[i].first;
    }

    ll total_used = prefix_sum[N];
    ll remaining = K - total_used;

    vector<ll> answer(N, -1);

    for (int i = 0; i < N; ++i) {
        ll current_A = sorted_A[i].first;
        int original_index = sorted_A[i].second;

        // Binary search to find the minimal X such that current_A + X ensures election
        ll low = 0, high = remaining + current_A;
        ll best_X = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_Ai = current_A + mid;

            // Find how many candidates have > new_Ai votes
            auto it = upper_bound(sorted_A.begin(), sorted_A.end(), make_pair(new_Ai, N));
            int cnt = sorted_A.end() - it;

            // If adding mid votes makes cnt < M, then it's a candidate solution
            if (cnt < M) {
                best_X = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (best_X != -1) {
            // Now, check if the remaining votes can be distributed to make this possible
            // The worst case is when as many candidates as possible get votes to surpass new_Ai
            // So, we need to ensure that the sum of votes given to the top (M - 1) candidates is within the remaining votes after allocating best_X to candidate i
            ll new_Ai = current_A + best_X;
            auto it = upper_bound(sorted_A.begin(), sorted_A.end(), make_pair(new_Ai, N));
            int cnt = sorted_A.end() - it;

            // The candidates from it to end can be given (new_Ai + 1) votes to surpass new_Ai
            // We need to ensure that the sum of (new_Ai + 1 - their current votes) for top (M - 1 - cnt) candidates is <= remaining - best_X
            ll needed = 0;
            int potential = M - 1 - cnt;
            if (potential > 0) {
                int start_idx = N - potential;
                if (start_idx >= 0) {
                    for (int j = start_idx; j < N; ++j) {
                        if (sorted_A[j].first < new_Ai + 1) {
                            needed += (new_Ai + 1 - sorted_A[j].first);
                        }
                    }
                } else {
                    needed = LLONG_MAX; // Impossible case
                }
            }

            if (needed <= remaining - best_X) {
                answer[original_index] = best_X;
            } else {
                answer[original_index] = -1;
            }
        } else {
            answer[original_index] = -1;
        }
    }

    for (int i = 0; i < N; ++i) {
        if (answer[i] == -1) {
            // Check if the candidate is already winning
            ll current_A = A[i];
            auto it = upper_bound(sorted_A.begin(), sorted_A.end(), make_pair(current_A, N));
            int cnt = sorted_A.end() - it;
            if (cnt < M) {
                answer[i] = 0;
            }
        }
        cout << answer[i] << ' ';
    }
    cout << endl;

    return 0;
}