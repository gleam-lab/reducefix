#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<ll> X(N);
    vector<ll> P(N+1, 0);
    
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
    }
    
    for (int i = 0; i < N; ++i) {
        ll p;
        cin >> p;
        P[i+1] = P[i] + p;
    }
    
    map<ll, int> x_to_ptr;
    for (int i = 0; i < N; ++i) {
        x_to_ptr[X[i]] = i;
    }
    
    int Q;
    cin >> Q;
    while (Q--) {
        ll L, R;
        cin >> L >> R;
        
        auto it_l = x_to_ptr.lower_bound(L);
        auto it_r = x_to_ptr.upper_bound(R);
        
        int l = (it_l == x_to_ptr.end()) ? N : it_l->second;
        int r = (it_r == x_to_ptr.end()) ? N : it_r->second;
        
        cout << P[r] - P[l] << '\n';
    }
    
    return 0;
}