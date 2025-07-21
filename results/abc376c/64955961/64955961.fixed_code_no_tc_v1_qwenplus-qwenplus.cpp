#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n - 1);
    
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (ll i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // We need to match N toys to N boxes (N-1 existing + 1 new)
    // Try to assign the largest toys to the largest available boxes first
    ll x = -1;

    ll i = n - 1, j = n - 2; // i: toy index, j: box index
    while (i >= 0 && j >= 0) {
        if (a[i] <= b[j]) {
            // Assign this toy to this box
            --i;
            --j;
        } else {
            // This toy cannot fit in any remaining box, so we must put it in the new box
            x = a[i];
            --i;
        }
    }

    // If there is one or zero toys left unmatched, and all boxes are used,
    // then Takahashi can use the new box for the remaining toy(s).
    if (x == -1 && i >= 0) {
        // All toys matched to existing boxes; no special box needed
        cout << 1 << endl;
    } else if (x != -1) {
        // The smallest box that can contain the unmatched toy
        cout << x << endl;
    } else {
        // All toys were matched
        cout << 1 << endl;
    }
}

int main() {
    solve();
}