#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;

    vector<ll> A(n), B(n - 1);

    for (ll i = 0; i < n; ++i) {
        cin >> A[i];
    }

    for (ll i = 0; i < n - 1; ++i) {
        cin >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    ll extra_box_size = -1;

    ll j = 0; // pointer for B
    for (ll i = 0; i < n; ++i) {
        if (j < n - 1 && B[j] >= A[i]) {
            j++;
        } else {
            if (extra_box_size == -1) {
                extra_box_size = A[i];
            } else {
                // Need more than one extra box -> impossible
                cout << -1 << '\n';
                return 0;
            }
        }
    }

    cout << extra_box_size << '\n';
    return 0;
}