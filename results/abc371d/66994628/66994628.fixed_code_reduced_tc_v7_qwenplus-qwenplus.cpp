#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n;
    
    vector<ll> x(n+2), p(n+2);  // Using 1-based indexing
    
    for(int i = 1; i <= n; ++i){
        cin >> x[i];
    }
    
    for(int i = 1; i <= n; ++i){
        cin >> p[i];
    }
    
    // Create prefix sum array
    vector<ll> sum(n+2, 0);
    for(int i = 1; i <= n; ++i){
        sum[i] = sum[i-1] + p[i];
    }
    
    cin >> q;
    
    while(q--){
        ll l, r;
        cin >> l >> r;
        
        // Find first index where x[i] >= l
        int left_idx = lower_bound(x.begin() + 1, x.begin() + n + 1, l) - x.begin();
        
        // Find first index where x[i] > r
        int right_idx = upper_bound(x.begin() + 1, x.begin() + n + 1, r) - x.begin();
        
        // The number of people is the sum from left_idx to right_idx-1 in p array
        if(left_idx > right_idx){
            cout << 0 << endl;
        } else {
            cout << sum[right_idx - 1] - sum[left_idx - 1] << endl;
        }
    }
    
    return 0;
}