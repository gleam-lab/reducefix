#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<long long> nums(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
        nums[i] += nums[i - 1]; // Convert to prefix sum array
    }

    long long count = 0;
    for (int s = 1; s <= n; ++s) {
        for (int t = s + 1; t <= n; ++t) {
            long long step = nums[t] - nums[s - 1];
            if (step % m == 0) {
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}