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

    // We need to assign N toys to N boxes: N-1 existing and one new box
    // Try to assign largest toys to largest boxes greedily

    ll j = n - 2; // index for B (boxes)
    vector<ll> unassigned;

    // Go from largest toy to smallest
    for (ll i = n - 1; i >= 0; --i) {
        if (j >= 0 && B[j] >= A[i]) {
            // This box can fit this toy
            j--;
        } else {
            // Can't fit, must go to new box
            unassigned.push_back(A[i]);
        }
    }

    if (unassigned.size() > 1) {
        cout << -1 << '\n';
    } else {
        cout << (unassigned.empty() ? 0 : unassigned[0]) << '\n';
    }

    return 0;
}