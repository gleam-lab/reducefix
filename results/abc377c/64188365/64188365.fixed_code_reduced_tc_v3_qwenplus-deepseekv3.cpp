#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;
    set<pair<ll, ll>> unsafe;
    
    vector<pair<ll, ll>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };
    
    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        unsafe.emplace(a, b);
        
        for (const auto &dir : directions) {
            ll new_a = a + dir.first;
            ll new_b = b + dir.second;
            if (new_a >= 1 && new_a <= N && new_b >= 1 && new_b <= N) {
                unsafe.emplace(new_a, new_b);
            }
        }
    }
    
    cout << N * N - unsafe.size() << endl;
}