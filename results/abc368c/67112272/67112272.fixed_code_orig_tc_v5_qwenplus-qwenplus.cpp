#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    // Binary search on answer T
    ll low = 0, high = 1e18, ans = 0;
    while (low <= high) {
        ll mid = (low + high) / 2;
        ll strong = mid / 3;
        ll weak = mid - strong;
        vector<ll> temp = h;

        // Try to apply attacks greedily
        bool ok = true;
        for (int i = 0; i < n && (strong > 0 || weak > 0); ++i) {
            ll use_strong = min(strong, temp[i] / 3 + (temp[i] % 3 != 0 ? 1 : 0));
            temp[i] -= use_strong * 3;
            strong -= use_strong;

            if (temp[i] > 0) {
                ll rem = temp[i];
                if (rem > weak) {
                    ok = false;
                    break;
                }
                weak -= rem;
                temp[i] = 0;
            }
        }

        if (ok) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << endl;
}