#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> a(n);
        vector<int> b(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        
        sort(a.begin(), a.end());
        vector<int> indices(n);
        for (int i = 0; i < n; i++) {
            indices[i] = a[i].second;
        }
        
        sort(indices.begin(), indices.end());
        int sumB = 0;
        for (int i = 0; i < k; i++) {
            sumB += b[indices[i]];
        }
        
        long long ans = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            ans = min(ans, (long long) a[i].first * sumB);
        }
        
        cout << ans << endl;
    }
    return 0;
}