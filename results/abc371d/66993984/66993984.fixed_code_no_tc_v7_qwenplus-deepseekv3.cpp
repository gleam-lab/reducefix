#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n;
    vector<int> x(n+1), p(n+1);
    vector<int> prefix_sum(n+1, 0);
    
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        prefix_sum[i] = prefix_sum[i-1] + p[i];
    }
    
    cin >> q;
    while(q--) {
        int L, R;
        cin >> L >> R;
        
        // Find first x[i] >= L
        int left = lower_bound(x.begin()+1, x.end(), L) - x.begin();
        // Find first x[i] > R
        int right = upper_bound(x.begin()+1, x.end(), R) - x.begin();
        
        // The valid range is [left, right-1]
        if(left > right) {
            cout << "0\n";
        } else {
            cout << prefix_sum[right-1] - prefix_sum[left-1] << "\n";
        }
    }
    return 0;
}