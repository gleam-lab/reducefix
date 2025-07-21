#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, ans = 0, tri = 1;
    cin >> n;
    vector<ll> h(n);
    for (ll i = 0; i < n; ++i) cin >> h[i];
    
    // Function to simulate the battle process
    auto battle = [&](ll& hp) -> void {
        if (hp > 0) {
            if (tri % 3 == 0) hp -= 3;
            else hp -= 1;
            ans++;
            if (hp <= 0) return;
            battle(hp);
        }
    };
    
    for (auto& hp : h) battle(hp);
    
    cout << ans << endl;
    return 0;
}