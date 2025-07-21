#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Process {
    int a, b, p, q;
};

bool check(Process proc[], int n, ll budget, ll target_capacity) {
    ll cost_s = 0, cost_t = 0;
    for(int i = 0; i < n; ++i) {
        ll lcm = lcm(proc[i].a, proc[i].b);
        ll units_s = max(0ll, (target_capacity / lcm - 1));
        ll units_t = max(0ll, (target_capacity / lcm - 1));
        
        cost_s += units_s * proc[i].p * (lcm / proc[i].a);
        cost_t += units_t * proc[i].q * (lcm / proc[i].b);

        if(units_s * proc[i].a + units_t * proc[i].b < target_capacity) {
            return false;
        }
    }

    return cost_s + cost_t <= budget;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n; ll budget;
    cin >> n >> budget;
    vector<Process> proc(n);
    
    for(int i = 0; i < n; ++i) {
        cin >> proc[i].a >> proc[i].p >> proc[i].b >> proc[i].q;
    }

    ll left = 0, right = 1e9;
    while(left < right) {
        ll mid = left + (right - left + 1) / 2;
        if(check(proc.data(), n, budget, mid)) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }

    cout << left << "\n";
    return 0;
}