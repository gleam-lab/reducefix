#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, q;
long long a[N];

// Check if there are at least k points within distance 'd' from point x
bool check(long long d, long long x, int k) {
    // Find the leftmost index where a[i] >= (x - d)
    int left = lower_bound(a, a + n, x - d) - a;
    // Find the rightmost index where a[i] <= (x + d)
    int right = upper_bound(a, a + n, x + d) - a;
    return (right - left) >= k;
}

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
        
        // Binary search on the answer (distance)
        long long left = 0, right = 2e8;
        long long ans = right;
        
        while (left <= right) {
            long long mid = (left + right) / 2;
            if (check(mid, b, k)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}