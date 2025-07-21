#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ll N, M, K;
    cin >> N >> M >> K;

    vector<ll> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    vector<pair<ll, int>> B(N + 1);
    for (int i = 1; i <= N; ++i) {
        B[i] = {A[i], i};
    }

    sort(B.begin(), B.end());

    vector<ll> prefixSum(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        prefixSum[i] = prefixSum[i - 1] + B[i].first;
    }

    K -= prefixSum[N];
    vector<ll> result(N + 1, -1);

    for (int i = 1; i <= N; ++i) {
        ll votes_needed = B[i].first + K;
        ll upper_bound_idx = upper_bound(B.begin() + i, B.end(), {votes_needed, 0}) - B.begin();
        ll votes_above = prefixSum[N] - prefixSum[upper_bound_idx - 1];
        
        if (votes_above < M) {
            ll min_votes_needed = votes_above + B[i].first + 1 - M;
            if (min_votes_needed > 0 && min_votes_needed <= K) {
                result[B[i].second] = min_votes_needed;
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        cout << result[i] << ' ';
    }

    return 0;
}