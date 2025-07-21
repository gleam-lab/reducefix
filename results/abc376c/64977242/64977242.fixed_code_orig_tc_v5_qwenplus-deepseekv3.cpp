#include <iostream>
#include <vector>
#include <algorithm>

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

    vector<long long> possible_x;
    // Check if the first N-1 toys can fit into the first N-1 boxes
    bool possible = true;
    for (int i = 0; i < N - 1; ++i) {
        if (A[i] > B[i]) {
            possible = false;
            break;
        }
    }
    if (possible) {
        possible_x.push_back(A.back());
    }

    // Check if the last N-1 toys can fit into the N-1 boxes
    possible = true;
    for (int i = 1; i < N; ++i) {
        if (A[i] > B[i - 1]) {
            possible = false;
            break;
        }
    }
    if (possible) {
        possible_x.push_back(A[0]);
    }

    // Check if inserting x allows the N toys to fit into N boxes
    // General case: find the minimal x such that after sorting, the toys fit into boxes
    // The minimal x is the maximum between the largest toy not covered by existing boxes
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    long long min_x = -1;
    // The approach is to find the minimal x such that in the merged list of B and x,
    // the toys can be matched one-to-one with boxes where toy <= box.
    // The merged boxes are B + x, sorted. Then, we need to find x such that when we
    // sort all boxes (B + x), we can pair A[i] <= boxes[i] for all i.
    // The minimal x is the smallest value >= A[k] where k is the position in the merged list.

    // We can binary search for x. The possible x must be >= A[N-1] (since all boxes must be >= toys)
    // So the minimal x is the maximum between the largest toy not covered by the existing boxes.
    // But to compute this, we can consider the following:
    // After sorting A and B, we can try to match A[i] <= B[i] for i < N-1, and x >= A[N-1].
    // Or, if we place x in some position, the other toys must fit into the remaining boxes.
    // The minimal x is the maximum A[i] not covered by any B[j], which is:
    // For the merged list of B and x, sorted, each A[i] (sorted) must be <= boxes[i] in the merged list.
    // So for each A[i] in sorted order, boxes[i] must be >= A[i], where boxes is B + x, sorted.

    // So the minimal x is the smallest value such that when B is sorted and x is added, then sorted,
    // the condition A[i] <= boxes[i] holds for all i.
    // So the minimal x is the smallest x such that if we replace some element in B with x (or add x),
    // the sorted B + x can cover sorted A.

    // The approach is:
    // Sort A and B.
    // The minimal x is the maximum of:
    // For the first N-1 elements of A, check if A[i] <= B[i], then x must be >= A[N-1].
    // Or, if some A[i] > B[i-1], then x must be >= A[i], etc.

    // Alternative idea: after sorting A and B, the minimal x is the maximum between:
    // A[N-1], and any A[i] that is not covered by B[i] when B is extended by x.

    // Wait, in the cases where the first N-1 toys fit into the first N-1 boxes,
    // then x must be >= A[N-1], so x is A[N-1].
    // Or, if the last N-1 toys fit into the N-1 boxes, then x must be >= A[0], so x is A[0].
    // But we need to find the minimal x that works in all possible scenarios.

    // So, the correct approach is to:
    // 1. Sort A and B.
    // 2. For each i from 0 to N-1, consider that the new box x is used to cover A[i], and check if the remaining toys can be covered by the B boxes.
    // The minimal x would then be the minimal A[i] for which such a scenario exists.

    // So for each i in 0..N-1, we need to check if the N-1 boxes in B can cover the N-1 toys in A except A[i].
    // Then, x must be >= A[i], and the minimal such x is the minimal A[i] for which the remaining toys can be covered by B.

    // To check for each i, whether the N-1 boxes can cover the N-1 toys A excluding A[i]:
    // Merge the first i elements of A and the elements after i, then check if this merged list can be matched with B.

    // So the algorithm will be:
    // Sort A and B.
    // For each i in 0..N-1:
    //   Create a list of N-1 toys: all elements of A except A[i].
    //   Check if this list can be matched with the B boxes (each toy <= box, in sorted order).
    //   If yes, then a possible x is A[i], and we track the minimal such x.

    // The minimal x among all possible A[i] is the answer.

    // Implementing this:

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    long long res = -1;

    for (int skip = 0; skip < N; ++skip) {
        vector<long long> remaining_toys;
        for (int j = 0; j < N; ++j) {
            if (j != skip) {
                remaining_toys.push_back(A[j]);
            }
        }
        bool valid = true;
        for (int j = 0; j < N - 1; ++j) {
            if (remaining_toys[j] > B[j]) {
                valid = false;
                break;
            }
        }
        if (valid) {
            if (res == -1 || A[skip] < res) {
                res = A[skip];
            }
        }
    }

    cout << res << endl;

    return 0;
}