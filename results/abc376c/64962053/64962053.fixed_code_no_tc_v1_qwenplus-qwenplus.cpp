#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<long long> A(N);
    vector<long long> B(N - 1);
    
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // We need to assign N toys to N boxes: N-1 given + 1 new box.
    // Each toy must go into a box of size >= its size.
    // We want the minimal x such that we can assign all toys.

    // Try to match the smallest N-1 toys with the sorted boxes.
    // The largest toy will go to the new box, whose size is at least it.

    // To check feasibility:
    // For each i from 0 to N-2, A[i] should fit in B[i]
    // That is, A[i] <= B[i]

    for (int i = 0; i < N - 1; ++i) {
        if (A[i] > B[i]) {
            cout << -1 << endl;
            return 0;
        }
    }

    // If all good, then the biggest toy (A[N-1]) needs to be placed in the new box.
    // So x needs to be at least A[N-1]

    cout << A[N - 1] << endl;
}