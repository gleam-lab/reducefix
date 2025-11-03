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
    
    // We need to remove exactly K elements, so we keep N-K elements.
    // The optimal strategy is to remove some elements from the left and some from the right.
    // Try all possible ways: remove i elements from the left and (K-i) from the right.
    int keep = N - K;
    int ans = A[keep - 1] - A[0]; // Initial case: remove K from right
    
    for (int i = 0; i <= K; i++) {
        // Remove i elements from the left, K-i from the right
        int left_removed = i;
        int right_removed = K - i;
        
        if (left_removed + right_removed <= N && N - right_removed >= left_removed) {
            int current_min = A[left_removed];
            int current_max = A[N - 1 - right_removed];
            ans = min(ans, current_max - current_min);
        }
    }
    
    cout << ans << endl;
    
    return 0;
}