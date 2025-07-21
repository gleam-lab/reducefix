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

    int minDiff = INT_MAX;
    for (int i = 0; i <= N - K; ++i) {
        int currentDiff = A[i + K - 1] - A[i];
        if (currentDiff < minDiff) {
            minDiff = currentDiff;
        }
    }

    cout << minDiff << endl;

    return 0;
}