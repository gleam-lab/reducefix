#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    
    // Read and store A values
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Process each query
    for (int q = 0; q < Q; ++q) {
        int B, k;
        cin >> B >> k;
        
        // Calculate distances from A to B
        vector<int> distances(N);
        for (int i = 0; i < N; ++i) {
            distances[i] = abs(A[i] - B);
        }
        
        // Sort distances and get the k-th smallest
        sort(distances.begin(), distances.end());
        int result = distances[k - 1]; // k-th element in 1-indexed array
        
        // Output the result
        cout << result << endl;
    }
    
    return 0;
}