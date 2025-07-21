#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n - 1);
    for (ll i = 0; i < n; ++i) cin >> a[i];
    for (ll i = 0; i < n - 1; ++i) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // We need to find the smallest x such that we can assign all toys to boxes
    // with one toy per box, and one of the toys goes into the new box of size x.

    // Try to match largest toys to largest available boxes first.
    // If a[i] > b[j], we must put a[i] in the new box. Only one toy can go there.

    ll new_box_needed_for = -1;
    ll j = n - 2; // index for boxes (n-1 boxes)

    // Try to assign toys from big to small
    for (ll i = n - 1; i >= 0 && j >= 0; --i) {
        if (a[i] <= b[j]) {
            --j; // this box is used
        } else {
            // This toy cannot fit in any unused box, needs the new box
            if (new_box_needed_for != -1) {
                // Already one toy needs new box => not possible
                cout << -1 << endl;
                return;
            }
            new_box_needed_for = a[i];
        }
    }

    // After loop, if j < 0 and still some a[i] left, only one can be left to go to new box
    if (new_box_needed_for != -1) {
        cout << new_box_needed_for << endl;
    } else {
        // If no toy requires new box, we can use x = 1 (or any value ≥ smallest toy)
        cout << a[0] << endl;
    }
}

int main() {
    solve();
}