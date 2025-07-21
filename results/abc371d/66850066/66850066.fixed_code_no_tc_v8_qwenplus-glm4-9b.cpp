#include <iostream>
#include <vector>
#include <map>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> P(N+1, 0);
    vector<int> X(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
    }
    
    for (int i = 0; i < N; ++i) {
        ll p;
        cin >> p;
        P[i+1] = P[i] + p;
    }
    
    map<int, int> x_to_ptr;
    for (int i = 0; i < N; ++i) {
        x_to_ptr.insert({X[i], i});
    }
    
    int Q;
    cin >> Q;
    for (int q = 0; q < Q; ++q) {
        int L, R;
        cin >> L >> R;
        auto X_l = x_to_ptr.lower_bound(L);
        auto X_r = x_to_ptr.upper_bound(R);
        
        // Adjust for one-based indexing
        int l = (X_l != x_to_ptr.end()) ? X_l->second : N;
        int r = (X_r != x_to_ptr.end()) ? X_r->second : N;
        
        cout << P[r] - P[l] << endl;
    }
    
    return 0;
}