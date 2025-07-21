#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n;
    
    vector<ll> x(n+2), p(n+2);  // Using 1-based indexing
    
    for(int i = 1; i <= n; ++i)
        cin >> x[i];
    
    for(int i = 1; i <= n; ++i){
        cin >> p[i];
        p[i] += p[i-1];  // Compute prefix sum directly
    }
    
    cin >> q;
    
    while(q--){
        ll L, R;
        cin >> L >> R;
        
        // Find first index >= L
        int left = lower_bound(x.begin() + 1, x.begin() + n + 1, L) - x.begin();
        
        // Find last index <= R
        int right = upper_bound(x.begin() + 1, x.begin() + n + 1, R) - x.begin() - 1;
        
        if(left > right)
            cout << 0 << '\n';
        else
            cout << p[right] - p[left-1] << '\n';
    }
    
    return 0;
}