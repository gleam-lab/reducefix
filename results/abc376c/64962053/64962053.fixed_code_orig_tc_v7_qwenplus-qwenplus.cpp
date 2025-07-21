#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<long long> A(N), B(N - 1);

    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    multiset<long long> box_sizes;
    for (int i = 0; i < N - 1; ++i) {
        box_sizes.insert(B[i]);
    }

    // Try to place each toy in a suitable box
    for (int i = 0; i < N; ++i) {
        auto it = box_sizes.lower_bound(A[i]);
        if (it != box_sizes.end()) {
            // Found a suitable box, use it
            box_sizes.erase(it);
        } else {
            // Cannot place this toy without the additional box
            cout << A[i] << endl;
            return 0;
        }
    }

    // All toys could be placed without needing an extra box
    cout << -1 << endl;
    return 0;
}