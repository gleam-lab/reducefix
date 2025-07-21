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
        A[i].second = i;
    }

    // Sort the candidates by current votes
    sort(A.begin(), A.end());

    // Prefix sum of sorted votes
    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i)
        prefix[i + 1] = prefix[i] + A[i].first;

    ll total_remaining = K - prefix[N];

    vector<ll> result(N);

    // For each candidate, binary search on minimum additional votes needed
    for (int i = 0; i < N; ++i) {
        ll low = 0, high = total_remaining;
        ll answer = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll current_vote = A[i].first + mid;

            // Binary search to find how many candidates have votes > current_vote
            int left = 0, right = N - 1;
            int cnt = 0;
            while (left <= right) {
                int m = (left + right) / 2;
                if (A[m].first > current_vote)
                    left = m + 1;
                else
                    right = m - 1;
            }
            cnt = N - left;

            if (cnt < M) {
                // Not enough candidates ahead -> this mid is valid
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        // If no valid X found, set to -1
        result[A[i].second] = (answer == -1 ? -1 : answer);
    }

    // Print result
    for (int i = 0; i < N; ++i) {
        if (i > 0) cout << " ";
        cout << (result[i] == -1 ? -1LL : max(0LL, result[i]));
    }
    cout << "\n";

    return 0;
}