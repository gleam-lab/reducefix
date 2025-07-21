#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long

int main() {
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<pair<int, int>> A(n), B(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> A[i].first;
            A[i].second = i;
        }
        for (int i = 0; i < n; ++i) {
            cin >> B[i].first;
            B[i].second = i;
        }
        
        sort(A.begin(), A.end());
        sort(B.begin(), B.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second; // Sort by index
        });
        
        long long ans = LLONG_MAX;
        long long sumB = 0;
        
        for (int i = 0; i < n; ++i) {
            if (i >= k - 1) {
                sumB += B[i].first;
            }
            if (i >= k) {
                sumB -= B[i - k].first;
            }
            
            if (i >= k - 1) { // Start from the k-th element since we need k elements in the subset
                ans = min(ans, A[i].first * sumB);
            }
        }
        
        cout << ans << endl;
    }
    return 0;
}