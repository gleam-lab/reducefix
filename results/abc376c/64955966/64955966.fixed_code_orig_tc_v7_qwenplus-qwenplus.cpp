#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<long long> A(N), B(N - 1);

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < N - 1; ++i) {
        cin >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    long long x = -1;

    int j = 0;
    for (int i = 0; i < N; ++i) {
        if (j < N - 1 && A[i] <= B[j]) {
            ++j;
        } else {
            if (x == -1) {
                x = A[i];
            } else {
                // More than one toy cannot fit into existing boxes
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << x << endl;
    return 0;
}