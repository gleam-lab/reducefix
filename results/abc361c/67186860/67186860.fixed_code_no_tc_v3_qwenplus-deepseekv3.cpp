#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    
    int ans = INT_MAX;
    for (int i = 0; i <= k; ++i) {
        int left_removed = i;
        int right_removed = k - i;
        if (left_removed + right_removed > n) continue;
        int current_min = A[left_removed];
        int current_max = A[n - 1 - right_removed];
        ans = min(ans, current_max - current_min);
    }
    
    cout << ans << endl;
    return 0;
}