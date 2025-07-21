#include<iostream>
#include<algorithm>
using namespace std;

#define int long long

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<pair<int, int>> A(n), B(n);
        for(int i = 0; i < n; ++i) cin >> A[i].first >> A[i].second;
        for(int i = 0; i < n; ++i) cin >> B[i].first >> B[i].second;
        
        // Sort based on the first element of pairs
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        
        long long ans = LLONG_MAX, sum = 0;
        
        // Iterate through the sorted arrays to find the minimum product
        for(int i = 0; i <= n - k; ++i) {
            sum = 0;
            for(int j = 0; j < k; ++j) {
                sum += B[i + j].first;
            }
            ans = min(ans, static_cast<long long>(A[i + k - 1].first) * sum);
        }
        
        cout << ans << endl;
    }
    
    return 0;
}