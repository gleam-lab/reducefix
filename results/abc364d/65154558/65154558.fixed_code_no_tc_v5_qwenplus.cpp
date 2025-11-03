#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_N = 1e5 + 5;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    
    vector<ll> a(N);
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    
    // Sort the A points for binary search
    sort(a.begin(), a.end());
    
    for(int j = 0; j < Q; j++){
        ll b;
        int k;
        cin >> b >> k;
        
        // Find the k-th smallest distance from B_j to any A_i
        // We'll use binary search on the answer (distance)
        ll left = 0, right = 2e8 + 10;
        ll ans = right;
        
        while(left <= right){
            ll mid = (left + right) / 2;
            
            // Count how many points A_i are within distance 'mid' from point b
            ll lower_bound = b - mid;
            ll upper_bound = b + mid;
            
            auto it1 = lower_bound(a.begin(), a.end(), lower_bound);
            auto it2 = upper_bound(a.begin(), a.end(), upper_bound);
            
            int count = it2 - it1; // number of points within [b-mid, b+mid]
            
            if(count >= k){
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