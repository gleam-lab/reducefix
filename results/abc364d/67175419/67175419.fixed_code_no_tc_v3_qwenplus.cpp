#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, q;
long long a[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a, a + n);
    
    while (q--) {
        long long b;
        int k;
        cin >> b >> k;
        
        // Find the k-th smallest distance from B to any A_i
        // We can do this by binary searching on the answer (distance)
        long long left = 0, right = 2e8;
        long long ans = right;
        
        while (left <= right) {
            long long mid = (left + right) / 2;
            
            // Count how many points A_i are within distance 'mid' from point b
            long long low = b - mid;
            long long high = b + mid;
            
            // Find the first index >= low
            int l_idx = lower_bound(a, a + n, low) - a;
            // Find the first index > high
            int r_idx = upper_bound(a, a + n, high) - a;
            
            int count = r_idx - l_idx;
            
            if (count >= k) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}