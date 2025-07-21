#include <iostream>
#include <vector>
#include <map>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> P(N + 1, 0);
    vector<int> X(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
    }
    
    ll sum = 0;
    for (int i = 0; i < N; ++i) {
        ll p;
        cin >> p;
        sum += p;
        P[i + 1] = sum;
    }
    
    map<int, int> x_to_pos;
    for (int i = 0; i < N; ++i) {
        x_to_pos[X[i]] = i;
    }
    
    int Q;
    cin >> Q;
    while (Q--) {
        int L, R;
        cin >> L >> R;
        
        auto l_pos = x_to_pos.lower_bound(L);
        auto r_pos = x_to_pos.upper_bound(R);
        
        if (l_pos == x_to_pos.end()) {
            l_pos--;
        }
        
        if (r_pos == x_to_pos.end()) {
            r_pos--;
        }
        
        ll ans = P[r_pos->second + 1] - P[l_pos->second + 1];
        cout << ans << endl;
    }
    
    return 0;
}