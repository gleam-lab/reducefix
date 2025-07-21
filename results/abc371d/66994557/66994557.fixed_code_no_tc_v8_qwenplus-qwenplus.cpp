#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
    cin >> n;
    int x[200005], p[200005];
    
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    
    // Build prefix sum array
    int sum[200005] = {0};
    for(int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + p[i];
    }
    
    cin >> q;
    while(q--) {
        int L, R;
        cin >> L >> R;
        
        // Find first index where x[i] >= L
        int l = lower_bound(x + 1, x + n + 1, L) - x;
        
        // Find first index where x[i] > R
        int r = upper_bound(x + 1, x + n + 1, R) - x;
        
        if (l <= r - 1) {
            cout << sum[r - 1] - sum[l - 1] << endl;
        } else {
            cout << 0 << endl; // No elements in range
        }
    }
    
    return 0;
}