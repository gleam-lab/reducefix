#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canAchieveCapacity(const vector<int>& A, const vector<int>& P, const vector<int>& B, const vector<int>& Q, long long X, int targetCapacity) {
    for (size_t i = 0; i < A.size(); ++i) {
        long long costS = 0, costT = 0;
        // Try using machine S_i up to its maximum capacity
        for (long long s = 0; s <= B[i]; ++s) {
            long long remaining = max(0LL, targetCapacity - A[i] * s);
            long long t = (remaining + B[i] - 1) / B[i];
            costS = min(costS, s * P[i] + t * Q[i]);
        }
        // Try using machine T_i up to its maximum capacity
        for (long long t = 0; t <= A[i]; ++t) {
            long long remaining = max(0LL, targetCapacity - B[i] * t);
            long long s = (remaining + A[i] - 1) / A[i];
            costT = min(costT, t * Q[i] + s * P[i]);
        }
        // Check if we can afford the cheaper option
        if (costS > X && costT > X) {
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    long long X;
    cin >> N >> X;
    vector<int> A(N), P(N), B(N), Q(N);

    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    int left = 0, right = 1e9 + 1; // Initialize binary search bounds

    while (left < right) {
        int mid = (left + right) / 2;
        if (canAchieveCapacity(A, P, B, Q, X, mid)) {
            left = mid + 1; // Try for a higher capacity
        } else {
            right = mid; // Try for a lower capacity
        }
    }

    cout << left - 1 << endl; // The maximum achievable capacity within budget X

    return 0;
}