#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N - 1);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vector<long long> possible_x;

    // The new box must accommodate at least one toy, which is the largest toy not fitting into the largest N-1 boxes.
    // We can pair the largest N-1 toys with the largest N-1 boxes, and the remaining toy goes to the new box.
    // Thus, x must be at least the size of the remaining toy.

    // Case 1: The smallest x is max(A[N-1], A[k] where A[k] is not covered by B)
    // We need to find the minimal x such that when we pair the largest N-1 toys with the largest N-1 boxes,
    // the remaining toy is <= x.

    // The largest N toys are A[N-1], A[N-2], ..., A[0] (sorted in ascending order, so A[N-1] is largest)
    // The largest N-1 boxes are B[N-2], B[N-3], ..., B[0] (sorted in ascending order)

    bool possible = true;
    for (int i = 0; i < N - 1; ++i) {
        if (A[i + 1] > B[i]) {
            possible = false;
            break;
        }
    }

    if (possible) {
        // All toys except the smallest can be placed in the existing boxes.
        // The new box must accommodate the smallest toy.
        cout << A[0] << endl;
        return 0;
    }

    // Otherwise, we need to find the minimal x such that:
    // - The new box accommodates one toy, and the rest can be matched to existing boxes.
    // The minimal x is the largest toy that cannot be matched to any existing box when optimally matched.

    // Optimal matching is to match the largest N-1 toys to the largest N-1 boxes, and the remaining toy goes to x.
    // So, the minimal x is the largest toy not covered by this matching.

    sort(A.begin(), A.end(), greater<long long>());
    sort(B.begin(), B.end(), greater<long long>());

    long long x_candidate = -1;
    for (int i = 0; i < N; ++i) {
        if (i < N - 1) {
            if (A[i] > B[i]) {
                x_candidate = A[i];
                break;
            }
        } else {
            x_candidate = A[i];
        }
    }

    // Now, verify if with x = x_candidate, all toys can be placed.
    // We need to ensure that all toys can be placed in either existing boxes or the new box.
    // The new box can hold one toy, so the remaining N-1 toys must fit into the existing N-1 boxes.

    // Merge the new box into the boxes list for verification.
    vector<long long> boxes = B;
    boxes.push_back(x_candidate);
    sort(boxes.begin(), boxes.end());
    sort(A.begin(), A.end());

    possible = true;
    for (int i = 0; i < N; ++i) {
        if (A[i] > boxes[i]) {
            possible = false;
            break;
        }
    }

    if (possible) {
        cout << x_candidate << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}