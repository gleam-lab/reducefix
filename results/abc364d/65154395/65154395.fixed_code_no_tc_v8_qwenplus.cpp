#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;

int a[MAXN];

void solve() {
    int N, Q;
    cin >> N >> Q;
    
    // Read the A points and sort them for binary search
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a, a + N);
    
    // Process each query
    for (int j = 0; j < Q; j++) {
        int b, k;
        cin >> b >> k;
        
        // Binary search on the distance
        int left = 0, right = 2e8;
        int ans = right;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int count = 0;
            
            // Count how many A_i are within distance <= mid from b
            // This is equivalent to counting points in [b - mid, b + mid]
            int low_bound = b - mid;
            int high_bound = b + mid;
            
            auto it1 = lower_bound(a, a + N, low_bound);
            auto it2 = upper_bound(a, a + N, high_bound);
            count = it2 - it1;
            
            if (count >= k) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}