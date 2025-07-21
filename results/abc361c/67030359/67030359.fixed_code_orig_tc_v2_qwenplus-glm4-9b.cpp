#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    // Sort the array in ascending order
    sort(A.begin(), A.end());
    
    // Initialize variables to store the minimum difference found
    int min_diff = INT_MAX;
    
    // Calculate differences for all possible windows
    for (int i = 0; i <= N - K; i++) {
        int max_val = A[i + K - 1];
        int min_val = A[i];
        min_diff = min(min_diff, max_val - min_val);
    }
    
    // Output the minimum difference
    cout << min_diff << endl;
    
    return 0;
}