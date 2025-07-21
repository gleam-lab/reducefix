#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> A(N), B(N-1);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N-1; ++i) cin >> B[i];

    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());

    int i = 0, j = 0;
    int remaining = -1;

    while (i < N && j < N-1) {
        if (A[i] <= B[j]) {
            i++;
            j++;
        } else {
            if (remaining == -1) {
                remaining = A[i];
                i++;
            } else {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    if (i < N) {
        if (remaining == -1) {
            remaining = A[i];
            i++;
        } else {
            cout << -1 << endl;
            return 0;
        }
    }

    if (remaining != -1) {
        cout << remaining << endl;
    } else {
        cout << 1 << endl;
    }

    return 0;
}