#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n;
    vector<int> x(n+1), p(n+1);
    vector<long long> sum(n+1);  // Using long long to prevent overflow
    
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = sum[i-1] + p[i];
    }
    
    cin >> q;
    while(q--) {
        int query_l, query_r;
        cin >> query_l >> query_r;
        
        // Find first x >= query_l
        int lower = lower_bound(x.begin()+1, x.end(), query_l) - x.begin();
        // Find first x > query_r
        int upper = upper_bound(x.begin()+1, x.end(), query_r) - x.begin();
        
        cout << sum[upper-1] - sum[lower-1] << '\n';
    }
    
    return 0;
}