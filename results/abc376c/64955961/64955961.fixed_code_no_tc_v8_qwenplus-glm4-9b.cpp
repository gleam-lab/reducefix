#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N - 1);
    
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; i++) {
        cin >> B[i];
    }
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<long long>());
    
    long long x = 0; // This will be our answer.
    
    // Iterate from the largest to the smallest in B to find the minimum x.
    for (int i = 0; i < N - 1; i++) {
        if (B[i] > A[i]) {
            // If the box size is greater than the toy size, we need to consider a new box size.
            x = max(x, A[i] + 1);
        }
        if (x > A.back()) {
            // If the x we found is already greater than the largest toy, we can break early.
            break;
        }
    }
    
    // If x is still 0, it means we couldn't find a valid x for all toys.
    // Otherwise, we print the maximum x we found.
    cout << (x > 0 ? x : -1) << endl;
    
    return 0;
}