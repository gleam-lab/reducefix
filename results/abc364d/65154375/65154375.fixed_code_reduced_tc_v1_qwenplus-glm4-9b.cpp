#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    vector<pair<long long, long long>> queries(q);
    for (int i = 0; i < q; i++) {
        int b, k;
        cin >> b >> k;
        queries[i] = {b, k};
    }
    
    // Sort queries by b to process them in order of the points B
    sort(queries.begin(), queries.end());
    
    // Prepare to compute the number of points between each A_i and B_j
    vector<vector<int>> count(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            count[i][j] = count[i - 1][j] + (a[i] - a[j] <= 0);
        }
    }
    
    // Process each query
    for (auto& q : queries) {
        long long b = q.first;
        long long k = q.second;
        
        // Binary search for the k-th closest point A_i to B_j
        long long low = 0, high = n;
        while (low < high) {
            long long mid = (low + high + 1) / 2;
            long long num_points = count[mid][n];
            if (num_points >= k) {
                high = mid - 1;
            } else {
                low = mid;
            }
        }
        
        // Output the distance between X and B_j
        cout << a[low] - b << endl;
    }
    
    return 0;
}