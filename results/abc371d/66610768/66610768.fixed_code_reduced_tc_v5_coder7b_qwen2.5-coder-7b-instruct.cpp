#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 7;
int n, q;
vector<int> X(MAXN), P(MAXN), prefix_sum(MAXN);

void preprocess() {
    prefix_sum[0] = 0;
    for(int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + P[i - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> X[i];
    }
    for(int i = 1; i <= n; ++i) {
        cin >> P[i];
    }
    cin >> q;
    
    preprocess();

    while(q--) {
        int l, r;
        cin >> l >> r;
        
        auto it_l = lower_bound(X.begin() + 1, X.end(), l);
        auto it_r = upper_bound(X.begin() + 1, X.end(), r);
        
        int idx_l = distance(X.begin(), it_l);
        int idx_r = distance(X.begin(), it_r) - 1;
        
        if(idx_l > idx_r) continue; // No valid range
        
        if(it_r == X.end()) { // If right bound is out of array
            cout << prefix_sum[n] - prefix_sum[idx_l - 1] << '\n';
        } else {
            cout << prefix_sum[idx_r] - prefix_sum[idx_l - 1] << '\n';
        }
    }
    
    return 0;
}