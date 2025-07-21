#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> A(N), B(N - 1);

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        cin >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    multiset<long long> b_set;
    for (long long b : B) {
        b_set.insert(b);
    }

    for (int i = N - 1; i >= 0; --i) {
        auto it = b_set.lower_bound(A[i]);
        if (it != b_set.end()) {
            b_set.erase(it);
        } else {
            if (!b_set.empty()) {
                // Can't place all toys, so we need to check whether a box can be added
                cout << A[i] << '\n';
                return 0;
            }
        }
    }

    // If all toys were placed without needing an extra box
    cout << "-1\n";
    return 0;
}