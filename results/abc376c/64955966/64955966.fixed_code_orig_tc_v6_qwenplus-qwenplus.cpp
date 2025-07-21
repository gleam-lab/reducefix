#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<long long> A(N), B(N - 1);

    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];

    sort(A.begin(), A.end(), greater<long long>());
    sort(B.begin(), B.end(), greater<long long>());

    int j = 0;
    for (int i = 0; i < N; ++i) {
        if (j < N - 1 && A[i] <= B[j]) {
            ++j;
        }
    }

    if (j == N - 1) {
        cout << -1 << endl;
    } else {
        cout << A[N - 1 - j] << endl;
    }

    return 0;
}