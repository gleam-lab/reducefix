#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    ll N;
    cin >> N;
    
    vector<ll> A(N), B(N - 1);
    for (ll i = 0; i < N; ++i) cin >> A[i];
    for (ll i = 0; i < N - 1; ++i) cin >> B[i];
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    multiset<ll> b_set(B.begin(), B.end());

    ll x = -1;
    for (ll i = 0; i < N; ++i) {
        auto it = b_set.lower_bound(A[i]);
        if (it != b_set.end()) {
            // There is a box that can fit this toy
            b_set.erase(it);
        } else {
            // No box can fit this toy, we need to use the new box
            if (x != -1) {
                // Already used one toy for new box, cannot do it again
                cout << -1 << endl;
                return;
            }
            x = A[i];
        }
    }

    if (x == -1) {
        // All toys fit in existing boxes, choose minimal possible x that is not used
        // Take smallest unused box size + 1 or something like that
        // But since we must output x such that we can execute step 2,
        // and all toys are already placed, we can pick any x >= 1
        // Let's find the minimal possible x not conflicting with our placement logic
        cout << 1 << endl;
    } else {
        cout << x << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}