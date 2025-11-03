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
        k--; // convert to 0-indexed
        
        // Binary search on the answer (distance)
        int left = -1;
        int right = 200000000; // max possible distance is 2e8
        
        while (right - left > 1) {
            int mid = (left + right) / 2;
            
            // Count how many points in A are within distance 'mid' from B_j
            int lower_bound = b - mid;
            int upper_bound = b + mid;
            
            auto it1 = lower_bound(a.begin(), a.end(), lower_bound);
            auto it2 = upper_bound(a.begin(), a.end(), upper_bound);
            int count = it2 - it1;
            
            if (count <= k) {
                left = mid;
            } else {
                right = mid;
            }
        }
        
        cout << right << endl;
    }
}