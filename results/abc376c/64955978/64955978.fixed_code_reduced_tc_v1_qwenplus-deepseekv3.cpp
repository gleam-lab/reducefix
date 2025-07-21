#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N), B(N - 1);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        cin >> B[i];
    }

    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());

    int i = 0, j = 0, cnt = 0;
    while (i < N && j < N - 1) {
        if (A[i] <= B[j]) {
            ++i;
            ++j;
            ++cnt;
        } else {
            ++i;
        }
    }

    if (cnt == N) {
        cout << -1 << '\n';
    } else if (cnt == N - 1) {
        cout << A.back() << '\n';
    } else {
        cout << -1 << '\n';
    }

    return 0;
}