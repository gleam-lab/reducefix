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
    // The possible x will be the A[i] that was not matched in B
    // We can try to match the first N-1 A's to B, then x is A[N-1]
    // Or match the last N-1 A's to B, then x is A[0]
    // Or some other combination. The correct approach is to match the largest N-1 A's with the largest B's.

    // Sort A and B in ascending order
    // Try to match the smallest N-1 A's to the smallest B's: A[i] <= B[i]
    bool possible = true;
    for (int i = 0; i < N - 1; ++i) {
        if (A[i] > B[i]) {
            possible = false;
            break;
        }
    }
    if (possible) {
        // The largest remaining A is A[N-1], which must be <= x
        possible_x.push_back(A[N-1]);
    }

    // Another approach: sort A in ascending and B in ascending, then match A[i+1] <= B[i]
    possible = true;
    for (int i = 0; i < N - 1; ++i) {
        if (A[i+1] > B[i]) {
            possible = false;
            break;
        }
    }
    if (possible) {
        possible_x.push_back(A[0]);
    }

    // Another approach: sort A in ascending and B in ascending, then match the largest N-1 A's to B's
    // So, compare A[1..N-1] with B[0..N-2]
    possible = true;
    for (int i = 1; i < N; ++i) {
        if (A[i] > B[i-1]) {
            possible = false;
            break;
        }
    }
    if (possible) {
        possible_x.push_back(A[0]);
    }

    // Similarly, other combinations might be possible, but the minimal x is the minimal among the possible x's
    if (possible_x.empty()) {
        cout << -1 << endl;
    } else {
        cout << *min_element(possible_x.begin(), possible_x.end()) << endl;
    }

    return 0;
}