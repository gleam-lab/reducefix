#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define int long long
const int N = 1e5 + 9;

int n, q;
int a[N];

// Check if there are at least k points within distance 'dist' from point 'pos'
bool check(int pos, int dist, int k) {
    int left_bound = pos - dist;
    int right_bound = pos + dist;
    
    // Find the first index >= left_bound
    int ln = lower_bound(a + 1, a + n + 1, left_bound) - a;
    // Find the first index > right_bound
    int rn = upper_bound(a + 1, a + n + 1, right_bound) - a;
    
    // Number of points in [left_bound, right_bound]
    int count = rn - ln;
    
    return count >= k;
}

int findans(int pos, int k) {
    int l = 0, r = 2e8;  // Maximum possible distance is 2*10^8
    
    while (l < r) {
        int mid = (l + r) / 2;
        
        if (check(pos, mid, k)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    
    return l;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    sort(a + 1, a + n + 1);
    
    while (q--) {
        int x, k;
        cin >> x >> k;
        cout << findans(x, k) << '\n';
    }
    
    return 0;
}