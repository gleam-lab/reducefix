#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<pair<ll, int>> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i].first;
    }

    // Store original indices to restore order at the end
    for (int i = 0; i < N; ++i) {
        A[i].second = i;
    }

    // Result array
    vector<ll> res(N);

    // Total current sum of votes
    ll total_current = 0;
    for (auto &p : A) {
        total_current += p.first;
    }
    ll remaining_votes = K - total_current;

    // Sort the candidates by vote count
    sort(A.begin(), A.end());

    // Prefix sum array
    vector<ll> prefix(N + 1);
    for (int i = 1; i <= N; ++i) {
        prefix[i] = prefix[i - 1] + A[i - 1].first;
    }

    // For each candidate, perform binary search to find minimum X
    for (int i = 0; i < N; ++i) {
        int idx = i; // position in sorted list
        ll cur_votes = A[i].first;

        auto cmp = [&](ll add) {
            ll total = cur_votes + add;
            // Find how many candidates can possibly get more than total
            int l = 0, r = N - 1, pos = N;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (A[mid].first > total) {
                    pos = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            // Count how many candidates are strictly greater than total
            int count_greater = N - pos;

            // If there are already >= M such candidates, cannot win
            if (count_greater >= M) return false;

            // Now try to assign enough votes to those who tie or are below
            int available = N - count_greater - 1;
            if (available < M - count_greater) {
                // Not enough candidates to be tied/under to fill up M
                return false;
            }

            // Assign just enough to make sure only (M - 1 - count_greater) can beat us
            // So we limit the number of ones who can beat us to M - 1
            int max_beat = M - 1;
            int min_start = N - max_beat;
            if (min_start < 0) return false;

            ll need = 0;
            for (int j = min_start; j < N; ++j) {
                if (j == i) continue;
                need += max(0LL, A[j].first - total + 1);
            }

            return need <= remaining_votes;
        };

        // Binary search over X
        ll low = 0, high = remaining_votes;
        ll answer = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            if (cmp(mid)) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        res[A[i].second] = (answer == -1 ? -1 : answer);
    }

    for (int i = 0; i < N; ++i) {
        cout << res[i] << " ";
    }

    return 0;
}