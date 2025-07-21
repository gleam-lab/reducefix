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

    // We need to find the minimal x such that we can assign all toys to boxes
    // including one box of size x.

    // The largest toy must go into the largest box or the new box.
    // So we try to match smallest toys with smallest available boxes.

    int i = 0;
    for (; i < N - 1; ++i) {
        if (B[i] < A[i]) {
            // Need a box at least as big as A[i] to fit unmatched toy
            cout << A[i] << endl;
            return 0;
        }
    }

    // If all boxes matched and still one toy left, it goes in new box
    cout << A.back() << endl;
    return 0;
}