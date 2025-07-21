#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<long long> a(n), prefix_sum(n + 1);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        prefix_sum[i + 1] = (prefix_sum[i] + a[i]) % m;
    }

    map<int, int> count;
    count[0]++;
    long long result = 0;
    for(int i = 1; i <= n; ++i) {
        result += count[prefix_sum[i]];
        count[prefix_sum[i]]++;
    }

    cout << result << endl;
    return 0;
}