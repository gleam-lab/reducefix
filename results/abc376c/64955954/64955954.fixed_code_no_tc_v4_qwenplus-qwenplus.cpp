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

    // We need to assign each toy to a box.
    // One extra box is available, so we can afford one toy that doesn't fit in B[i]
    // Try greedy matching with two pointers

    int i = 0, j = 0;
    int extra_needed = 0;
    while (i < N && j < N - 1) {
        if (A[i] <= B[j]) {
            ++i;
            ++j;
        } else {
            ++i;
            ++extra_needed;
        }
    }

    // If extra_needed is more than 1, we cannot place all toys
    if (extra_needed > 1) {
        cout << -1 << endl;
        return 0;
    }

    // If all toys matched successfully, the extra box size can be 0 (but per problem, it must be positive)
    if (i == N) {
        cout << 1 << endl;
        return 0;
    }

    // We need to find minimal x such that remaining unmatched toy fits in x
    // Remaining toy is A[N-1], since all previous ones were matched or only one remains
    cout << A.back() << endl;

    return 0;
}