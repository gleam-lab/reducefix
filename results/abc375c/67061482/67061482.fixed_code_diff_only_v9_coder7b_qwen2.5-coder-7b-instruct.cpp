#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // Disable synchronization with C I/O streams
    cin.tie(nullptr); // Untie cin from cout to improve performance

    long long a = 0, b = 0, c, d;
    int N;
    cin >> N;

    long long total_cost = 0;
    for (int i = 0; i < N; ++i) {
        cin >> c >> d;
        total_cost += abs(c - a) + abs(d - b); // Using Manhattan distance instead of Euclidean to avoid floating-point precision issues
        a = c;
        b = d;
    }

    total_cost += abs(a) + abs(b); // Return to the origin using Manhattan distance
    cout << total_cost << endl;

    return 0;
}