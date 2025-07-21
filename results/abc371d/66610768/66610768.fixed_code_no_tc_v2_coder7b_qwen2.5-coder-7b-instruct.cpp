#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> prefix_sum;

void preprocess(vector<int>& X, vector<int>& P) {
    int n = X.size();
    prefix_sum.resize(n + 1, 0);
    
    for (int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + P[i - 1];
    }
}

ll get_villagers_in_range(int L, int R, const vector<int>& X) {
    auto it_l = lower_bound(X.begin(), X.end(), L);
    auto it_r = upper_bound(X.begin(), X.end(), R);
    
    if (it_l == X.end() || *it_l > R) return 0; // No villages in range
    
    int idx_l = it_l - X.begin();
    int idx_r = it_r - X.begin() - 1;
    
    return prefix_sum[idx_r + 1] - prefix_sum[idx_l];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, q;
    cin >> n;
    vector<int> X(n), P(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> X[i];
    }
    
    for (int i = 0; i < n; ++i) {
        cin >> P[i];
    }
    
    preprocess(X, P);
    
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        
        cout << get_villagers_in_range(l, r, X) << '\n';
    }

    return 0;
}