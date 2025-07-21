#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    int min_diff = INT_MAX;
    for (int i = 0; i <= K; ++i) {
        int j = i + (N - K) - 1;
        if (j >= N) break;
        min_diff = min(min_diff, A[j] - A[i]);
    }
    cout << min_diff << endl;
    return 0;
}