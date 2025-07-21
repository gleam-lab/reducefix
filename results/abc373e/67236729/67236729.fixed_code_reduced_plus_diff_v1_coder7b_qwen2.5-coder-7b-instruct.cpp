#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        K -= A[i];
    }

    sort(A.begin(), A.end());

    vector<long long> suffix_sum(N + 1);
    for (int i = N - 1; i >= 0; --i) {
        suffix_sum[i] = suffix_sum[i + 1] + A[i];
    }

    vector<long long> results(N, 0);
    for (int i = 0; i < N; ++i) {
        long long need = 0;
        int up = N - i + M - 1;
        if (up >= N) continue;

        long long S = suffix_sum[up + 1] - suffix_sum[i + 1];
        if (A[i] <= A[up] && A[i] <= A[up - 1]) {
            S -= A[i];
            S += A[up - 1];
        }

        need = (A[i] + 1) * (M - up) - S;
        if (need <= K) {
            results[i] = need;
        }
    }

    for (long long res : results) {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}