#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;

int n, q;
int a[200005];

int find_kth_closest(int b, int k) {
    // Binary search on the answer (distance)
    int left = 0, right = 2e8;
    while (left < right) {
        int mid = (left + right) / 2;
        
        // Find how many elements are within distance mid of b
        int l = lower_bound(a, a + n, b - mid) - a;
        int r = upper_bound(a, a + n, b + mid) - a;
        
        if (r - l >= k) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    return left;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    
    while (q--) {
        int b, k;
        cin >> b >> k;
        cout << find_kth_closest(b, k) << '\n';
    }
    
    return 0;
}