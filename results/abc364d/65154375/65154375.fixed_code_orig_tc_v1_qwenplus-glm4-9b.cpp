#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    
    vector<int> A(N + 1);  // Using a vector to store the points
    
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    
    vector<pair<int, int>> queries(Q);
    for (int i = 0; i < Q; i++) {
        int b, k;
        cin >> b >> k;
        queries[i] = {b, k};
    }
    
    // Sort the queries by point B
    sort(queries.begin(), queries.end());
    
    for (auto& [b, k] : queries) {
        // Find the k-th closest point A
        // This is a linear search approach for simplicity
        vector<int> distances(N);
        for (int i = 1; i <= N; i++) {
            distances[i - 1] = abs(b - A[i]);
        }
        
        // Sort and get the k-th closest distance
        sort(distances.begin(), distances.end());
        cout << distances[k - 1] << endl;
    }
    
    return 0;
}