#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N - 1);
    
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; i++) {
        cin >> B[i];
    }
    
    // Sort toy and box sizes
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int i = 0, j = 0, x = INT_MAX;
    
    // Find the minimum x
    while (i < N && j < N - 1) {
        if (A[i] <= B[j]) {
            // This box can accommodate the current toy
            x = min(x, B[j]);
            j++;  // Move to the next box
        } else {
            // This box cannot accommodate the current toy
            i++;  // Move to the next toy
        }
    }
    
    // If not all toys have been matched, there is no valid x
    if (i != N) {
        cout << -1 << endl;
    } else {
        cout << x << endl;
    }
    
    return 0;
}