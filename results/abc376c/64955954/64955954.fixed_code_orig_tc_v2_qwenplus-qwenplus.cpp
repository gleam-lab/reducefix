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

    // We need to assign each toy to a box such that box size >= toy size.
    // Since one extra box will be added, we can leave one toy to be placed in the new box.

    // To find the minimal x, we check how many toys can be matched with current boxes greedily.

    int j = 0;
    for (int i = 0; i < N && j < N - 1; ++i) {
        if (B[j] >= A[i]) {
            ++j;
        }
    }

    if (j == N - 1) {
        // One toy left unmatched. It requires the new box.
        cout << A.back() << '\n';
    } else {
        // Not all existing boxes could be used, so not possible to place all toys.
        cout << -1 << '\n';
    }

    return 0;
}