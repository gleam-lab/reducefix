#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    
    vector<long long> nums(n);
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<long long> prefix_sum(n + 1, 0);
    for(int i = 0; i < n; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + nums[i];
    }

    long long count = 0;
    for(int s = 0; s < n; ++s) {
        for(int t = s + 1; t <= n; ++t) {
            long long step = prefix_sum[t] - prefix_sum[s];
            if(step % m == 0) {
                ++count;
            }
        }
    }

    cout << count << '\n';

    return 0;
}