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
    
    vector<ll> a(N);
    rep(i, N) cin >> a[i];
    
    sort(a.begin(), a.end());
    
    rep(qi, Q) {
        ll b;
        int k;
        cin >> b >> k;
        
        // We are looking for the k-th smallest distance from b to points in a
        // Instead of computing all distances, we can binary search on the answer (distance)
        // For a given distance d, count how many points are within distance <= d from b
        // That is: count of a[i] such that |a[i] - b| <= d
        // <=> b-d <= a[i] <= b+d
        
        ll left = -1;
        ll right = 200000000; // max possible coordinate difference is 2e8, so max distance is 2e8
        
        while (right - left > 1) {
            ll mid = (left + right) / 2;
            // Count number of points within distance <= mid from b
            ll low = b - mid;
            ll high = b + mid;
            
            auto it1 = lower_bound(a.begin(), a.end(), low);
            auto it2 = upper_bound(a.begin(), a.end(), high);
            int cnt = distance(it1, it2);
            
            if (cnt >= k) {
                right = mid;
            } else {
                left = mid;
            }
        }
        
        cout << right << '\n';
    }
}