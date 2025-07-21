#include<bits/stdc++.h>
using namespace std;

struct Machine {
    int a, p, b, q;
};

bool feasible(vector<Machine>& machines, int mid, long long budget) {
    long long cost = 0;
    for(auto& m : machines) {
        int units_S = min(mid / m.a, mid / m.b); // Calculate the number of units of S and T machines needed
        int units_T = mid / m.b;
        long long cost_S = units_S * m.p;
        long long cost_T = units_T * m.q;
        cost += cost_S + cost_T;
        if(cost > budget) return false; // If cost exceeds budget, not feasible
    }
    return true;
}

int main() {
    int n;
    long long x;
    cin >> n >> x;
    vector<Machine> machines(n);
    for(int i = 0; i < n; ++i) {
        cin >> machines[i].a >> machines[i].p >> machines[i].b >> machines[i].q;
    }

    int l = 0, r = 1e7; // Binary search range
    while(l < r) {
        int mid = l + (r - l + 1) / 2; // Midpoint calculation
        if(feasible(machines, mid, x)) {
            l = mid; // If feasible, try for higher production capacity
        } else {
            r = mid - 1; // If not feasible, reduce production capacity
        }
    }

    cout << l << endl; // Output the maximum achievable production capacity
    return 0;
}