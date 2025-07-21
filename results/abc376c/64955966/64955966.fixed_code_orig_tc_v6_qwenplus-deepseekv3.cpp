#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N), B(N - 1);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];

    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());

    vector<bool> used(N - 1, false);
    int j = 0;
    int cnt = 0;
    int x = 0;

    for (int i = 0; i < N; ++i) {
        while (j < N - 1 && (used[j] || B[j] < A[i])) {
            ++j;
        }
        if (j < N - 1 && B[j] >= A[i]) {
            used[j] = true;
        } else {
            ++cnt;
            x = max(x, A[i]);
        }
    }

    if (cnt > 1) {
        cout << -1 << endl;
    } else {
        cout << x << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}