#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;
    set<pair<ll, ll>> unsafe;
    
    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        a--; b--; // Convert to 0-based for easier boundary checks
        unsafe.insert({a, b});
        
        // All 8 possible knight moves
        int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
        
        for (int k = 0; k < 8; ++k) {
            ll new_a = a + dx[k];
            ll new_b = b + dy[k];
            if (new_a >= 0 && new_a < N && new_b >= 0 && new_b < N) {
                unsafe.insert({new_a, new_b});
            }
        }
    }
    
    cout << N * N - unsafe.size() << endl;
    return 0;
}