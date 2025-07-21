#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(n), prefix_sum(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] %= m;
        prefix_sum[i] = (prefix_sum[i-1] + a[i]) % m;
    }

    unordered_map<int, int> count;
    long long ans = 0;
    for(int i = 0; i < n; ++i) {
        if(count.find((prefix_sum[i] * 2) % m) != count.end()) {
            ans += count[(prefix_sum[i] * 2) % m];
        }
        if(count.find(prefix_sum[i]) != count.end()) {
            count[prefix_sum[i]]++;
        } else {
            count[prefix_sum[i]] = 1;
        }
    }

    cout << ans << '\n';

    return 0;
}