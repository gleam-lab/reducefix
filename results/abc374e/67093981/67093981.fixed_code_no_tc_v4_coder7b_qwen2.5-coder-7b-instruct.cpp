#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Machine {
    int a, p, b, q;
};

int N, X;
vector<Machine> machines;
vector<vector<long long>> dp;

// Function to calculate the minimum cost for processing 'n' products using machine i
long long cost(int i, int n) {
    int units = n / (machines[i].a * machines[i].b);
    int remaining = n % (machines[i].a * machines[i].b);
    return dp[i][remaining] + units * machines[i].p * machines[i].b;
}

// Binary search function to maximize production capacity within the budget
int binarySearch() {
    int low = 0, high = 1e9;
    while (high - low > 1) {
        int mid = low + (high - low) / 2;
        bool possible = true;
        for (int i = 0; i < N; ++i) {
            if (cost(i, mid) > X) {
                possible = false;
                break;
            }
        }
        if (possible) {
            low = mid;
        } else {
            high = mid;
        }
    }
    // Check if the upper limit is feasible
    bool possible = true;
    for (int i = 0; i < N; ++i) {
        if (cost(i, high) > X) {
            possible = false;
            break;
        }
    }
    if (possible) return high;
    return low;
}

int main() {
    cin >> N >> X;
    machines.resize(N);
    dp.resize(N, vector<long long>(10001, INT_MAX));

    for (int i = 0; i < N; ++i) {
        cin >> machines[i].a >> machines[i].p >> machines[i].b >> machines[i].q;
        if (machines[i].a * machines[i].q > machines[i].b * machines[i].p)
            swap(machines[i].a, machines[i].b), swap(machines[i].p, machines[i].q);
        dp[i][0] = 0;
        for (int j = 1; j <= machines[i].a * machines[i].b; ++j) {
            dp[i][j] = min(dp[i][max(0, j - machines[i].a)] + machines[i].p, 
                           dp[i][max(0, j - machines[i].b)] + machines[i].q);
        }
    }

    cout << binarySearch() << endl;
    return 0;
}