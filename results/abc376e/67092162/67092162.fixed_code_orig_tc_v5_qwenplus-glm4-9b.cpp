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

        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }

        sort(A.begin(), A.end(), greater<int>());
        sort(B.begin(), B.end());

        int maxA = A[0];
        int sumB = 0;
        for (int i = 0; i < K; i++) {
            sumB += B[i];
        }

        int ans = maxA * sumB;

        for (int i = K; i < N; i++) {
            sumB += B[i];
            if (maxA > A[i]) {
                continue;
            }
            sumB -= B[K - 1];
            maxA = A[i];
            ans = min(ans, maxA * sumB);
        }

        cout << ans << endl;
    }

    return 0;
}