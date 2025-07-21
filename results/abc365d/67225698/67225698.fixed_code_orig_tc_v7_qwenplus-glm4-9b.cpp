#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

void solve() {
    string s;
    ll n;
    cin >> n;
    cin >> s;

    ll ans = 0;
    ll cnt = 0;
    vector<ll> v;
    for (int i = 0; i < n; ++i) {
        if (i == 0 || s[i] == s[i - 1]) {
            cnt++;
        } else {
            ans += (cnt + 1) / 2;
            v.push_back(cnt);
            cnt = 1;
        }
    }
    ans += (cnt + 1) / 2;
    v.push_back(cnt);

    for (int i = 1; i < v.size() - 1; ++i) {
        if (v[i] > 1 && v[i - 1] > 1) {
            ans -= 1;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}