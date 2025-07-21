#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> a(n), b(n);
        
        for (int i = 0; i < n; i++)
            cin >> a[i];
        
        for (int i = 0; i < n; i++)
            cin >> b[i];
        
        // Sort arrays A and B
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        int ans = LLONG_MAX;
        
        // Iterate through the pairs of the first K elements of A and last K elements of B
        for (int i = 0; i < k; i++) {
            ans = min(ans, a[i] * b[n - k + i]);
        }
        
        cout << ans << endl;
    }
    
    return 0;
}