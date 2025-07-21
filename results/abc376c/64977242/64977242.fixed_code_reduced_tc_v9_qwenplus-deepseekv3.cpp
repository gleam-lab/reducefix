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

    // The new box must contain one toy, and the rest must fit into the existing boxes.
    // We need to find a toy that is not in any of the existing boxes when sorted and matched.
    // The minimal x is the smallest toy that is not in its corresponding box when matched.
    // Alternatively, it could be the largest toy that is larger than its corresponding box.

    vector<bool> used(N, false);
    int i = 0, j = 0;
    while (i < N && j < N - 1) {
        if (A[i] <= B[j]) {
            used[i] = true;
            ++i;
            ++j;
        } else {
            ++j;
        }
    }

    vector<long long> remaining_toys;
    for (int k = 0; k < N; ++k) {
        if (!used[k]) {
            remaining_toys.push_back(A[k]);
        }
    }

    if (remaining_toys.empty()) {
        // All toys are placed in existing boxes, but we need an extra box.
        // So the new box can be of size 1, but must not be used. But the problem says place each.
        // So the new box must fit at least one toy, but all toys are placed in existing boxes.
        // This means the new box can be any size, but the minimal is 1.
        // But the problem requires placing each toy in a box, so probably the new box is unused.
        // But the problem requires placing each toy in one of the N boxes. So the new box must contain one toy.
        // So the new box's size must be >= some toy.
        // So the minimal x is the smallest toy in A.
        cout << A[0] << endl;
    } else if (remaining_toys.size() == 1) {
        cout << remaining_toys[0] << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}