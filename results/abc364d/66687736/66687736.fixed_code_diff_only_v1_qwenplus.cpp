#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define vi vector<int>
#define vl vector<ll>

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    vi a(n);
    rep(i, n) {
        cin >> a[i];
    }
    
    // Sort the A points for binary search
    sort(a.begin(), a.end());
    
    rep(i, q) {
        int b, k;
        cin >> b >> k;
        k--; // Convert to 0-indexed
        
        // We'll use binary search on the answer (distance)
        int left = -1;
        int right = 200000000; // Maximum possible distance
        
        while (right - left > 1) {
            int mid = (left + right) / 2;
            
            // Count how many points in A are within distance 'mid' from B
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