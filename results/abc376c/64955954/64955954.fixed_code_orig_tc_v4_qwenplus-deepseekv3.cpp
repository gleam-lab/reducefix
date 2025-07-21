#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N - 1);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    vector<int> possible_x;
    
    // We need to place each A[i] into a box that is >= A[i], with all boxes distinct.
    // The boxes are B[0..N-2] and x (the new box).
    // We can try to match sorted A to sorted B, with one A needing to go to x.
    
    // Check if we can place all A[i] into B's and x, with x being the k-th largest box.
    // We can try to find the smallest x such that:
    // The largest A not covered by B's goes to x.
    
    // The approach is to match the largest N-1 A's to the largest N-1 B's, and the remaining A goes to x.
    // So, x must be >= the remaining A.
    
    // Check if the largest N-1 A's can fit into the largest N-1 B's.
    bool possible = true;
    for (int i = 0; i < N - 1; ++i) {
        if (A[i + 1] > B[i]) {
            possible = false;
            break;
        }
    }
    if (possible) {
        possible_x.push_back(A[0]);
    }
    
    // Another approach: match the largest N-1 A's to the largest N-1 B's.
    // The smallest A might be placed in x.
    possible = true;
    for (int i = 0; i < N - 1; ++i) {
        if (A[i] > B[i]) {
            possible = false;
            break;
        }
    }
    if (possible) {
        possible_x.push_back(A.back());
    }
    
    // Another possible scenario: the largest A is in the new box x, and the rest fit into B's.
    // So x must be >= A.back(), and the remaining A's fit into B's.
    // The remaining A's are A[0..N-2], which should fit into B's.
    possible = true;
    for (int i = 0; i < N - 1; ++i) {
        if (A[i] > B[i]) {
            possible = false;
            break;
        }
    }
    if (possible) {
        possible_x.push_back(A.back());
    }
    
    // Another scenario: the new box x is one of the middle boxes.
    // We need to find if there's a position k such that:
    // A[k] is the one placed in x, and the rest can be placed in B's.
    // We can try for each possible k in 0..N-1.
    for (int k = 0; k < N; ++k) {
        vector<int> tempA;
        for (int i = 0; i < N; ++i) {
            if (i != k) tempA.push_back(A[i]);
        }
        possible = true;
        for (int i = 0; i < N - 1; ++i) {
            if (tempA[i] > B[i]) {
                possible = false;
                break;
            }
        }
        if (possible) {
            possible_x.push_back(A[k]);
        }
    }
    
    if (possible_x.empty()) {
        cout << -1 << endl;
    } else {
        sort(possible_x.begin(), possible_x.end());
        cout << possible_x[0] << endl;
    }
    
    return 0;
}