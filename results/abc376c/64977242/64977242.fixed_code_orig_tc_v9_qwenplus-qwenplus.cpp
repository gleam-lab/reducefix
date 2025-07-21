#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<long long> A(N), B(N - 1);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Check if it's possible to place N-1 smallest toys in the N-1 boxes
    bool possible = true;
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

    // The required size of the new box is at least A[N-1]
    // and must be greater than any toy that cannot fit in the largest N-1 boxes.
    long long x = A.back();

    // Now check whether we can replace one box with our new box of size x
    // so that all toys can be placed.

    // We simulate the assignment:
    // Try to assign each toy to a box of at least its size.
    // Since we have sorted both arrays, we try greedy matching.

    // Use multiset to manage available boxes (include x as an extra box)
    multiset<long long> boxes;
    for (int i = 0; i < N - 1; ++i) {
        boxes.insert(B[i]);
    }
    boxes.insert(x);  // add the new box

    for (int i = 0; i < N; ++i) {
        auto it = boxes.lower_bound(A[i]);
        if (it == boxes.end()) {
            // No suitable box found
            cout << -1 << endl;
            return 0;
        }
        boxes.erase(it);  // use this box
    }

    cout << x << endl;
    return 0;
}