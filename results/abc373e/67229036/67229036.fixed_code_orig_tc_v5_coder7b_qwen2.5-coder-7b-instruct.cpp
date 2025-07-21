#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    vector<long long> A(N), B(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        K -= A[i];
    }

    sort(A.begin(), A.end());

    long long sum = accumulate(A.begin(), A.end(), 0LL);
    vector<long long> C(N);

    for (int i = 0; i < N; ++i) {
        // Calculate the minimum additional votes needed for candidate i to win
        if (M <= i) {
            C[i] = 0;
        } else {
            long long required_votes = (K + M - 1) / M * (M - 1) - sum + A[i];
            C[i] = max(0LL, required_votes - A[i]);
        }
    }

    for (int i = 0; i < N; ++i) {
        if (C[i] == LLONG_MAX)
            C[i] = -1;
        cout << C[i] << " ";
    }

    return 0;
}