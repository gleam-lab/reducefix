#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N), B(N-1);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N-1; ++i) cin >> B[i];

    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());

    int box_ptr = 0;
    int x = -1;

    for (int toy_ptr = 0; toy_ptr < N; ++toy_ptr) {
        if (box_ptr < N-1 && A[toy_ptr] <= B[box_ptr]) {
            box_ptr++;
        } else {
            if (x == -1) {
                x = A[toy_ptr];
            } else {
                x = max(x, A[toy_ptr]);
            }
        }
    }

    if (x != -1) {
        cout << x << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}