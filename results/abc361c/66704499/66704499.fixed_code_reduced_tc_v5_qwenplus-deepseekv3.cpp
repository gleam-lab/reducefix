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
    int min_diff = INT_MAX;
    for (int i = 0; i <= K; ++i) {
        int j = N - K + i - 1;
        if (j < N && j >= 0) {
            int current_diff = A[j] - A[i];
            if (current_diff < min_diff) {
                min_diff = current_diff;
            }
        }
    }
    cout << min_diff << endl;
    return 0;
}