#include<bits/stdc++.h>
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
    int new_box_toys = 0;
    int required_x = 0;

    for (int i = 0; i < N; ++i) {
        bool placed = false;
        for (int j = 0; j < N - 1; ++j) {
            if (!used[j] && B[j] >= A[i]) {
                used[j] = true;
                placed = true;
                break;
            }
        }
        if (!placed) {
            new_box_toys++;
            if (A[i] > required_x) {
                required_x = A[i];
            }
        }
    }

    if (new_box_toys > 1) {
        cout << -1 << endl;
    } else {
        cout << required_x << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}