#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> A(N), B(N - 1);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    multiset<long long> b_set(B.begin(), B.end());

    // Try to fit the smallest toy first in the smallest available box
    for (int i = 0; i < N; ++i) {
        auto it = b_set.lower_bound(A[i]);
        if (it == b_set.end()) {
            // No suitable box found for this toy, we need a new box of size A[i]
            cout << A[i] << '\n';
            return 0;
        }
        b_set.erase(it); // Use the box
    }

    // All toys can be placed without an additional box
    cout << -1 << '\n';
    return 0;
}