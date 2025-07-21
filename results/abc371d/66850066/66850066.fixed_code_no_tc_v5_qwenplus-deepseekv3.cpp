#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int main(){
    int N;
    cin >> N;
    vector<ll> X(N), P(N+1);
    P[0] = 0;
    for (int i = 0; i < N; ++i) cin >> X[i];
    for (int i = 0; i < N; ++i) {
        ll p;
        cin >> p;
        P[i+1] = P[i] + p;
    }
    
    vector<pair<int, int>> sorted_X;
    for (int i = 0; i < N; ++i) {
        sorted_X.emplace_back(X[i], i);
    }
    sort(sorted_X.begin(), sorted_X.end());
    
    int Q;
    cin >> Q;
    while (Q--) {
        int L, R;
        cin >> L >> R;
        
        // Find first X >= L
        auto lower = lower_bound(sorted_X.begin(), sorted_X.end(), make_pair(L, 0));
        int l_idx = (lower == sorted_X.end()) ? N : lower->second;
        
        // Find first X > R
        auto upper = upper_bound(sorted_X.begin(), sorted_X.end(), make_pair(R, N));
        int r_idx = (upper == sorted_X.end()) ? N : upper->second;
        
        // Calculate sum from l_idx to r_idx-1
        ll ans = P[r_idx] - P[l_idx];
        cout << ans << '\n';
    }
}