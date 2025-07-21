#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &val : v) {
        cin >> val;
    }

    sort(v.begin(), v.end());

    int ans = v[n-k] - v[k-1];
    cout << ans << endl;

    return 0;
}