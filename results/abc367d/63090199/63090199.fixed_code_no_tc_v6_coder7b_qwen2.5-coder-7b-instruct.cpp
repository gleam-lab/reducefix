#include<bits/stdc++.h>
using namespace std;

int n, m;
int main() {
    cin >> n >> m;
    vector<int> nums(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
        nums[i] += nums[i - 1]; // Correctly compute the prefix sum
    }

    int count = 0;
    for (int s = 1; s <= n; ++s) {
        for (int t = s; t <= n; ++t) { // Start t from s to avoid duplicate counting
            int step = nums[t] - nums[s - 1];
            if (step % m == 0) {
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}