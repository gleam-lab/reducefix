#include<bits/stdc++.h>
using namespace std;

int n, q, x[200005], p[200005];
map<int, int> prefix_sum;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        prefix_sum[x[i]] += p[i];
    }
    
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        
        // Find the first element greater than or equal to L
        auto it1 = prefix_sum.lower_bound(L);
        // Find the first element strictly greater than R
        auto it2 = prefix_sum.upper_bound(R);
        
        if (it1 != prefix_sum.end()) {
            cout << (*it1).second;
        } else {
            cout << 0;
        }
        
        if (it2 != prefix_sum.begin()) {
            --it2;
            cout << " " << (*it2).second;
        } else {
            cout << " 0";
        }
        
        cout << endl;
    }
    
    return 0;
}