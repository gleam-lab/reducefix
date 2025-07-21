#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<pair<long long, long long>> AB(N);
        for (int i = 0; i < N; i++) {
            cin >> AB[i].first >> AB[i].second;
        }
        
        // Sort pairs by their product in descending order
        sort(AB.begin(), AB.end(), [](const pair<long long, long long>& a, const pair<long long, long long>& b) {
            return a.first * a.second > b.first * b.second;
        });
        
        long long min_value = LLONG_MAX;
        long long sum_B = 0;
        
        // Evaluate subsets
        for (int i = 0; i < N; i++) {
            if (N - i - 1 >= K - 1) {
                sum_B += AB[i].second;
                long long max_A = AB[i].first;
                long long current_value = max_A * sum_B;
                min_value = min(min_value, current_value);
            }
        }
        
        cout << min_value << '\n';
    }
    return 0;
}