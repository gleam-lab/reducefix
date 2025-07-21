#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> A(n), B(q), distances;
    
    // Reading the coordinates of points A
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    
    // Reading the points B and k_j
    for (int i = 0; i < q; ++i) {
        cin >> B[i] >> distances[i]; // Store distance directly
    }
    
    // For each point B_j, calculate the distance to the k_j-th closest point in A
    for (int j = 0; j < q; ++j) {
        vector<int> distances_to_Bj;
        
        // Calculate the absolute distance from each point in A to B_j
        for (int a : A) {
            distances_to_Bj.push_back(abs(a - B[j]));
        }
        
        // Sort the distances
        sort(distances_to_Bj.begin(), distances_to_Bj.end());
        
        // Get the k_j-th closest distance
        cout << distances_to_Bj[distances[j] - 1] << '\n'; // distances[j] is 1-based index
    }
    
    return 0;
}