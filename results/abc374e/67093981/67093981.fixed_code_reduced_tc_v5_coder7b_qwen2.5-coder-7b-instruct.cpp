#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Machine {
    int a, p, b, q;
};

vector<Machine> machines;
long long dp[101][10001];

long long cost(int i, int n) {
    long long d = n / (machines[i].a * machines[i].b);
    int rem = n % (machines[i].a * machines[i].b);
    return dp[i][rem] + d * machines[i].p * machines[i].b;
}

bool feasible(long long n) {
    long long total_cost = 0;
    for (int i = 0; i < machines.size(); ++i) {
        total_cost += cost(i, n);
        if (total_cost > X) return false;
    }
    return true;
}

int main() {
    int N, X;
    cin >> N >> X;

    machines.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> machines[i].a >> machines[i].p >> machines[i].b >> machines[i].q;
        if (machines[i].a * machines[i].q > machines[i].b * machines[i].p)
            swap(machines[i].a, machines[i].b), swap(machines[i].p, machines[i].q);
        dp[i][0] = 0;
        for (int j = 1; j <= machines[i].a * machines[i].b; ++j) {
            dp[i][j] = min(dp[i][max(0, j - machines[i].a)] + machines[i].p, dp[i][max(0, j - machines[i].b)] + machines[i].q);
        }
    }

    int low = 0, high = 1e9;
    while (low < high) {
        int mid = low + (high - low + 1) / 2;
        if (feasible(mid)) low = mid;
        else high = mid - 1;
    }

    cout << low << endl;
    return 0;
}