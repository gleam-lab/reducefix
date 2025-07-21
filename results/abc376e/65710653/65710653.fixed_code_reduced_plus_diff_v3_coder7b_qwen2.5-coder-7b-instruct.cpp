#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        
        vector<int> A(N), B(N);
        for (int i = 0; i < N; ++i) cin >> A[i];
        for (int i = 0; i < N; ++i) cin >> B[i];

        // Sort A and B in descending order
        sort(A.begin(), A.end(), greater<int>());
        sort(B.begin(), B.end(), greater<int>());

        // Calculate the result
        long long max_A = A[K - 1];
        long long sum_B = 0;
        for (int i = 0; i < K; ++i) sum_B += B[i];

        long long result = max_A * sum_B;
        cout << result << '\n';
    }

    return 0;
}