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

    int ans = INT_MAX;
    for (int i = 0; i <= K; ++i) {
        int left_min = A[i];
        int right_max = A[N - K + i];
        ans = min(ans, right_max - left_min);
    }

    cout << ans << endl;
    return 0;
}