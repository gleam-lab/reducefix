#include<bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N), B(N-1);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N-1; ++i) cin >> B[i];

    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());

    int x = -1;
    int box_ptr = 0;
    int toy_ptr = 0;
    int cnt = 0;

    while (toy_ptr < N && box_ptr < N-1) {
        if (A[toy_ptr] <= B[box_ptr]) {
            ++box_ptr;
            ++toy_ptr;
        } else {
            if (x != -1) {
                cout << -1 << endl;
                return;
            }
            x = A[toy_ptr];
            ++toy_ptr;
        }
    }

    if (toy_ptr < N) {
        if (x != -1) {
            cout << -1 << endl;
            return;
        }
        x = A[toy_ptr];
    }

    if (x != -1) {
        cout << x << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}