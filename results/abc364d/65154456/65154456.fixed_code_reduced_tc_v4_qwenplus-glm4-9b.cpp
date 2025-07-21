#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    vector<pair<long long, int>> queries(Q);
    for (int i = 0; i < Q; ++i) {
        long long b; int kj;
        cin >> b >> kj;
        queries[i] = { kj, b };
    }
    
    // Sort queries based on b_j (the coordinates of B_j)
    sort(queries.begin(), queries.end());
    
    // Sort A based on the coordinates, so we can find the closest A_i for each B_j
    sort(A.begin(), A.end());
    
    // Result vector
    vector<long long> results(Q);
    
    // We will iterate through sorted A and find the closest A_i for each B_j
    long long cur_dist = 0, count = 0;
    for (const auto& q : queries) {
        while (count < N && A[count] < queries[q.second].first) {
            cur_dist = A[count] - queries[q.second].first;
            count++;
        }
        results[q.second - 1] = cur_dist;
    }
    
    // Output the results
    for (const auto& res : results) {
        cout << res << endl;
    }
    
    return 0;
}