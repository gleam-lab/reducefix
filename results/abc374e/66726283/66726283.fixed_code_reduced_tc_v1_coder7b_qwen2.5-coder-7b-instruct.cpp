#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100 + 5;
const long long INF = LLONG_MAX;

struct Machine {
    int a, p, b, q;
};

int n, x;
Machine machines[MAXN];

// Function to calculate the cost of running at least 'capacity' units of a process
long long cost(int process, int capacity) {
    int a = machines[process].a, p = machines[process].p, b = machines[process].b, q = machines[process].q;
    int units_a = (capacity + a - 1) / a; // Ceiling division
    int units_b = (capacity + b - 1) / b; // Ceiling division
    return (long long)units_a * p + (long long)units_b * q;
}

// Binary search for the maximum capacity within the given budget
int binary_search() {
    int left = 0, right = x;
    while (left <= right) {
        int mid = (left + right) / 2;
        bool possible = true;
        for (int i = 1; i <= n; ++i) {
            if (cost(i, mid) > x) {
                possible = false;
                break;
            }
        }
        if (possible) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> machines[i].a >> machines[i].p >> machines[i].b >> machines[i].q;
    }

    cout << binary_search() << '\n';

    return 0;
}