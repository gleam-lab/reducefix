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
    int result = INT_MAX;
    for (int i = 0; i <= K; ++i) {
        result = min(result, A[N - 1 - (K - i)] - A[i]);
    }
    cout << result << endl;
    return 0;
}