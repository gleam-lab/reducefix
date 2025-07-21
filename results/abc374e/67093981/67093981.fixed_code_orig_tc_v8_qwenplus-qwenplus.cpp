#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

struct Machine {
    int a, p, b, q;
};

int main() {
    int N;
    ll X;
    cin >> N >> X;

    vector<Machine> machines(N);
    for (int i = 0; i < N; ++i) {
        cin >> machines[i].a >> machines[i].p >> machines[i].b >> machines[i].q;
        // Ensure a <= b and corresponding costs are matched
        if (machines[i].a > machines[i].b) {
            swap(machines[i].a, machines[i].b);
            swap(machines[i].p, machines[i].q);
        }
    }

    auto isPossible = [&](ll needed) -> bool {
        ll total_cost = 0;
        for (const auto& m : machines) {
            int a = m.a, p = m.p, b = m.b, q = m.q;
            // Try all possible combinations of type A and type B tablets that satisfy a*x + b*y >= needed
           	ll min_cost = 1e18;
            // Only check up to needed/a possibilities since x <= needed/a
            for (int x = 0; x <= needed / a + 1; ++x) {
                ll remaining = max(0LL, needed - 1LL * a * x);
                ll y = (remaining + b - 1) / b; // ceil division
                ll cost = 1LL * x * p + 1LL * y * q;
                min_cost = min(min_cost, cost);
                if (cost > X) break; // Further increases in x will only increase cost
            }
            total_cost += min_cost;
            if (total_cost > X) return false;
        }
        return true;
    };

    ll low = 0, high = 1e18;
    while (low < high) {
        ll mid = (low + high + 1) / 2;
        if (isPossible(mid)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }

    cout << low << endl;
}