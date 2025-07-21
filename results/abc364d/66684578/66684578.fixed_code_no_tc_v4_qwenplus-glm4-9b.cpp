#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    vector<pair<int, int>> queries(Q);
    for (int i = 0; i < Q; ++i) {
        int b, k;
        cin >> b >> k;
        queries[i] = {b, k};
    }
    
    // Sort the points A for binary search
    sort(A.begin(), A.end());
    
    // Prepare a map to count occurrences of each point in A
    map<int, int> countMap;
    for (int a : A) {
        countMap[a]++;
    }
    
    // Prepare to answer all queries
    for (auto &query : queries) {
        int b = query.first, k = query.second;
        
        // Find the k-th closest point to b
        int left = lower_bound(A.begin(), A.end(), b) - A.begin();
        int right = left + k - 1;
        
        // Check if the k-th closest point is within the range
        if (right < N && A[right] == b) {
            cout << 0 << endl; // The k-th closest point is exactly b, distance is 0
        } else {
            // Calculate the distance to the closest point
            int distance;
            if (right >= 0) {
                int closestPoint = A[right];
                distance = abs(closestPoint - b);
            } else {
                // All points are to the right of b, take the leftmost point
                int closestPoint = A[left - 1];
                distance = abs(closestPoint - b);
            }
            cout << distance << endl;
        }
    }
    
    return 0;
}