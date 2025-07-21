#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n-1);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < n-1; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // Function to check if it's possible to place all toys with a new box of size x
    auto is_possible = [&](ll x) {
        vector<ll> boxes = b;
        boxes.push_back(x);
        sort(boxes.begin(), boxes.end());
        ll i = 0, j = 0;
        while (i < n && j < n) {
            if (a[i] <= boxes[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }
        return i == n;
    };

    ll low = 1, high = 1e18;
    ll ans = -1;
    while (low <= high) {
        ll mid = (low + high) / 2;
        if (is_possible(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (ans != -1) {
        // Now find the minimal x that is >= some a[i] and works
        // We need to find the smallest a[i] that is not covered by the existing boxes without x
        // But we can optimize by checking the minimal possible x which is the a[i] that is left out
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        bool possible = false;
        vector<bool> used(n-1, false);
        ll j = 0;
        ll cnt = 0;
        for (ll i = 0; i < n; i++) {
            while (j < n-1 && b[j] < a[i]) {
                j++;
            }
            if (j < n-1 && b[j] >= a[i]) {
                cnt++;
                j++;
            }
        }
        if (cnt >= n-1) {
            // All except one can be placed, find the a[i] not placed
            vector<bool> placed(n, false);
            j = 0;
            for (ll i = 0; i < n; i++) {
                while (j < n-1 && b[j] < a[i]) {
                    j++;
                }
                if (j < n-1 && b[j] >= a[i]) {
                    placed[i] = true;
                    j++;
                }
            }
            ll missing = -1;
            for (ll i = 0; i < n; i++) {
                if (!placed[i]) {
                    missing = a[i];
                    break;
                }
            }
            if (missing != -1) {
                ans = missing;
            }
        }
    }

    cout << ans << endl;
    return 0;
}