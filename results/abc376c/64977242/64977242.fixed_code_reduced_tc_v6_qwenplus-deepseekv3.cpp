#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N - 1);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N - 1; i++) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vector<long long> possible_x;

    // Check if we can match first N-1 toys to boxes
    bool possible = true;
    for (int i = 0; i < N - 1; i++) {
        if (A[i] > B[i]) {
            possible = false;
            break;
        }
    }
    if (possible) {
        possible_x.push_back(A.back());
    }

    // Check if we can match last N-1 toys to boxes
    possible = true;
    for (int i = 1; i < N; i++) {
        if (A[i] > B[i - 1]) {
            possible = false;
            break;
        }
    }
    if (possible) {
        possible_x.push_back(A.front());
    }

    // Check for other possible positions where the new box can be used
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // The new box must be at least the largest A not covered by B
    // We need to find the minimal x such that:
    // When we assign N-1 toys to N-1 boxes, the remaining toy can fit in x.
    // So, we can pair N-1 toys to boxes, leaving out one toy.

    // The optimal x is the smallest A that is not covered by B in any possible pairing
    // So, we can try to pair N-1 toys to boxes in sorted order, leaving the largest toy for x.
    // Or pair N-1 toys (excluding the smallest) and leave the smallest for x.

    // Another approach: find the minimal x such that when we insert x into B and sort,
    // then when we compare sorted A to sorted B (with x), each A[i] <= B[i].
    // The minimal such x is the minimal value that fills the gap.

    // The minimal x is the maximum between:
    // The largest A not covered in the best possible pairing.

    // So, the minimal x is the maximum unmatched A when we try to match N-1 A's to N-1 B's.
    // So, we can pair the first N-1 A's to N-1 B's with A[i] <= B[i], then x >= A[N-1].
    // Or, pair the last N-1 A's to N-1 B's, then x >= A[0].

    // The minimal x is the minimum of these maximums.
    if (possible_x.empty()) {
        cout << -1 << endl;
    } else {
        cout << *min_element(possible_x.begin(), possible_x.end()) << endl;
    }

    return 0;
}