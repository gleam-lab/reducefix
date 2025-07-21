#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N), B(N - 1);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];

    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());

    int i = 0, j = 0;
    int remaining = 0;
    while (i < N && j < N - 1) {
        if (A[i] <= B[j]) {
            ++i;
            ++j;
        } else {
            ++remaining;
            ++i;
        }
    }
    remaining += N - i;

    if (remaining != 1) {
        cout << -1 << endl;
        return;
    }

    int x = (i < N) ? A[i] : A.back();
    cout << x << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}