#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> nums(n + 1, 0);
    for(int i = 1; i <= n; ++i) {
        cin >> nums[i];
        nums[i] += nums[i - 1]; // Calculate prefix sum
    }

    long long count = 0;
    unordered_map<int, int> remainder_count;
    remainder_count[0] = 1; // Base case

    for(int i = 1; i <= n; ++i) {
        int remainder = nums[i] % m;
        if(remainder_count.find((remainder - m) % m) != remainder_count.end()) {
            count += remainder_count[(remainder - m) % m];
        }
        remainder_count[remainder]++;
    }

    cout << count << endl;
    return 0;
}