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

    long long result = LLONG_MAX;
    for (int left_remove = 0; left_remove <= K; ++left_remove) {
        int right_remove = K - left_remove;
        if (left_remove + right_remove > N) continue;
        long long current_diff = A[N - 1 - right_remove] - A[left_remove];
        result = min(result, current_diff);
    }

    cout << result << endl;
    return 0;
}