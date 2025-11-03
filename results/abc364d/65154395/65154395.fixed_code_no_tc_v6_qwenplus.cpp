#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;

int a[MAXN];

void solve() {
    int N, Q;
    cin >> N >> Q;
    
    // Read the A points
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    // Sort the A array to enable binary search and distance computation
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
            
            // Count how many A_i are within distance 'mid' from point b
            int left_bound = b - mid;
            int right_bound = b + mid;
            
            // Find the first index where a[i] >= left_bound
            int* low = lower_bound(a, a + N, left_bound);
            // Find the first index where a[i] > right_bound
            int* high = upper_bound(a, a + N, right_bound);
            
            int count = high - low;
            
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