#include<bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N), B(N - 1);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        cin >> B[i];
    }

    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());

    int i = 0, j = 0;
    vector<int> remaining;

    while (i < N && j < N - 1) {
        if (A[i] <= B[j]) {
            ++i;
            ++j;
        } else {
            remaining.push_back(A[i]);
            ++i;
        }
    }

    while (i < N) {
        remaining.push_back(A[i]);
        ++i;
    }

    if (remaining.size() > 1) {
        cout << -1 << endl;
    } else {
        if (remaining.empty()) {
            // All toys fit in existing boxes, so x can be any size >= 0 (but problem says purchase one box, so perhaps x can be 1)
            // However, the problem requires placing all toys in separate boxes, which is already satisfied, so x can be minimal (e.g., 1)
            cout << 1 << endl;
        } else {
            cout << remaining[0] << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}