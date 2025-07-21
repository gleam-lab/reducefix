#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    
    // Read the coordinates of points A
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Prepare a map to count occurrences of each point
    vector<int> counts(2 * 10e8 + 1, 0);
    for (int coord : A) {
        counts[coord]++;
    }
    
    // Process each query
    for (int j = 0; j < Q; ++j) {
        int B, kj;
        cin >> B >> kj;
        
        // Calculate the distance to B for each point A
        vector<int> distances(N);
        for (int i = 0; i < N; ++i) {
            distances[i] = abs(B - A[i]);
        }
        
        // Sort distances and find the kj-th smallest one
        sort(distances.begin(), distances.end());
        int ans = distances[kj - 1];
        
        cout << ans << endl;
    }
    
    return 0;
}