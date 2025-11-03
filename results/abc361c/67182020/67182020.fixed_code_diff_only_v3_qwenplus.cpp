#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    // We are removing exactly K elements, so B has length N-K
    // To minimize (max - min) of the remaining sequence,
    // we can only keep a contiguous segment of length N-K in the sorted array
    // because any non-contiguous selection would have larger range

    int min_diff = INT_MAX;
    for (int i = 0; i + (N - K) <= N; i++) {
        int j = i + (N - K) - 1;  // ending index of the segment
        min_diff = min(min_diff, A[j] - A[i]);
    }

    cout << min_diff << endl;

    return 0;
}