#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> H(n);

    for (int i = 0; i < n; ++i) {
        cin >> H[i];
    }

    ll t = 0;
    for (ll h : H) {
        while (h > 0) {
            if (t % 3 == 0) {
                h -= 3;
            } else {
                h--;
            }
            t++;
        }
    }

    cout << t << endl;
    return 0;
}