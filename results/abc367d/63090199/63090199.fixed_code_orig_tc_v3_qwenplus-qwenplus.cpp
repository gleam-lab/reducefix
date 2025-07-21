#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    // Map to count remainders of prefix sums modulo m
    map<int, long long> remainder_count;
    long long count = 0;
    long long prefix_sum = 0;

    // Initial zero remainder for empty prefix sum
    remainder_count[0] = 1;

    for (int i = 0; i < n; ++i) {
        prefix_sum = (prefix_sum + nums[i]) % m;
        count += remainder_count[prefix_sum];
        remainder_count[prefix_sum]++;
    }

    cout << count << endl;
    return 0;
}