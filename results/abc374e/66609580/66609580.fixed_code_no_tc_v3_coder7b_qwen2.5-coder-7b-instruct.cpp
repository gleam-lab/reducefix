#include <bits/stdc++.h>
using namespace std;

bool check(long long v, vector<vector<int>>& machines, long long budget) {
    long long total_cost = 0;
    for(auto& machine : machines) {
        int A = machine[0], B = machine[1], P = machine[2], Q = machine[3];
        long long units_S = max(0LL, (v / A) - 1);
        long long units_T = max(0LL, (v / B) - 1);
        long long cost_S = units_S * P;
        long long cost_T = units_T * Q;
        if(cost_S + cost_T > budget) {
            units_S = max(0LL, (budget / Q) - 1);
            units_T = max(0LL, ((budget - units_S * Q) / P));
        }
        total_cost += cost_S + cost_T;
        v -= units_S * A + units_T * B;
        if(v < 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n; long long x;
    cin >> n >> x;
    
    vector<vector<int>> machines(n);
    for(int i = 0; i < n; ++i) {
        cin >> machines[i][0] >> machines[i][2] >> machines[i][1] >> machines[i][3];
    }
    
    long long left = 0, right = 1e9 + 7, ans = 0;
    while(left <= right) {
        long long mid = left + (right - left) / 2;
        if(check(mid, machines, x)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}