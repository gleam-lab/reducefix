#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n - 1);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < n - 1; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll cnt = 0;
    ll ans = -1;
    ll i = 0, j = 0;
    while (i < n && j < n - 1) {
        if (a[i] <= b[j]) {
            i++;
            j++;
        } else {
            cnt++;
            ans = a[i];
            i++;
        }
    }
    while (i < n) {
        cnt++;
        ans = a[i];
        i++;
    }

    if (cnt > 1) {
        cout << -1 << endl;
    } else {
        if (cnt == 0) {
            // All toys fit in existing boxes, but we need to add one box. 
            // The box can be any size >= the smallest toy not placed, but since all are placed, 
            // we can choose the smallest possible (1?)
            // But the problem requires that we add one box, so we must choose the smallest x that doesn't affect existing placements.
            // However, all toys are placed, so the new box won't be used; hence any x >= 1 is possible, but the minimum is 1.
            // But likely, the problem expects us to possibly choose x as the smallest unused box size or similar.
            // Alternatively, it may be impossible to add a box if all toys are already placed, but the problem requires adding exactly one box.
            // Therefore, in this case, the answer should be 1 (the smallest possible x).
            ans = 1;
        }
        cout << ans << endl;
    }
}

int main() {
    solve();
    return 0;
}