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

    int i = 0, j = 0;
    long long x = -1;

    while (i < N && j < N - 1) {
        if (A[i] <= B[j]) {
            ++i;
            ++j;
        } else {
            // Cannot place A[i] in current or any smaller box => needs new box
            x = A[i];
            ++i;
        }
    }

    // At most one toy should be left after this
    if (i < N) {
        if (x == -1) x = A[i];
        else x = max(x, A[i]); // In case more than one left, pick max
    }

    // If still some toys not assigned even after using new box
    if (i < N) {
        cout << -1 << '\n';
    } else {
        cout << x << '\n';
    }

    return 0;
}