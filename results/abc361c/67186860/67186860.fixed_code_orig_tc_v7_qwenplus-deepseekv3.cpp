#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    
    int ans = INT_MAX;
    for (int i = 0; i <= k; i++) {
        int j = k - i;
        ans = min(ans, A[n - 1 - j] - A[i]);
    }
    
    cout << ans << endl;
    return 0;
}