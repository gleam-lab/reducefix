#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    int result = INT_MAX;
    for (int i = 0; i <= K; ++i) {
        int j = N - 1 - (K - i);
        if (j >= i) {
            result = min(result, A[j] - A[i]);
        }
    }
    cout << result << endl;
    return 0;
}