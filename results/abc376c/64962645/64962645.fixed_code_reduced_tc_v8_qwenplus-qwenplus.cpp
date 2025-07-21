#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

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

    // Check if all but one toys can fit into the existing boxes
    int j = 0;
    for (int i = 0; i < N; ++i) {
        if (j < N - 1 && A[i] <= B[j]) {
            j++;
        }
    }

    if (j == N - 1) {
        // The smallest toy that doesn't fit in any box is our answer
        cout << A[N - 1] << endl;
    } else {
        // There are some toys we couldn't place even with the best matching
        cout << -1 << endl;
    }

    return 0;
}