#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end()); // Sort the array A to facilitate binary search
    
    vector<pair<int, int>> queries(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> queries[i].first >> queries[i].second;
    }
    
    // Map to count occurrences of each element in A
    vector<int> count(A.size());
    count[0] = 1;
    for (int i = 1; i < A.size(); ++i) {
        count[i] = count[i - 1] + (A[i] == A[i - 1] ? 1 : 0);
    }
    
    // Sort queries by the point B_j
    sort(queries.begin(), queries.end());
    
    // Process each query
    for (const auto& query : queries) {
        int b = query.first;
        int k = query.second;
        
        // Binary search to find the k-th closest point
        int low = 0, high = A.size() - 1;
        while (low < high) {
            int mid = low + (high - low + 1) / 2;
            if (A[mid] >= b - k) {
                high = mid;
            } else {
                low = mid;
            }
        }
        
        // Calculate the distance to the k-th closest point
        int closestPoint = A[low];
        int distance = abs(b - closestPoint);
        cout << distance << '\n';
    }
    
    return 0;
}