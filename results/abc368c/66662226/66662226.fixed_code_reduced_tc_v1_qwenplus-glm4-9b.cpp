#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> h(n);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    for (ll health : h) {
        while (health > 0) {
            if (health % 3 == 0) {
                health -= 3;
            } else {
                health -= 1;
            }
            ans++;
        }
    }
    cout << ans << endl;
}