#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) cin >> A[i];
        for (int i = 0; i < N; i++) cin >> B[i];

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        vector<long long> prefixSum(N + 1, 0);
        for (int i = 0; i < N; i++) {
            prefixSum[i + 1] = prefixSum[i] + B[i];
        }

        long long min_value = LLONG_MAX;

        for (int i = 0; i <= N - K; i++) {
            long long maxAi = A[i + K - 1];
            long long sumBi = prefixSum[i + K] - prefixSum[i];
            min_value = min(min_value, maxAi * sumBi);
        }

        cout << min_value << endl;
    }
    return 0;
}