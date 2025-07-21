#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<long long> A(N), B(N-1);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // We need to find the smallest x such that:
    // There exists a permutation of A where each element fits in one of the boxes (B + x)
    // and no two elements go into the same box.

    // We try to match smallest toys with smallest available boxes

    multiset<long long> boxes;
    for (long long b : B) boxes.insert(b);

    // Try to fit all toys, keeping track of required new box size
    long long required_x = -1;

    for (int i = 0; i < N; ++i) {
        // Find the smallest box that can fit A[i]
        auto it = boxes.lower_bound(A[i]);
        if (it != boxes.end()) {
            // Use that box
            boxes.erase(it);
        } else {
            // No suitable box found, we must use the new box
            if (required_x == -1 || A[i] > required_x) {
                required_x = A[i];
            }
        }
    }

    if (required_x == -1) {
        // This shouldn't happen as we always have a new box
        cout << -1 << endl;
    } else {
        cout << required_x << endl;
    }

    return 0;
}