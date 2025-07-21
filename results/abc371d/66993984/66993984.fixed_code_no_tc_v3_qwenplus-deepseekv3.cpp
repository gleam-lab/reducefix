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
        
        // Find first element >= L
        int left_pos = lower_bound(x.begin()+1, x.end(), L) - x.begin();
        // Find first element > R
        int right_pos = upper_bound(x.begin()+1, x.end(), R) - x.begin();
        
        if(left_pos > right_pos || left_pos > n || right_pos == 1) {
            cout << 0 << endl;
        } else {
            cout << prefix_sum[right_pos-1] - prefix_sum[left_pos-1] << endl;
        }
    }
    return 0;
}