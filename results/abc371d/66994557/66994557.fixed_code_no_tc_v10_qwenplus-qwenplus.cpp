#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
    cin >> n;
    vector<int> x(n + 1), p(n + 1);
    
    for(int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    
    for(int i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    
    // Prefix sum array
    vector<long long> prefix_sum(n + 1, 0);
    for(int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + p[i];
    }
    
    cin >> q;
    while(q--) {
        int L, R;
        cin >> L >> R;
        
        // Find the first index where x[i] >= L
        int left = lower_bound(x.begin() + 1, x.end(), L) - x.begin();
        
        // Find the first index where x[i] > R
        int right = upper_bound(x.begin() + 1, x.end(), R) - x.begin();
        
        // The number of elements in range [L, R] is from left to right - 1
        if(left <= right - 1) {
            cout << prefix_sum[right - 1] - prefix_sum[left - 1] << endl;
        } else {
            cout << 0 << endl;  // No elements in the range
        }
    }

    return 0;
}