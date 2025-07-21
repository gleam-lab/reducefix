#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while(t--) {
        int n, k;
        cin >> n >> k;
        
        vector<ll> a(n), b(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < n; ++i) cin >> b[i];
        
        // Sort A in descending order and B in ascending order
        sort(a.begin(), a.end(), greater<ll>());
        sort(b.begin(), b.end());
        
        // Initialize two pointers
        int i = 0, j = n - 1;
        ll min_val = LLONG_MAX;
        
        while(i < k && j >= 0) {
            ll curr_sum = 0;
            for(int x = 0; x <= i; ++x) curr_sum += b[x];
            for(int y = 0; y < k - i - 1; ++y) curr_sum -= b[j - y];
            min_val = min(min_val, a[i] * curr_sum);
            if(a[i] > b[j]) --j;
            else ++i;
        }
        
        cout << min_val << '\n';
    }
    
    return 0;
}