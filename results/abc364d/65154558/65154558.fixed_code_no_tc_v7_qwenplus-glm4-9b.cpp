#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 200000, INF = 1e9;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N + 1);
    
    // Reading A array and making prefix sums
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }
    
    // Sort B array by coordinate and then by k_j
    vector<pair<int, int>> B(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> B[i].first >> B[i].second;
    }
    sort(B.begin(), B.end());
    
    // Answer for each B_j
    for (auto &b : B) {
        int b_j = b.first;
        int k_j = b.second;
        
        // Binary search to find the k_j-th closest A_i to B_j
        int left = 0, right = N;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            int distance = A[mid] - b_j; // Yes, it is distance, not d_i
            if (distance < 0) {
                left = mid;
            } else {
                right = mid;
            }
        }
        
        // Calculate the k_j-th distance
        int ans = INF;
        for (int i = max(0, left - k_j + 1); i <= min(N - 1, left); ++i) {
            ans = min(ans, abs(A[i] - b_j));
        }
        
        cout << ans << endl;
    }
    
    return 0;
}