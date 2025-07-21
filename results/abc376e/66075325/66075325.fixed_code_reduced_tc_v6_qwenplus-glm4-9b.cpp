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
    sort(AB.begin(), AB.end());

    long long max_A = 0, sum_B = 0;
    for (int i = N - 1; i >= N - K; --i) {
        sum_B += AB[i].second;
        max_A = max(max_A, AB[i].first);
    }

    return max_A * sum_B;
}

int main() {
    int T, N, K;
    cin >> T;
    while (T--) {
        cin >> N >> K;
        int *A = new int[N];
        int *B = new int[N];
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < N; ++i) {
            cin >> B[i];
        }
        cout << solve(A, B, N, K) << endl;
        delete[] A;
        delete[] B;
    }
    return 0;
}