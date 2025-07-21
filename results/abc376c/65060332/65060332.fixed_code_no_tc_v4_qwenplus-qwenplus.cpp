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

    ll extra_box_needed = -1;

    // Use two pointers to match largest toys with largest available boxes
    ll toy_idx = n - 1;
    ll box_idx = n - 2;

    while (toy_idx >= 0 && box_idx >= 0) {
        if (B[box_idx] >= A[toy_idx]) {
            // Box can fit this toy
            toy_idx--;
            box_idx--;
        } else {
            // This toy cannot fit in any remaining box, need extra box
            if (extra_box_needed != -1) {
                cout << -1;
                return 0;
            }
            extra_box_needed = A[toy_idx];
            toy_idx--;
        }
    }

    // If there's one toy left unmatched
    if (toy_idx >= 0) {
        if (extra_box_needed != -1) {
            cout << -1;
        } else {
            cout << A[toy_idx];
        }
    } else {
        cout << extra_box_needed;
    }

    return 0;
}