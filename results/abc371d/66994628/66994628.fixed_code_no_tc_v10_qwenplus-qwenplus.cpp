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
    
    // Build prefix sum of p
    int sum[200005] = {0};
    for(int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + p[i];
    }
    
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        
        // Find first index where x[i] >= l
        int left = lower_bound(x + 1, x + n + 1, l) - x;
        
        // Find first index where x[i] > r
        int right = upper_bound(x + 1, x + n + 1, r) - x;
        
        if(left < right) {
            cout << sum[right - 1] - sum[left - 1] << endl;
        } else {
            cout << 0 << endl; // No elements in range
        }
    }
    
    return 0;
}