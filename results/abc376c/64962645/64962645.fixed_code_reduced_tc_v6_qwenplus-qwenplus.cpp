#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> A(n);
    vector<long long> B(n - 1);

    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Check if it's possible to assign toys to boxes (excluding one toy)
    // We need to find the minimum x such that we can place all toys in the N-1 boxes + one box of size x

    // We try to match the smallest N-1 toys with the largest N-1 boxes,
    // and the largest toy will be placed in the new box, so x must be at least that toy.

    // To check feasibility: can we fit N-1 toys into the N-1 boxes?
    // Try greedy matching:
    // Match largest toy with largest box until only one toy remains

    int j = 0;
    for (int i = 0; i < n && j < n - 1; ++i) {
        if (A[i] <= B[j]) {
            ++j;
        }
    }

    if (j == n - 1) {
        // We can fit N-1 toys into the boxes. The remaining toy needs a box of its size.
        // Find the unmatched toy (the one with maximum size among unmatched)
        // Since both are sorted, we can just return the largest unmatched A[i]
        cout << A.back() << '\n';
    } else {
        cout << -1 << '\n';
    }

    return 0;
}