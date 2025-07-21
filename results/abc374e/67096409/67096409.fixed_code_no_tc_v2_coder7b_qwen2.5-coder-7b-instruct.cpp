#include <iostream>
#include <algorithm>
using namespace std;

struct Machine {
    int a, p, b, q; // a: products per day, p: cost per unit, b: products per day, q: cost per unit
};

Machine machines[100]; // Array to store machine details
long long dp[100][10001]; // DP table to store minimum cost for given remainder

// Function to calculate cost for processing 'n' products using current machine
long long cost(int index, int n) {
    int max_products_per_day = max(machines[index].a, machines[index].b);
    int units_needed = n / max_products_per_day + (n % max_products_per_day != 0);
    return dp[index][n % max_products_per_day] + units_needed * min(machines[index].p, machines[index].q);
}

// Binary search function to maximize production capacity within given budget
int binarySearch(int low, int high, int budget) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        bool possible = true;
        for (int i = 0; i < N; ++i) {
            if (cost(i, mid) > budget) {
                possible = false;
                break;
            }
        }
        if (possible) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return high;
}

int main() {
    int N, X;
    cin >> N >> X;

    for (int i = 0; i < N; ++i) {
        cin >> machines[i].a >> machines[i].p >> machines[i].b >> machines[i].q;
        if (machines[i].a * machines[i].q < machines[i].b * machines[i].p)
            swap(machines[i].a, machines[i].b), swap(machines[i].p, machines[i].q); // Ensure lower cost per product

        dp[i][0] = 0;
        for (int j = 1; j <= 10000; ++j) {
            dp[i][j] = min(dp[i][(j - machines[i].a + 10000) % 10000] + machines[i].p,
                           dp[i][(j - machines[i].b + 10000) % 10000] + machines[i].q);
        }
    }

    cout << binarySearch(0, 10000, X) << endl;
    return 0;
}