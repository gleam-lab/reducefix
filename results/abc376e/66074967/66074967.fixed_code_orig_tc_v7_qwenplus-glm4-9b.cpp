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

        sort(A.begin(), A.end()); // Sort A ascending
        sort(B.begin(), B.end(), greater<int>()); // Sort B descending

        long long ans = LLONG_MAX;
        for (int i = 0; i < K; i++) {
            ans = min(ans, (long long)A[i] * B[i]);
        }

        cout << ans << endl;
    }
    return 0;
}