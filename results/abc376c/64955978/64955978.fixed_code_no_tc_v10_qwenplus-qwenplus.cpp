#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N), B(N - 1);

    for (ll i = 0; i < N; ++i) cin >> A[i];
    for (ll i = 0; i < N - 1; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Try to match toys to boxes greedily
    ll i = 0, j = 0;
    ll unpaired_toy = -1;

    while (i < N && j < N - 1) {
        if (A[i] <= B[j]) {
            i++;
            j++;
        } else {
            i++;  // This toy cannot fit in current box or any smaller box, so skip it
        }
    }

    // After greedy matching, if all boxes are used and some toys remain,
    // the remaining toys need to go into the new purchased box.
    // We need to find the smallest x that can fit all unmatched toys.

    // The unpaired toy is the one that couldn't be matched due to insufficient box size
    // It's either the largest unmatched toy
    if (j == N - 1) {
        // All boxes are used, remaining toys must go into new box
        if (i < N) {
            cout << A[N - 1] << endl;  // Largest unmatched toy
            return;
        } else {
            cout << -1 << endl;
            return;
        }
    }

    // If we ran out of toys before boxes, the leftover boxes don't matter
    // But if we ran out of boxes first, we need a new box big enough for remaining toys
    if (i < N) {
        cout << A[N - 1] << endl;  // Largest remaining toy is the minimum required size
    } else {
        cout << -1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}