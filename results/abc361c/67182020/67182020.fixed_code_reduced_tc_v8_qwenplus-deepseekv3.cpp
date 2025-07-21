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
    for (int i = 0; i <= K; ++i) {
        int left = i;
        int right = N - 1 - (K - i);
        if (left <= right) {
            int current_diff = A[right] - A[left];
            if (current_diff < min_diff) {
                min_diff = current_diff;
            }
        }
    }
    cout << min_diff << endl;
    return 0;
}