#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N - 1);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        cin >> B[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int x = -1;
    int i = 0, j = 0;
    vector<bool> used(N - 1, false);

    // Try to match toys to boxes greedily
    while (i < N && j < N - 1) {
        if (A[i] <= B[j]) {
            used[j] = true;
            ++i;
            ++j;
        } else {
            ++j;
        }
    }

    if (i < N) {
        // The remaining toys must be placed in the new box x
        // x must be >= all remaining toys, and the smallest possible is A[N-1]
        // But also, x must not be used in B (if B already has x, it's a problem)
        // So x must be >= the largest remaining toy
        // But if all boxes are used, then x must cover all remaining toys
        // So x must be >= the largest toy not placed in any box
        int max_remaining = A.back();
        // Check if max_remaining is in B (if so, then x must be >= it)
        // But since we sorted B and used some boxes, we need to ensure x is not in B
        // So x must be >= max_remaining and not present in B
        bool found = binary_search(B.begin(), B.end(), max_remaining);
        if (found) {
            // Need an x > max_remaining that is not in B
            // Find the smallest x >= max_remaining not in B
            x = max_remaining;
            while (binary_search(B.begin(), B.end(), x)) {
                ++x;
            }
        } else {
            x = max_remaining;
        }
    } else {
        // All toys are placed in existing boxes; x can be any (but problem says to choose smallest, but since no toy is left, x can be 1)
        // But the problem might require x to be such that it doesn't disrupt existing placements, but since all toys are placed, x can be 1 (but it's not used)
        // So output -1 (as no need to purchase any box)
        x = -1;
    }

    // Now verify if with x, we can place all toys
    // We need to check if the remaining toys (those not placed in B) can be placed in x
    // So collect all toys not placed in B
    vector<int> remaining_toys;
    i = 0; j = 0;
    while (i < N && j < N - 1) {
        if (A[i] <= B[j]) {
            ++i;
            ++j;
        } else {
            remaining_toys.push_back(A[i]);
            ++i;
        }
    }
    while (i < N) {
        remaining_toys.push_back(A[i]);
        ++i;
    }

    if (remaining_toys.empty()) {
        cout << -1 << endl;
    } else {
        int required_x = remaining_toys.back();
        if (required_x <= x) {
            // Check if x is not in B
            if (x == -1 || !binary_search(B.begin(), B.end(), x)) {
                cout << x << endl;
            } else {
                // Need to find the smallest x not in B and >= required_x
                x = required_x;
                while (binary_search(B.begin(), B.end(), x)) {
                    ++x;
                }
                cout << x << endl;
            }
        } else {
            // Even the largest remaining toy is larger than x (but x is -1)
            cout << -1 << endl;
        }
    }

    return 0;
}