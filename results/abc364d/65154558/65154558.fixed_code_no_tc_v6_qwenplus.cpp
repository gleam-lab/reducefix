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
    
    // Sort the A points for binary search and efficient queries
    sort(a.begin(), a.end());
    
    for(int j = 0; j < Q; j++){
        ll b;
        int k;
        cin >> b >> k;
        
        // Find distances from B_j to all A_i
        // Instead of computing all distances, we can use binary search on answer
        // But simpler approach: find k-th smallest distance using two pointers or binary search
        
        // We'll do binary search on the answer (distance)
        ll left = 0, right = 2e8 + 10;
        
        while(left < right){
            ll mid = (left + right) / 2;
            
            // Count how many points A_i are within distance 'mid' from point b
            ll count = 0;
            
            // Points in [b - mid, b + mid]
            auto it1 = lower_bound(a.begin(), a.end(), b - mid);
            auto it2 = upper_bound(a.begin(), a.end(), b + mid);
            count = it2 - it1;
            
            if(count >= k){
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        cout << left << endl;
    }
    
    return 0;
}