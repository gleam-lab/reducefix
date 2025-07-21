#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define int long long
const int N = 2e5 + 9;

int solve(int N, int K, const vector<int>& A, const vector<int>& B) {
    if (K == 1) {
        return 0; // If K is 1, the expression simplifies to max(A_i) * 0, which is 0.
    }

    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end());

    map<int, int> prefixSum;
    vector<int> prefixSumValues;
    int currentSum = 0;
    for (int i = 0; i < N; ++i) {
        currentSum += B[i];
        prefixSum[currentSum] = i;
    }

    int minResult = INT_MAX;
    for (int i = 0; i < N; ++i) {
        int maxAi = A[i];
        int sumB = 0;
        int count = 0;

        for (int j = i + 1; j < N && count < K - 1; ++j) {
            sumB += B[j];
            count++;
        }

        if (count == K - 1) {
            sumB += B[i + 1];
            int index = prefixSum[sumB];
            if (index != 0) {
                minResult = min(minResult, maxAi * sumB);
            }
        }
    }

    return minResult;
}

int32_t main() {
    int T;
    cin >> T;
    vector<int> A, B;

    while (T--) {
        int N, K;
        cin >> N >> K;
        A.resize(N);
        B.resize(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < N; ++i) {
            cin >> B[i];
        }

        cout << solve(N, K, A, B) << endl;
    }

    return 0;
}