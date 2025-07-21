#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for (ll &a : A) {
        cin >> a;
    }
    ll total = accumulate(A.begin(), A.end(), 0LL);
    ll remaining = K - total;

    vector<pair<ll, int>> sortedA(N);
    for (int i = 0; i < N; ++i) {
        sortedA[i] = {A[i], i};
    }
    sort(sortedA.begin(), sortedA.end());

    vector<int> indexMap(N); // Maps original index to position in sorted list
    for (int i = 0; i < N; ++i) {
        indexMap[sortedA[i].second] = i;
    }

    vector<ll> prefix(N + 1);
    for (int i = 1; i <= N; ++i) {
        prefix[i] = prefix[i - 1] + sortedA[i - 1].first;
    }

    vector<ll> result(N);

    for (int i = 0; i < N; ++i) {
        int idx = indexMap[i];
        ll current = A[i];

        // Binary search on the number of additional votes needed
        ll low = 0;
        ll high = remaining;
        ll answer = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_score = current + mid;

            // Find how many candidates can be strictly greater than new_score
            // Start from the first candidate after 'idx' in sorted array
            int left = idx + 1;
            int right = N;
            while (left < right) {
                int m = (left + right) / 2;
                if (sortedA[m].first > new_score)
                    left = m + 1;
                else
                    right = m;
            }
            int num_greater = N - left;

            // If we already have M or more candidates strictly greater than us, this mid is invalid
            if (num_greater >= M) {
                low = mid + 1;
                continue;
            }

            // We need to make sure that even among the remaining (M - num_greater - 1) candidates,
            // we can surpass them by using the remaining votes.
            int max_check = min(idx, M - num_greater - 1);
            if (max_check < 0) {
                answer = mid;
                high = mid - 1;
                continue;
            }

            // Calculate how much we need to increase our score to beat these top max_check candidates
            ll needed = max_check * new_score - (prefix[left] - prefix[left - max_check]);

            if (needed <= remaining - mid) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        result[i] = (answer == -1 || answer > remaining) ? -1 : answer;
    }

    for (ll val : result) {
        cout << max(0LL, val) << " ";
    }

    return 0;
}