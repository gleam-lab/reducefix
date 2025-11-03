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
    rep(i, N) {
        cin >> a[i];
    }
    
    // Sort the A points for binary search
    sort(a.begin(), a.end());
    
    rep(qi, Q) {
        int b, k;
        cin >> b >> k;
        k--; // Convert to 0-indexed
        
        // We'll find the k-th smallest distance from B to any A point
        // Instead of computing all distances, we can binary search on the answer
        // But simpler: collect distances and use nth_element or partial_sort?
        // However, N and Q up to 10^5 -> O(NQ) worst-case 10^10, too slow
        
        // Better approach: for each query, we want the k-th smallest |a_i - b|
        // We can do: find position where b would be inserted, then expand left/right with two pointers
        
        // Find the lower bound of b in sorted a
        auto it = lower_bound(a.begin(), a.end(), b);
        
        // We'll consider elements from both sides
        vector<ll> distances;
        
        // Left side: from closest to b going left
        vector<int> left, right;
        if (it != a.begin()) {
            for (auto iter = it; iter != a.begin(); ) {
                --iter;
                left.push_back(*iter);
            }
        }
        // Right side: from it onwards
        for (auto iter = it; iter != a.end(); ++iter) {
            right.push_back(*iter);
        }
        
        // Merge the two sequences by distance from b
        int i = 0, j = 0;
        while (i < left.size() || j < right.size()) {
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
        
        // Get k-th smallest distance (k is now 0-indexed)
        cout << distances[k] << '\n';
    }
}