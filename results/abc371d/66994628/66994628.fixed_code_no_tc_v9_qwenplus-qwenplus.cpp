#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n;
    
    vector<int> x(n + 2); // Add padding for easier edge handling
    vector<int> p(n + 2);
    vector<int> prefix_sum(n + 2, 0);
    
    for(int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    
    for(int i = 1; i <= n; ++i) {
        cin >> p[i];
        prefix_sum[i] = prefix_sum[i - 1] + p[i];
    }
    
    cin >> q;
    
    while(q--) {
        int l, r;
        cin >> l >> r;
        
        // Find first index where x[i] >= l
        int left = lower_bound(x.begin() + 1, x.begin() + n + 1, l) - x.begin();
        // Find first index where x[i] > r
        int right = upper_bound(x.begin() + 1, x.begin() + n + 1, r) - x.begin();
        
        if(left < right) {
            cout << prefix_sum[right - 1] - prefix_sum[left - 1] << '\n';
        } else {
            cout << 0 << '\n'; // No elements in range
        }
    }
    
    return 0;
}