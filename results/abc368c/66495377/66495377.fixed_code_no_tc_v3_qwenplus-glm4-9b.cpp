#include <iostream>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> h(n);
    ll t = 0;

    for (int i = 0; i < n; ++i) {
        cin >> h[i];
        while (h[i] > 0) {
            if (t % 3 == 0) {
                h[i] -= 3;
            } else {
                h[i] -= 1;
            }
            t++;
        }
    }

    cout << t << endl;
    return 0;
}