#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<int> x, p;
vector<long long> sum;

int main() {
    cin >> n;
    x.resize(n + 1);
    p.resize(n + 1);
    
    for(int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    
    for(int i = 1; i <= n; ++i) {
        cin >> p[i];
        sum.push_back(sum.empty() ? p[i] : sum.back() + p[i]);
    }

    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        
        // Adjust indices since we are using 1-based indexing internally
        --l; --r;
        
        if(l == 0) {
            cout << sum[r] << '\n';
        } else {
            cout << sum[r] - sum[l - 1] << '\n';
        }
    }
    return 0;
}