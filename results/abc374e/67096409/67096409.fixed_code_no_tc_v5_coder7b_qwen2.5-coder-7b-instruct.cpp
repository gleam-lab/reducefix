#include <iostream>
#include <algorithm>
using namespace std;

struct Machine {
    int a, p, b, q;
};

Machine machines[100];
long long dp[100][10001];

int N, X;

long long cost(int i, int n) {
    long long units = n / (machines[i].a * machines[i].b);
    int remaining = n % (machines[i].a * machines[i].b);
    return dp[i][remaining] + units * machines[i].p * machines[i].b;
}

bool feasible(long long capacity) {
    long long totalCost = 0;
    for (int i = 0; i < N; ++i) {
        totalCost += cost(i, capacity);
        if (totalCost > X) return false;
    }
    return true;
}

int main() {
    cin >> N >> X;

    for (int i = 0; i < N; ++i) {
        cin >> machines[i].a >> machines[i].p >> machines[i].b >> machines[i].q;
        if (machines[i].a * machines[i].q < machines[i].b * machines[i].p)
            swap(machines[i].a, machines[i].b), swap(machines[i].p, machines[i].q);
        dp[i][0] = 0;
        for (int j = 1; j <= 10000; ++j) {
            dp[i][j] = min(dp[i][max(0, j - machines[i].a)], dp[i][max(0, j - machines[i].b)]) + min(machines[i].p, machines[i].q);
        }
    }

    int low = 0, high = X;
    while (low < high) {
        int mid = (low + high + 1) / 2;
        if (feasible(mid)) low = mid;
        else high = mid - 1;
    }

    cout << low << endl;
}