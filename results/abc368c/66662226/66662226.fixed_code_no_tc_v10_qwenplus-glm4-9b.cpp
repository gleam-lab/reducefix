#include <iostream>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> h(n);
    ll ans = 0;

    for (int i = 0; i < n; ++i) {
        cin >> h[i];
        // Calculate the number of full attacks (T) needed to reduce the enemy's health to 0 or less
        ans += (h[i] + 2) / 3; // (h[i] + 2) / 3 is equivalent to ceil(h[i] / 3)
    }

    cout << ans << endl;
    return 0;
}