#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<pair<int, int>> AB(N);
        for (int i = 0; i < N; i++) {
            cin >> AB[i].first;
            cin >> AB[i].second;
        }

        // Sort by A_i in descending order
        sort(AB.begin(), AB.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });

        long long sum_B = 0;
        long long result = numeric_limits<long long>::max();

        // Calculate sum of B_i for the last K elements
        for (int i = N - K; i < N; i++) {
            sum_B += AB[i].second;
        }

        // Calculate the result using the last K elements
        for (int i = N - K; i < N; i++) {
            result = min(result, (long long)AB[i].first * sum_B);
        }

        cout << result << endl;
    }

    return 0;
}