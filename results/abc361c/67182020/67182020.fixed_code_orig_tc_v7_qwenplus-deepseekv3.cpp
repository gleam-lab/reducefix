#include <bits/stdc++.h>
using namespace std;

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    int result = INT_MAX;
    for (int i = 0; i <= K; ++i) {
        int current_diff = A[N - 1 - (K - i)] - A[i];
        if (current_diff < result) {
            result = current_diff;
        }
    }
    cout << result << endl;
    return 0;
}