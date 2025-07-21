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
    
    // The box size 'x' must be at least as large as the largest toy that cannot be stored in any of the existing boxes.
    // This is the maximum size that a new box must have to ensure that all toys can be stored.
    long long max_size_needed = 0;
    for (int i = 0; i < N; i++) {
        // A[i] must be less than or equal to some B[j] for each toy to be stored.
        // We find the largest B[j] that is less than or equal to A[i].
        auto it = upper_bound(B.begin(), B.end(), A[i]);
        if (it == B.begin()) { // If A[i] is larger than all B[j], then we need a new box of size at least A[i].
            max_size_needed = max(max_size_needed, A[i]);
        } else {
            // The can be placed in the box just before the upper_bound iterator.
            max_size_needed = max(max_size_needed, *prev(it) + 1);
        }
    }
    
    // Since we need a box that is at least as large as the maximum size needed and is the smallest possible
    // such box, we add 1 to max_size_needed if it is odd (because we need an integer box size).
    cout << (max_size_needed % 2 == 0 ? max_size_needed : max_size_needed + 1) << endl;
    
    return 0;
}