#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int ans = INT_MAX;
    for (int i = 0; i <= K; ++i) {
        int j = N - 1 - (K - i);
        if (i <= j) {
            ans = min(ans, A[j] - A[i]);
        }
    }

    cout << ans << endl;
    return 0;
}