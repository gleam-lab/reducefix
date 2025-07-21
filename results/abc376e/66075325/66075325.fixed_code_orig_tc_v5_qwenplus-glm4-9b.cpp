#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 200005

vector<int> A, B;

long long solve(int n, int k) {
    vector<pair<int, int>> AxB;

    // Pair each element of A with its corresponding index in B
    for (int i = 0; i < n; i++) {
        AxB.push_back({A[i], B[i]});
    }

    // Sort by A_i descending
    sort(AxB.begin(), AxB.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first;
    });

    // Calculate the minimum possible value
    long long min_value = LLONG_MAX;

    // We only need to consider the top k elements
    for (int i = 0; i < k; i++) {
        long long sum_B = 0;
        for (int j = 0; j < n; j++) {
            sum_B += (i == j) ? AxB[j].second : 0;
        }
        min_value = min(min_value, AxB[i].first * sum_B);
    }

    return min_value;
}

int main() {
    int t, n, k;

    cin >> t;

    while (t--) {
        cin >> n >> k;

        A.resize(n);
        B.resize(n);

        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> B[i];
        }

        cout << solve(n, k) << endl;
    }

    return 0;
}