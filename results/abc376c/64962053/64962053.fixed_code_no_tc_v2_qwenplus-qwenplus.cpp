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

    // We need to assign the smallest possible box size x such that:
    // - All toys fit into boxes, one toy per box
    // - One of the boxes is the purchased one with size x

    // The idea is: try to match largest toy with largest available B boxes,
    // and find the first toy which cannot be matched, then x must be at least that toy's size
    // Also ensure that the purchased box can accommodate that toy.

    int i = N - 1, j = N - 2;
    while (i >= 0 && j >= 0) {
        if (B[j] >= A[i]) {
            --i;
            --j;
        } else {
            --i;
        }
    }

    if (i < 0) {
        // All toys were matched without needing the new box
        // So we can use any small value not used in B, but problem requires x to be the size of purchased box
        // Since all toys are covered, we can just output 1 (minimal positive integer)
        cout << 1 << endl;
        return 0;
    }

    // Minimum size needed for the purchased box is A[i]
    // But we must ensure this x is not already covered by a box in B
    // If there are multiple toys with same size, ensure enough boxes exist in B or we use x for the unmatched ones

    // Final check: for the remaining unmatched toys, can we cover them using one purchased box?
    // Since we're trying to minimize x, just use A[i], the size of the largest unmatched toy

    cout << A[i] << endl;

    return 0;
}