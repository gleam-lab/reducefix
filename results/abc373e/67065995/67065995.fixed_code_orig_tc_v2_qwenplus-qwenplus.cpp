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
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // For each candidate, we need to compute how many votes they need to guarantee victory.
    vector<ll> result(N, -1);
    vector<pair<ll, int>> sortedA(N);
    for (int i = 0; i < N; ++i) {
        sortedA[i] = {A[i], i};
    }
    sort(sortedA.begin(), sortedA.end());

    vector<ll> prefixSum(N + 1);
    for (int i = 0; i < N; ++i) {
        prefixSum[i + 1] = prefixSum[i] + sortedA[i].first;
    }

    for (int idx = 0; idx < N; ++idx) {
        ll candidateVotes = sortedA[idx].first;
        int originalIndex = sortedA[idx].second;

        // Binary search on the number of additional votes needed
        ll low = 0, high = K + 1;
        while (low < high) {
            ll mid = (low + high) / 2;
            ll total = candidateVotes + mid;

            // We want to ensure that at most M-1 candidates can have more than this total
            // So find how many candidates currently have more than total
            int left = 0, right = N;
            while (left < right) {
                int m = (left + right) / 2;
                if (sortedA[m].first <= total) {
                    left = m + 1;
                } else {
                    right = m;
                }
            }
            int cnt = N - left;

            // If the current candidate is in those candidates (i.e., has more than total), decrease count
            if (sortedA[idx].first > total) {
                cnt--;
            }

            if (cnt >= M) {
                // Not enough, increase X
                low = mid + 1;
            } else {
                // Try lower X
                high = mid;
            }
        }

        ll candidateX = low;
        if (candidateX <= K) {
            result[originalIndex] = candidateX;
        } else {
            result[originalIndex] = -1;
        }
    }

    for (auto x : result) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}