#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    long long ans = 0;
    unordered_set<int> prefix_sums;
    prefix_sums.insert(0);

    for (int i = 0; i < n; ++i) {
        long long current_sum = accumulate(arr.begin(), arr.begin() + i + 1, 0LL);
        long long target = current_sum % m;
        if (prefix_sums.count(target)) {
            ans += prefix_sums[target];
        }
        prefix_sums.insert((current_sum + m) % m); // To handle negative sums
    }

    cout << ans << endl;
    return 0;
}