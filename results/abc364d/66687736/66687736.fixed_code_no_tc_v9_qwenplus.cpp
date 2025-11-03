#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define vi vector<int>

int main(){
    int n, q;
    cin >> n >> q;
    vi a(n);
    rep(i, n) {
        cin >> a[i];
    }
    
    // Sort the A points for binary search and distance computation
    sort(a.begin(), a.end());
    
    rep(j, q) {
        int b, k;
        cin >> b >> k;
        k--; // Convert to 0-indexed
        
        // We'll find the smallest radius r such that there are at least k+1 points within distance r
        // But instead of binary search on answer, we can use two pointers or binary search on positions
        
        // Binary search on the distance
        int left = -1;
        int right = 200000000; // max possible distance is 2e8
        
        while (right - left > 1) {
            int mid = (left + right) / 2;
            
            // Count how many points in A are within distance `mid` from point B
            int low_bound = b - mid;
            int high_bound = b + mid;
            
            auto it1 = lower_bound(a.begin(), a.end(), low_bound);
            auto it2 = upper_bound(a.begin(), a.end(), high_bound);
            int count = it2 - it1;
            
            if (count <= k) {
                left = mid;
            } else {
                right = mid;
            }
        }
        
        // Now right is the smallest distance such that fewer than or equal to k points are strictly closer
        // Actually, we want the k-th smallest distance
        
        // Let's collect all distances and get the k-th one? That would be O(N) per query -> too slow
        
        // Alternative: we know the answer is either right-1 or right?
        // Actually, our binary search found the smallest distance d such that the number of points 
        // within distance < d is <= k, but we need exactly the k-th smallest distance.
        
        // Let's change approach: we can't easily binary search on the count like this because
        // multiple points can have same distance. Instead, let's do:
        // Binary search on d such that number of points with distance <= d is >= k+1
        // Then smallest such d is our answer
        
        left = -1;
        right = 200000000;
        
        while (right - left > 1) {
            int mid = (left + right) / 2;
            
            int low_bound = b - mid;
            int high_bound = b + mid;
            
            auto it1 = lower_bound(a.begin(), a.end(), low_bound);
            auto it2 = upper_bound(a.begin(), a.end(), high_bound);
            int count = it2 - it1;
            
            if (count < k+1) {
                left = mid;
            } else {
                right = mid;
            }
        }
        
        cout << right << endl;
    }
}