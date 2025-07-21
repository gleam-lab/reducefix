#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> A(N), B(N - 1);

    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];

    sort(A.begin(), A.end(), greater<long long>());
    sort(B.begin(), B.end(), greater<long long>());

    int i = 0, j = 0;
    long long required_x = -1;

    while (i < N && j < N - 1) {
        if (A[i] <= B[j]) {
            ++j;
        } else {
            required_x = max(required_x, A[i]);
        }
        ++i;
    }

    // Remaining toys (if any) must go into new box
    while (i < N) {
        required_x = max(required_x, A[i++]);
    }

    cout << required_x << endl;

    return 0;
}