#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    int total_sum = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] %= m;
        total_sum = (total_sum + a[i]) % m;
    }

    unordered_map<int, int> counts;
    int current_sum = 0;
    int target = (total_sum + m) % m; // Adjust target to handle wrap-around

    for (int i = 0; i < n; ++i) {
        current_sum = (current_sum + a[i]) % m;
        counts[current_sum]++;
    }

    int result = 0;
    for (auto& p : counts) {
        result += p.second; // Each sum occurrence contributes to the result
        // Remove current sum from the set of sums that contribute to the result
        if (p.first == target) {
            result -= p.second;
        }
    }

    cout << result << endl;
    return 0;
}