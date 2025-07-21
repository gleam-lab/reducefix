#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    vector<ll> A(n), B(n - 1);
    for (ll i = 0; i < n; ++i) {
        cin >> A[i];
    }
    for (ll i = 0; i < n - 1; ++i) {
        cin >> B[i];
    }

    // First, check if there are any toys that cannot fit in any box
    bool impossible = true;
    for (ll i = 0; i < n; ++i) {
        bool canFit = false;
        for (ll j = 0; j < n - 1; ++j) {
            if (A[i] <= B[j]) {
                canFit = true;
                break;
            }
        }
        if (!canFit) {
            cout << "-1" << endl;
            return;
        }
    }

    // If all toys can fit in any of the given boxes, we need to find the minimum x
    // We will use a binary search approach to find the smallest possible x
    ll left = 0, right = 1;
    for (ll i = 0; i < n - 1; ++i) {
        right = max(right, B[i]);
    }
    while (left < right) {
        ll mid = left + (right - left) / 2;
        bool possible = true;
        for (ll i = 0; i < n; ++i) {
            bool canPlace = false;
            for (ll j = 0; j < n - 1; ++j) {
                if (A[i] <= B[j] || B[j] <= mid) {
                    canPlace = true;
                    break;
                }
            }
            if (!canPlace && A[i] > mid) {
                possible = false;
                break;
            }
        }
        if (possible) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    cout << left << endl;
}

int main() {
    solve();
    return 0;
}