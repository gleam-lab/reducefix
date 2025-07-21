#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int min_diff = INT_MAX;
    for (int i = 0; i <= N - K; ++i) {
        int diff = A[i + K - 1] - A[i];
        min_diff = min(min_diff, diff);
    }

    cout << min_diff << endl;
    return 0;
}