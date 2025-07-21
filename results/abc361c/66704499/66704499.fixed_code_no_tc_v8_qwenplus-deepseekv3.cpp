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
        int left = i;
        int right = N - 1 - (K - i);
        if (left <= right) {
            min_diff = min(min_diff, A[right] - A[left]);
        }
    }
    cout << min_diff << endl;
    return 0;
}