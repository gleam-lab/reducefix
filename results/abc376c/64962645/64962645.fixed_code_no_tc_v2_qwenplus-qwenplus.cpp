#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    vector<long long> B(N - 1);

    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];

    // Sort toys and boxes in descending order
    sort(A.begin(), A.end(), greater<>());
    sort(B.begin(), B.end(), greater<>());

    // We need to find the smallest toy that cannot be placed in available boxes
    // Try to match largest toy with largest box, second largest with second largest box, etc.
    // If all first N-1 toys can fit into the N-1 boxes, then the smallest x is A[N-1]
    // Otherwise, find the first mismatch where A[i] > B[i], and we need to put A[i] in the new box

    int pos = -1;
    for (int i = 0; i < N - 1; ++i) {
        if (A[i] > B[i]) {
            pos = i;
            break;
        }
    }

    // Now compare A[pos] with B[pos], if A[pos] <= B[pos], continue
    // But if pos == -1, it means all A[0..N-2] <= B[0..N-2], so minimum x is A[N-1]

    if (pos == -1) {
        cout << A.back() << endl;
        return 0;
    }

    // At this point, A[pos] > B[pos]
    // To determine if we can still assign A[pos] to the new box,
    // we need to check whether the rest of the toys can be assigned to remaining boxes.

    // Since we will use a new box for A[pos], try matching A[0..pos-1] and A[pos+1..N-1]
    // with B[0..N-2], skipping one box (we'll use it for A[pos])

    // We simulate greedy assignment:
    // Use two pointers approach to match toys (excluding A[pos]) with boxes

    vector<long long> C;
    for (int i = 0; i < N; ++i)
        if (i != pos) C.push_back(A[i]);

    int i = 0, j = 0;
    while (i < N - 1 && j < N - 1) {
        if (C[i] <= B[j]) {
            ++i;
        }
        ++j;
    }

    if (i == N - 1) {
        cout << A[pos] << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}