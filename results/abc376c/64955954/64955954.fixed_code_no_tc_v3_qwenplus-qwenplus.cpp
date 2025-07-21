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

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Check if the smallest (N-1) toys can fit in the sorted boxes
    bool possible = true;
    for (int i = 0; i < N - 1; ++i) {
        if (B[i] < A[i]) {
            possible = false;
            break;
        }
    }

    if (!possible) {
        cout << -1 << endl;
        return 0;
    }

    // The largest toy A[N-1] must go into the new box.
    // Find the minimal x such that x >= A[N-1]
    // and x > A[i] for all i where B[i] == A[i] (to ensure we cannot swap those)

    long long min_x = A.back();
    for (int i = 0; i < N - 1; ++i) {
        if (B[i] < A[i + 1]) {
            min_x = max(min_x, (long long)A[i + 1]);
            break;
        }
    }

    cout << min_x << endl;
    return 0;
}