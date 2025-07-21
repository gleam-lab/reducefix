#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

bool canAchieveProcessingCapacity(const vector<int>& A, const vector<int>& B, const vector<int>& P, const vector<int>& Q, int X, int target) {
    for (size_t i = 0; i < A.size(); ++i) {
        int max_s = (target + A[i] - 1) / A[i];
        int min_val = INT_MAX;
        
        for (int s = 0; s <= max_s; ++s) {
            int remaining_capacity = target - s * A[i];
            int t = (remaining_capacity + B[i] - 1) / B[i];
            min_val = min(min_val, s * P[i] + t * Q[i]);
        }
        
        if (min_val == INT_MAX || min_val > X) {
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    int X;
    cin >> N >> X;
    
    vector<int> A(N), B(N), P(N), Q(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i] >> P[i] >> Q[i];
    }
    
    int lb = 0, ub = INT_MAX;
    
    while (ub - lb > 1) {
        int mid = lb + (ub - lb) / 2;
        if (canAchieveProcessingCapacity(A, B, P, Q, X, mid)) {
            ub = mid;
        } else {
            lb = mid;
        }
    }
    
    cout << ub << endl;
    return 0;
}