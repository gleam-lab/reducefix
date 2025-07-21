#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i = 0; i < (int)n; i++)
#define vi vector<int>

int main() {
    int n, q; cin >> n >> q;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    while (q--) {
        int b, k; cin >> b >> k;
        int lo = -1e9, hi = 1e9;
        
        // Binary search to find the k-th closest point
        while (lo + 1 < hi) {
            int mid = lo + (hi - lo) / 2;
            int count = 0;
            
            // Count how many points in A are closer to B than mid
            for (int i = 0; i < n; i++) {
                if (abs(a[i] - b) < mid) count++;
            }
            
            if (count >= k) hi = mid;
            else lo = mid;
        }
        
        cout << abs(b - lo) << endl; // The distance between X and B_j
    }
    
    return 0;
}