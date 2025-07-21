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
    
    int ans = INT_MAX;
    for (int i = 0; i <= K; ++i) {
        int left = i;
        int right = K - i;
        if (left + right > K || left + right > N) continue;
        ans = min(ans, A[N - 1 - right] - A[left]);
    }
    cout << ans << endl;
    return 0;
}