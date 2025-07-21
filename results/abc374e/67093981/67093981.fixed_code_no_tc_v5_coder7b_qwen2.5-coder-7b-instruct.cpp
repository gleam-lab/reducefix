#include <iostream>
#include <algorithm>
using namespace std;

struct Machine {
    int a, p, b, q;
};

Machine machines[100];
long long dp[100][10001];

int N, X;

long long cost(int i, int units) {
    long long d = units / (machines[i].a * machines[i].b);
    long long rem = units % (machines[i].a * machines[i].b);
    return dp[i][rem] + d * max(machines[i].a, machines[i].b);
}

bool feasible(long long units) {
    long long totalCost = 0;
    for (int i = 0; i < N; ++i) {
        totalCost += cost(i, units);
        if (totalCost > X) return false;
    }
    return true;
}

int main() {
    cin >> N >> X;

    for (int i = 0; i < N; ++i) {
        cin >> machines[i].a >> machines[i].p >> machines[i].b >> machines[i].q;
        swap(machines[i].a, machines[i].b);
        swap(machines[i].p, machines[i].q);
        dp[i][0] = 0;
        for (int j = 1; j <= machines[i].a * machines[i].b; ++j) {
            dp[i][j] = min(dp[i][max(0, j - machines[i].a)] + machines[i].p, dp[i][max(0, j - machines[i].b)] + machines[i].q);
        }
    }

    int left = 0, right = 1e9;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (feasible(mid)) left = mid;
        else right = mid - 1;
    }

    if (!feasible(right) && feasible(left)) cout << left << endl;
    else cout << right << endl;

    return 0;
}