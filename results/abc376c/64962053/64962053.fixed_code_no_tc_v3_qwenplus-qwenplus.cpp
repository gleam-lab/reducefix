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

    // We need to assign N toys to N boxes: N-1 existing B's + one new box of size x
    // Each toy must go to a box with size >= toy size, and each box can contain at most one toy.
    // Goal: find the minimal x such that this is possible.

    // Strategy:
    // Try to match the largest N-1 toys to the boxes B,
    // then the smallest toy will go into the new box. So x >= smallest unmatched toy.
    // But we have to ensure that it is possible to match the top N-1 toys to B in a way
    // that all fits.

    // We try matching largest toys to largest available boxes

    // First, sort A in ascending order, so A[0] <= A[1] <= ... <= A[N-1]
    // Similarly for B

    // We try to assign the largest N-1 toys to the N-1 boxes.
    // For this, we compare A[i] <= B[i], for i from N-2 down to 0

    // The idea is:
    // If we sort both A and B in increasing order,
    // and match A[0] to A[N-2] with B[0] to B[N-2],
    // then the largest toy A[N-1] will be left out, which needs its own box.

    // However, for correct pairing, we must ensure that for each i in [0, N-2], A[i] <= B[i]

    bool possible = true;
    long long min_x = 0;

    // Try to match A[0..N-2] with B[0..N-2], check if possible
    for (int i = 0; i < N - 1; ++i) {
        if (A[i] > B[i]) {
            possible = false;
            break;
        }
    }

    if (!possible) {
        cout << -1 << endl;
        return 0;
    }

    // Then x must be >= A[N-1] (the largest toy), and also,
    // since we want to minimize x, we can set x = max(A[N-1], B[N-2])
        // Wait! No, because we sorted B in increasing order
        // B[N-2] is the second largest box
        // the largest toy must go into a box larger than or equal to it
        // and since all other toys are matched to boxes B[0..N-2], and those are all smaller than B[N-1]
        // So we can place the largest toy in a new box of size at least A[N-1]
        // but we also must make sure that the second largest toy fits in B[N-2]

    // Actually, we tried matching A[0..N-2] to B[0..N-2]
    // So the largest toy A[N-1] must go to the new box => x >= A[N-1]

    cout << A[N - 1] << endl;

    return 0;
}