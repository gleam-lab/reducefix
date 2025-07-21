#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long
const int N = 2e5 + 9;

int solve(int *A, int *B, int N, int K) {
    vector<pair<int, int>> AB(N);
    for (int i = 0; i < N; ++i) {
        AB[i] = {A[i], B[i]};
    }
    sort(AB.begin(), AB.end()); // Sort by A[i] values

    long long min_cost = LLONG_MAX;
    long long sum_B = 0;
    for (int i = 0; i < N; ++i) {
        sum_B += AB[i].second;
        if (i >= K - 1) { // Start checking from the (K-1)-th element
            int max_A = AB[i].first;
            int sum_B_k = sum_B;
            for (int j = 0; j < K; ++j) {
                sum_B_k -= AB[i - K + 1 + j].second;
                min_cost = min(min_cost, max_A * sum_B_k);
            }
        }
    }
    return min_cost;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        int A[N], B[N];
        for (int i = 0; i < N; ++i) cin >> A[i];
        for (int i = 0; i < N; ++i) cin >> B[i];
        cout << solve(A, B, N, K) << endl;
    }
    return 0;
}