#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Machine {
    int a, p, b, q;
};

int N, X;
vector<Machine> machines;

// Function to calculate the minimum cost to produce at least 'n' products for a given process
long long minCost(int processIndex, int n) {
    int a = machines[processIndex].a, b = machines[processIndex].b, p = machines[processIndex].p, q = machines[processIndex].q;
    long long dp[a * b + 1];
    fill(dp, dp + a * b + 1, LLONG_MAX);
    dp[0] = 0;
    
    for (int i = 0; i <= a * b; ++i) {
        if (dp[i] == LLONG_MAX) continue;
        
        if (i + a <= a * b) dp[i + a] = min(dp[i + a], dp[i] + p);
        if (i + b <= a * b) dp[i + b] = min(dp[i + b], dp[i] + q);
    }
    
    long long minCost = LLONG_MAX;
    for (int i = max(n - b, 0); i <= a * b; i += a) {
        minCost = min(minCost, dp[i]);
    }
    return minCost;
}

int main() {
    cin >> N >> X;
    machines.resize(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> machines[i].a >> machines[i].p >> machines[i].b >> machines[i].q;
    }
    
    // Binary search for the maximum production capacity
    int low = 0, high = X / (machines[0].a + machines[0].b);
    while (low < high) {
        int mid = (low + high + 1) / 2;
        bool feasible = true;
        for (int i = 0; i < N; ++i) {
            if (minCost(i, mid) > X) {
                feasible = false;
                break;
            }
        }
        if (feasible) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    
    cout << low << endl;
    return 0;
}