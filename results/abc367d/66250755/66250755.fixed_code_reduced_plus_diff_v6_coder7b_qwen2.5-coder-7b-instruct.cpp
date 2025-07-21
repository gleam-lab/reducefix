#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    unordered_map<int, int> prefix_sum_count;
    prefix_sum_count[0] = 1; // Initialize with one occurrence of prefix sum 0
    long long an = 0;
    int current_sum = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        current_sum = (current_sum + a[i]) % m;
        if (prefix_sum_count.find(current_sum) != prefix_sum_count.end()) {
            an += prefix_sum_count[current_sum];
        }
        prefix_sum_count[current_sum]++;
    }

    cout << an << endl;
    return 0;
}