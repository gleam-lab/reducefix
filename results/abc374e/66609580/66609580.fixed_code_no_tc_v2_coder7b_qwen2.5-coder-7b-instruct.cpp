#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool check(const vector<vector<int>>& machines, const vector<int>& capacities, int budget) {
    int n = machines.size();
    int max_capacity = INT_MIN;
    
    // Iterate over all possible combinations of machines for each process
    for (int mask = 0; mask < (1 << n); ++mask) {
        long long cost = 0;
        long long production = 0;
        
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                cost += machines[i][1]; // Cost of machine T_i
                production += machines[i][0]; // Production rate of machine T_i
            } else {
                cost += machines[i][3]; // Cost of machine S_i
                production += machines[i][2]; // Production rate of machine S_i
            }
        }
        
        // Check if the current combination fits within the budget
        if (cost <= budget) {
            // Update the maximum production capacity
            max_capacity = max(max_capacity, static_cast<int>(production));
        }
    }
    
    // Return true if the maximum capacity is greater than or equal to the required capacity
    return max_capacity >= capacities.back();
}

int main() {
    int n, x;
    cin >> n >> x;
    
    vector<vector<int>> machines(n, vector<int>(4));
    vector<int> capacities(n + 1);
    
    // Read the input data
    for (int i = 0; i < n; ++i) {
        cin >> machines[i][0] >> machines[i][1] >> machines[i][2] >> machines[i][3];
        capacities[i] = min(machines[i][0], machines[i][2]);
    }
    
    capacities[n] = 0; // Sentinel value
    
    // Binary search for the maximum production capacity
    int left = 0, right = 1e9;
    while (left < right) {
        int mid = (left + right + 1) / 2;
        if (check(machines, capacities, mid)) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    
    cout << left << endl;
    
    return 0;
}