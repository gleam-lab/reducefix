#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Function to check if we can achieve at least 'capacity' with the given budget
bool canAchieveCapacity(int N, ll X, const vector<int>& A, const vector<int>& P, const vector<int>& B, const vector<int>& Q, int capacity) {
    ll totalCost = 0;
    for (int i = 0; i < N; ++i) {
        // Calculate the optimal number of S_i and T_i machines for process i
        int x = max(0, (capacity + A[i] - 1) / A[i]); // Number of S_i machines needed
        int y = max(0, (capacity + B[i] - 1) / B[i]); // Number of T_i machines needed
        
        // Calculate the actual production capacity with these machines
        int produced = x * A[i] + y * B[i];
        
        // Calculate the cost for these machines
        ll cost = x * P[i] + y * Q[i];
        
        // Add the cost to the total cost
        totalCost += cost;
        
        // If the total cost exceeds the budget, return false
        if (totalCost > X) {
            return false;
        }
    }
    
    // If we reach here, it means we can achieve the capacity with the given budget
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll X;
    cin >> N >> X;
    vector<int> A(N), P(N), B(N), Q(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    // Binary search for the maximum achievable capacity
    int lo = 0, hi = 1000000000;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (canAchieveCapacity(N, X, A, P, B, Q, mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    cout << lo << "\n";
    return 0;
}