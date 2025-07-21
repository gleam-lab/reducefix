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
        a--; b--;
        unsafe.insert({a, b});
        
        // Check all 8 possible attack positions
        if (a + 2 < N && b + 1 < N) unsafe.insert({a + 2, b + 1});
        if (a + 1 < N && b + 2 < N) unsafe.insert({a + 1, b + 2});
        if (a - 1 >= 0 && b + 2 < N) unsafe.insert({a - 1, b + 2});
        if (a - 2 >= 0 && b + 1 < N) unsafe.insert({a - 2, b + 1});
        if (a - 2 >= 0 && b - 1 >= 0) unsafe.insert({a - 2, b - 1});
        if (a - 1 >= 0 && b - 2 >= 0) unsafe.insert({a - 1, b - 2});
        if (a + 1 < N && b - 2 >= 0) unsafe.insert({a + 1, b - 2});
        if (a + 2 < N && b - 1 >= 0) unsafe.insert({a + 2, b - 1});
    }
    
    cout << N * N - unsafe.size() << endl;
    return 0;
}