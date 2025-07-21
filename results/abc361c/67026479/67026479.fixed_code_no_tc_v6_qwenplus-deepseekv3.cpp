#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    int m = N - K;
    if (m <= 1) {
        cout << 0 << endl;
        return 0;
    }
    
    sort(A.begin(), A.end());
    int min_diff = INT_MAX;
    for (int i = 0; i <= K; ++i) {
        min_diff = min(min_diff, A[i + m - 1] - A[i]);
    }
    cout << min_diff << endl;
    return 0;
}