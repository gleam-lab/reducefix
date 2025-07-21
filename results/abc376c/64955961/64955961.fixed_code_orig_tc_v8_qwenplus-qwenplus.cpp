#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    vector<ll> A(n), B(n - 1);
    for (ll i = 0; i < n; ++i) cin >> A[i];
    for (ll i = 0; i < n - 1; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    multiset<ll> boxes;
    for (ll b : B) boxes.insert(b);

    ll required_x = -1;

    // Try to place each toy in a suitable box or determine the need for x
    for (ll a : A) {
        auto it = boxes.lower_bound(a);
        if (it != boxes.end()) {
            // Found a box that can fit this toy
            boxes.erase(it);
        } else {
            // Need a new box of at least size 'a'
            if (required_x == -1 || a < required_x)
                required_x = a;
        }
    }

    cout << required_x << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}