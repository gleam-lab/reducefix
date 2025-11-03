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
        
        // We want to find the k-th smallest distance from B to any A_i
        // That is: sort |a_i - b| and return the k-th element (1-indexed)
        
        // Binary search on the answer (the distance)
        ll low = 0;
        ll high = 2e8 + 10; // max possible distance is about 2*1e8
        
        while (low < high) {
            ll mid = (low + high) / 2;
            
            // Count how many points A_i are within distance <= mid from b
            // That is: count of i such that |a_i - b| <= mid
            // => b - mid <= a_i <= b + mid
            
            ll left_bound = b - mid;
            ll right_bound = b + mid;
            
            auto it1 = lower_bound(a.begin(), a.end(), left_bound);
            auto it2 = upper_bound(a.begin(), a.end(), right_bound);
            int count = distance(it1, it2);
            
            if (count >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        
        cout << low << '\n';
    }
}