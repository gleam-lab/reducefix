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
        int current = A[N - 1 - (K - i)] - A[i];
        if (current < result) {
            result = current;
        }
    }
    cout << result << endl;
    return 0;
}