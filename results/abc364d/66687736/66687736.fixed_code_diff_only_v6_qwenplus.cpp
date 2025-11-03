#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define vi vector<int>
#define vll vector<ll>

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    
    vi a(N);
    rep(i, N) cin >> a[i];
    
    // Sort the A points for binary search later
    sort(a.begin(), a.end());
    
    rep(qi, Q) {
        int b, k;
        cin >> b >> k;
        k--; // Convert to 0-indexed
        
        // We'll find the smallest distance d such that there are at least k+1 points within distance d from b
        // But instead, we can collect all distances and use binary search on answer
        
        // However, better approach: find the k-th smallest distance by checking candidates
        // The candidate positions are around b, so we can find the leftmost and rightmost possible A points
        
        // Find the position where b would be inserted
        auto it = lower_bound(a.begin(), a.end(), b);
        
        // We'll consider points around b - merge left and right parts
        vll distances;
        
        // Collect distances from nearby points
        // Points to the left of b (in reverse order, closest first)
        vector<int> left, right;
        if (it != a.begin()) {
            for (auto iter = it; iter != a.begin(); ) {
                --iter;
                left.push_back(*iter);
            }
        }
        // Points to the right of or at b
        for (auto iter = it; iter != a.end(); ++iter) {
            right.push_back(*iter);
        }
        
        // Merge the two lists by distance to b
        int i = 0, j = 0;
        while ((i < left.size() || j < right.size()) && (int)distances.size() <= k) {
            ll dist_left = (i < left.size()) ? (ll)b - left[i] : LLONG_MAX;
            ll dist_right = (j < right.size()) ? (ll)right[j] - b : LLONG_MAX;
            
            if (dist_left <= dist_right) {
                distances.push_back(dist_left);
                i++;
            } else {
                distances.push_back(dist_right);
                j++;
            }
        }
        
        // If we need more elements, continue merging
        while ((i < left.size() || j < right.size()) && (int)distances.size() <= k) {
            ll dist_left = (i < left.size()) ? (ll)b - left[i] : LLONG_MAX;
            ll dist_right = (j < right.size()) ? (ll)right[j] - b : LLONG_MAX;
            
            if (dist_left <= dist_right) {
                distances.push_back(dist_left);
                i++;
            } else {
                distances.push_back(dist_right);
                j++;
            }
        }
        
        // Sort just in case (though they should be in order)
        // But our merge ensures increasing order
        cout << distances[k] << '\n';
    }
}