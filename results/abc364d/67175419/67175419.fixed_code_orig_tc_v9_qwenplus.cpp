#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
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
        
        // Binary search on the distance
        long long left = 0, right = 2e8;
        long long ans = right;
        
        while (left <= right) {
            long long mid = (left + right) / 2;
            // Count how many points are within distance 'mid' from b
            long long lower_bound = b - mid;
            long long upper_bound = b + mid;
            
            int left_idx = lower_bound(a, a + n, lower_bound) - a;
            int right_idx = upper_bound(a, a + n, upper_bound) - a;
            
            int count = right_idx - left_idx;
            
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