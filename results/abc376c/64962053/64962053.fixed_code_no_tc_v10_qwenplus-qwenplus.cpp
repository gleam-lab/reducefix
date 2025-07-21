#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    vector<long long> B(N - 1);

    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // We need to find the minimal x such that we can assign all toys to boxes,
    // including one new box of size x, so that every toy fits in its box.

    // The largest toy must go into either:
    // - the new box (then x must be at least A[N-1])
    // - or the largest available box B[N-2], but then we have to check if the rest can fit

    // Let's try to see if we can use B[i] for A[i], and leave A[N-1] to the new box.
    // Then x must be at least A[N-1]

    // Try to match A[0..N-2] with B[0..N-2]
    for (int i = 0; i < N - 1; ++i) {
        if (B[i] < A[i]) {
            // Cannot place A[i] in any box <= B[i], not enough boxes
            cout << A[N - 1] << endl;
            return 0;
        }
    }

    // If all A[0..N-2] can be placed in B[0..N-2], then only A[N-1] needs a new box
    // So minimal x is A[N-1]
    cout << A[N - 1] << endl;
}