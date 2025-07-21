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
    int new_box_needed = 0;
    int x = 0;

    for (int i = 0; i < N; ++i) {
        if (box_ptr < N-1 && B[box_ptr] >= A[i]) {
            ++box_ptr;
        } else {
            if (new_box_needed == 0) {
                new_box_needed = 1;
                x = A[i];
            } else {
                cout << -1 << endl;
                return;
            }
        }
    }

    if (new_box_needed == 1) {
        cout << x << endl;
    } else {
        // All toys placed in existing boxes, but we need to use exactly one new box.
        // The new box can be of size 1 since it doesn't have to hold any toy.
        cout << 1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}