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

    multiset<long long> b_set;
    for (long long x : B) b_set.insert(x);

    for (int i = 0; i < N; ++i) {
        auto it = b_set.lower_bound(A[i]);
        if (it != b_set.end()) {
            b_set.erase(it);
        } else {
            // Cannot fit this toy in any unused box => need a new box
            if (i == N - 1) {
                // Only one toy left, we can use this as the extra box
                cout << A[i] << endl;
                return 0;
            } else {
                // This toy cannot be placed, and we have more toys to place => invalid
                cout << -1 << endl;
                return 0;
            }
        }
    }

    // All toys could be placed without needing an extra box
    cout << -1 << endl;
}