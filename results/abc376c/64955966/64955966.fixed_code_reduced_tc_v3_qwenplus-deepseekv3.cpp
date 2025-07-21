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

    int i = 0, j = 0;
    int need_x = 0;
    int count_x = 0;

    while (i < N && j < N-1) {
        if (A[i] <= B[j]) {
            ++i;
            ++j;
        } else {
            if (count_x == 0) {
                need_x = A[i];
                ++i;
                ++count_x;
            } else {
                cout << -1 << endl;
                return;
            }
        }
    }

    while (i < N) {
        if (count_x == 0) {
            need_x = A[i];
            ++i;
            ++count_x;
        } else {
            cout << -1 << endl;
            return;
        }
    }

    if (count_x == 1) {
        cout << need_x << endl;
    } else if (count_x == 0) {
        // All toys fit in existing boxes, but we need to buy one extra box (can be smallest possible)
        // So x can be 1 (as smallest toy is at least 1)
        cout << 1 << endl;
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