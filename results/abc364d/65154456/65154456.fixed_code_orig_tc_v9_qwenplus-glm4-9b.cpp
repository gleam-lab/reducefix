#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> // For std::setw in output formatting

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    // Step 1: Create a vector to store all points A_i
    vector<long long> pointsA(n);
    for (int i = 0; i < n; ++i) {
        cin >> pointsA[i];
    }
    
    // Step 2: Create a 2D vector to store distances from each A_i to each B_j
    vector<vector<long long>> distances(n + 1, vector<long long>(q + 1));
    
    // Step 3: Calculate distances between A_i and B_j
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= q; ++j) {
            int bj, kj;
            cin >> bj >> kj;
            distances[i + 1][j] = abs(pointsA[i] - bj);
        }
    }
    
    // Step 4: Output the k_j-th smallest distance for each B_j
    for (int j = 1; j <= q; ++j) {
        // Extract distances for point B_j
        vector<long long> bDistances(distances[1][j], distances[n][j]);
        
        // Sort the distances
        sort(bDistances.begin(), bDistances.end());
        
        // Output the k_j-th smallest distance
        cout << bDistances[j] << endl; // j is 1-indexed, so directly use it
    }
    
    return 0;
}