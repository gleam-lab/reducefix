#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

#define ll long long

ll n, q;
vector<ll> a;

// Function to perform binary search to find the k-th smallest distance
ll find_kth_closest(ll b, int k) {
    ll left = 0, right = 2 * LLONG_MAX; // Initialize range to handle large distances
    
    while (left < right) {
        ll mid = left + (right - left) / 2;
        ll count = 0;
        
        // Count how many points are within the distance 'mid' from 'b'
        for (auto& x : a) {
            if (abs(x - b) <= mid) {
                count++;
            }
        }
        
        // If there are enough points within 'mid' distance, adjust the right boundary
        if (count >= k) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    return left;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> q;
    a.resize(n);
    
    // Read the coordinates of points A_i
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Sort the points A_i
    sort(a.begin(), a.end());
    
    // Process each query
    for (int i = 0; i < q; ++i) {
        ll b;
        int k;
        cin >> b >> k;
        
        // Find the k-th closest distance from point B_j
        ll result = find_kth_closest(b, k);
        cout << result << "\n";
    }
    
    return 0;
}