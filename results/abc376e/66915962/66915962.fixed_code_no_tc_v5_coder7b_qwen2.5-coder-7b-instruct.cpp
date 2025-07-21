#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
using P = pair<int, int>;
constexpr int INF = 1001001001;
constexpr ll LINF = 1001001001001001001ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        
        // Sort A and B separately
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        // Initialize variables
        ll maxA = a[n - 1];
        ll sumB = accumulate(b.begin(), b.begin() + k, 0LL);
        ll ans = maxA * sumB;
        
        // Sliding window approach
        multiset<ll> s(begin(b), begin(b) + k);
        
        for (int i = k; i < n; ++i) {
            // Remove the smallest element from the current window
            sumB -= *s.begin();
            s.erase(s.begin());
            
            // Add the next element to the window
            sumB += b[i];
            s.insert(b[i]);
            
            // Update the maximum A_i in the remaining part of the array
            maxA = a[n - i - 1];
            
            // Calculate the new product
            ans = min(ans, maxA * sumB);
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}