#include<bits/stdc++.h>
using namespace std;

struct Machine {
    int type;
    double rate;
    double cost;
};

bool compare(Machine m1, Machine m2) {
    return (m1.rate / m1.cost) > (m2.rate / m2.cost);
}

int main() {
    int n, x;
    cin >> n >> x;
    
    vector<Machine> machines(n * 2);
    for (int i = 0; i < n; ++i) {
        int a, p, b, q;
        cin >> a >> p >> b >> q;
        machines[i * 2].type = 1; // Type S
        machines[i * 2].rate = a;
        machines[i * 2].cost = p;
        
        machines[i * 2 + 1].type = 2; // Type T
        machines[i * 2 + 1].rate = b;
        machines[i * 2 + 1].cost = q;
    }
    
    sort(machines.begin(), machines.end(), compare);
    
    double ans = 0;
    double budget = x;
    
    for (auto &machine : machines) {
        if (budget >= machine.cost) {
            budget -= machine.cost;
            ans += machine.rate;
        } else break;
    }
    
    cout << static_cast<int>(ans) << endl;
    
    return 0;
}