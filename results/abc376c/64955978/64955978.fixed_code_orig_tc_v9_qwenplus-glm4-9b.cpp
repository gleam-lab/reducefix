#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long N;
    cin >> N;
    vector<long long> A(N), B(N-1);
    
    // Read toy sizes
    for (long long i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Read box sizes
    for (long long i = 0; i < N - 1; ++i) {
        cin >> B[i];
    }
    
    // Sort toys and boxes in descending order
    sort(A.begin(), A.end(), greater<long long>());
    sort(B.begin(), B.end(), greater<long long>());
    
    // Find the maximum index of box that can accommodate the largest toy
    long long maxToySize = A[0];
    long long boxIndex = N - 2; // Start from the second last box since the last box is unused
    
    while (boxIndex >= 0 && B[boxIndex] < maxToySize) {
        --boxIndex;
    }
    
    if (boxIndex == -1) {
        // No box can accommodate the largest toy
        cout << -1 << endl;
    } else {
        // The smallest possible box size needed is the size of the box that can accommodate the largest toy
        cout << B[boxIndex] << endl;
    }
    
    return 0;
}