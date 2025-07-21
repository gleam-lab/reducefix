#include <iostream>
#include <algorithm>
using namespace std;

struct Machine {
    int a, p, b, q;
};

Machine machines[100];
long long dp[100][10001];

int N, X;

// Function to calculate the cost for a given number of products
long long cost(int process, int numProducts) {
    int units = numProducts / (machines[process].a * machines[process].b);
    int remaining = numProducts % (machines[process].a * machines[process].b);
    return dp[process][remaining] + units * machines[process].p * machines[process].b;
}

// Binary search function to find the maximum achievable production capacity
int binarySearch() {
    int low = 0, high = 1e9;
    while (high - low > 1) {
        int mid = (low + high) >> 1;
        bool feasible = true;
        for (int i = 0; i < N; ++i) {
            if (cost(i, mid) > X) {
                feasible = false;
                break;
            }
        }
        if (feasible) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    // Check if high is feasible
    bool feasibleHigh = true;
    for (int i = 0; i < N; ++i) {
        if (cost(i, high) > X) {
            feasibleHigh = false;
            break;
        }
    }
    if (feasibleHigh) {
        return high;
    }
    return low;
}

int main() {
    cin >> N >> X;
    for (int i = 0; i < N; ++i) {
        cin >> machines[i].a >> machines[i].p >> machines[i].b >> machines[i].q;
        if (machines[i].a * machines[i].q < machines[i].b * machines[i].p) {
            swap(machines[i].a, machines[i].b);
            swap(machines[i].p, machines[i].q);
        }
        dp[i][0] = 0;
        for (int j = 1; j <= 10000; ++j) {
            dp[i][j] = min(dp[i][max(0, j - machines[i].a)], dp[i][max(0, j - machines[i].b)]) + min(machines[i].p, machines[i].q);
        }
    }
    cout << binarySearch() << endl;
    return 0;
}