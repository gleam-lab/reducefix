#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> B(N - 1);

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        cin >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int j = 0;
    for (int i = 0; i < N; ++i) {
        while (j < N - 1 && B[j] < A[i]) {
            ++j;
        }
        if (j == N - 1 && B[j] < A[i]) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << B.back() + 1 << endl;

    return 0;
}