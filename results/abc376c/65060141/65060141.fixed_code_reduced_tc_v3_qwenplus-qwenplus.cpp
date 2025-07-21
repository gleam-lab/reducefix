#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

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

    // We need to find the minimum x such that we can assign all toys to boxes
    // with one toy per box, and one of the boxes has size x.

    // Try to match largest toys with largest available boxes
    ll need_box = -1;
    ll a_idx = n - 1;
    ll b_idx = n - 2;

    while (a_idx >= 0 && b_idx >= 0) {
        if (b[b_idx] >= a[a_idx]) {
            // Box can fit this toy
            b_idx--;
            a_idx--;
        } else {
            // This toy doesn't fit in any remaining box
            // We'll need a new box of at least this size
            need_box = max(need_box, a[a_idx]);
            a_idx--;
        }
    }

    // If there's still a toy left after using all boxes, we need another box
    if (a_idx >= 0) {
        need_box = max(need_box, a[a_idx]);
    }

    cout << (need_box == -1 ? 0 : need_box) << endl;

    return 0;
}