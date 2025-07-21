#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2 * 1e5 + 10;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(n), prefix_sum(n + 1, 0);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        prefix_sum[i + 1] = (prefix_sum[i] + a[i]) % m;
    }

    unordered_map<int, int> count;
    int result = 0;
    for(int i = 0; i <= n; ++i) {
        if(count.find(prefix_sum[i]) != count.end()) {
            result += count[prefix_sum[i]];
        }
        count[prefix_sum[i]]++;
    }

    cout << result << endl;

    return 0;
}