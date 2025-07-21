#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> H(n);
    rep(i, n) cin >> H[i];

    ll T = 0;

    // We simulate the process in a way that processes each enemy one by one
    rep(i, n) {
        ll h = H[i];

        // While this enemy still has health left
        while (h > 0) {
            T++;

            // Check if current T is a multiple of 3
            if (T % 3 == 0) {
                h -= 3;
            } else {
                h--;
            }

            // If we are past the first enemy and T reaches a point where it would affect next enemies,
            // we need to update their health accordingly
            // But since we're simulating sequentially, we only need to ensure that each attack is applied correctly

            // No need to store updated health unless we want to optimize further
        }
    }

    cout << T << endl;
}