#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // We will use a sliding window approach to keep N-K elements
    int windowSize = N - K;
    sort(A.begin(), A.end());

    int minDiff = numeric_limits<int>::max();
    for (int i = 0; i + windowSize <= N; ++i) {
        minDiff = min(minDiff, A[i + windowSize - 1] - A[i]);
    }

    cout << minDiff << endl;
    return 0;
}