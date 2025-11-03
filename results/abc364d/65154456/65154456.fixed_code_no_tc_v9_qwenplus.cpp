#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_N = 1e5 + 5;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    // Sort the A points for binary search and lower_bound/upper_bound operations
    sort(a.begin(), a.end());
    
    for (int j = 0; j < Q; j++) {
        int b, k;
        cin >> b >> k;
        
        // We want to find the smallest distance d such that there are at least k points within distance d from b
        // But we need exact k-th smallest distance, so we can use binary search on answer
        
        int left = 0, right = 2e8;
        int ans = right;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Count how many points in A are within distance 'mid' from point b
            // That means a_i is in [b - mid, b + mid]
            int left_bound = b - mid;
            int right_bound = b + mid;
            
            auto it1 = lower_bound(a.begin(), a.end(), left_bound);
            auto it2 = upper_bound(a.begin(), a.end(), right_bound);
            int count = it2 - it1;
            
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