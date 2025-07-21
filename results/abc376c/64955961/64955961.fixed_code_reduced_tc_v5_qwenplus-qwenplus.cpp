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

    // We will use a greedy approach with two pointers
    ll toy_ptr = 0;
    ll box_ptr = 0;

    while (toy_ptr < n && box_ptr < n - 1) {
        if (a[toy_ptr] <= b[box_ptr]) {
            toy_ptr++;
        }
        box_ptr++;
    }

    // If all toys could be placed, then no extra box is needed
    if (toy_ptr == n) {
        cout << 0 << endl;
        return;
    }

    // Otherwise, we need to find the largest unplaced toy
    // The answer is the size of that toy
    cout << a.back() << endl;
}

int main() {
    solve();
    return 0;
}