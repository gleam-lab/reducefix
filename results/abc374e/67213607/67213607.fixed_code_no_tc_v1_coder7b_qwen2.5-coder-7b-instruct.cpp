#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 105;
const int MAX_X = 1e7 + 5;

int n, x, a[MAX_N], p[MAX_N], b[MAX_N], q[MAX_N];

// Function to check if it's possible to achieve at least 'capacity' products per day
bool isFeasible(int capacity) {
    long long totalCost = 0;
    for (int i = 1; i <= n; ++i) {
        // Calculate the minimum cost to achieve 'capacity' products for process i
        int minCost = LLONG_MAX;
        
        // Try all combinations of machines S_i and T_i
        for (int j = 0; j * a[i] <= capacity; ++j) {
            int remainingProducts = capacity - j * a[i];
            int cost = j * p[i];
            
            if (remainingProducts % b[i] == 0) {
                cost += (remainingProducts / b[i]) * q[i];
            } else {
                cost += ((remainingProducts / b[i]) + 1) * q[i];
            }
            
            minCost = min(minCost, cost);
        }
        
        totalCost += minCost;
    }
    
    return totalCost <= x;
}

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    
    int l = 0, r = 1e7, mid, ans = 0;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (isFeasible(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    
    cout << ans << endl;
    return 0;
}