#include <bits/stdc++.h>

using namespace std;

long long findMinBoxSize(int N, vector<int> &A, vector<int> &B) {
    sort(A.begin(), A.end()); // Sort toys by size in ascending order
    sort(B.begin(), B.end()); // Sort boxes by size in ascending order
    
    int j = 0; // Index for iterating through boxes
    for (int i = 0; i < N; ++i) {
        if (j == B.size()) { // If we've run out of boxes
            return -1; // Not enough boxes to accommodate all toys
        }
        while (j < B.size() && B[j] < A[i]) { // Find a box big enough for current toy
            ++j;
        }
        if (j == B.size()) { // If we still don't have a suitable box
            return -1; // Not enough boxes to accommodate all toys
        }
        ++j; // Move to the next box
    }
    return A.back(); // Return the size of the last toy as the minimum box size needed
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N), B(N - 1);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        cin >> B[i];
    }

    cout << findMinBoxSize(N, A, B) << endl;

    return 0;
}