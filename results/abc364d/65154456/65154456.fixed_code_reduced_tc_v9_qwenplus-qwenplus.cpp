#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

ll a[MAXN];

// Binary search to find the k-th smallest distance from b
ll query(ll b, ll k, int n) {
    // We will use two pointers to maintain a sliding window
    ll res = 0;
    int left = 0;
    int right = 0;
    
    // Sort the array first
    sort(a, a + n);
    
    // Sliding window to find the k-th smallest distance
    for (int i = 0; i < n; ++i) {
        while (right < n && right - left < k)
            right++;
        
        while (right < n && abs(a[right] - b) == abs(a[i] - b))
            right++;
        
        if (right - left == k)
            return abs(a[i] - b);
        
        while (left <= i && abs(a[left] - b) <= abs(a[i] - b))
            left++;
    }
    
    // Fallback: this shouldn't happen in valid inputs
    return abs(a[n-1] - b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    
    sort(a, a + N);  // Sort A once
    
    for (int q = 0; q < Q; ++q) {
        ll b, k;
        cin >> b >> k;
        
        // Binary search on the answer
        ll low = 0;
        ll high = 2e8;  // Maximum possible distance
        
        // We need to count how many distances are <= mid
        auto count_distances = [&](ll mid) {
            ll count = 0;
            for (int i = 0; i < N; ++i) {
                // For each a[i], find how many elements are within [b - mid, b + mid]
                int l = lower_bound(a, a + N, b - mid) - a;
                int r = upper_bound(a, a + N, b + mid) - a;
                count += r - l;
                
                // Early exit if we already exceed k
                if (count >= k) break;
            }
            return count >= k;
        };
        
        // The binary search implementation was incorrect in the original code
        // Let's fix it with proper logic using sorted A
        ll left = 0;
        ll right = 1e14;  // Use a large enough upper bound
        
        while (left < right) {
            ll mid = (left + right) / 2;
            int pos = lower_bound(a, a + N, b - mid) - a;
            int cnt = 0;
            
            while (pos < N && a[pos] <= b + mid) {
                cnt++;
                if (cnt == k) break;
                pos++;
            }
            
            if (cnt >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        cout << left << "\n";
    }
    
    return 0;
}