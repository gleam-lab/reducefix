#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

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

    ll extra_box_size = 0;
    ll b_ptr = 0;

    for (ll a : A) {
        if (b_ptr < B.size() && B[b_ptr] >= a) {
            b_ptr++;
        } else {
            // Need to use the extra box
            if (extra_box_size == 0) {
                extra_box_size = a;
            } else {
                // We already used the extra box, no space left
                cout << -1 << endl;
                return 0;
            }
        }
    }

    if (extra_box_size == 0) {
        // All toys fit in boxes without needing an extra one
        // We can still use a very small box just to satisfy the condition
        // The smallest toy not perfectly matched will work
        // But since all toys fit, we can use x = 1
        cout << 1 << endl;
    } else {
        cout << extra_box_size << endl;
    }

    return 0;
}