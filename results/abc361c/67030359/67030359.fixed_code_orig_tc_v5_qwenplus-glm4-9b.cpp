#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // We only need to consider the elements around the boundaries, as those have the most significant impact on the max-min difference.
    int maxMinDiff = A[N-1] - A[0];

    // K elements can be removed, and we want to minimize the max-min difference of the remaining sequence
    // We will compare the difference of max-min by removing one element from either ends and then choosing min of the two differences.
    for (int i = K; i >= 1; i--) {
        maxMinDiff = min(maxMinDiff, max(A[N-1-i] - A[i], A[N-2-i] - A[0]));
    }

    cout << maxMinDiff << endl;
    return 0;
}