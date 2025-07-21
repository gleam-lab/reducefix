#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <limits>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<int> a(n);
    map<int, int> freq;
    
    // Read and store all points A into the map
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        freq[a[i]]++;
    }
    
    while (q--) {
        int b, k;
        cin >> b >> k;
        
        // Calculate the distance of each point in A from B
        vector<pair<int, int>> distances;
        for (int point : a) {
            distances.emplace_back(abs(point - b), point);
        }
        
        // Sort the vector of distances
        sort(distances.begin(), distances.end());
        
        // Find the k-th closest point's distance to B
        int distance = distances[k - 1].first;
        
        // Output the distance
        cout << distance << endl;
    }
    
    return 0;
}