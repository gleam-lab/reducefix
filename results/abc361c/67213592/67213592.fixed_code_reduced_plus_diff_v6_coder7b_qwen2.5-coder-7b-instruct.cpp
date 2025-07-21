#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (auto& val : v) {
        cin >> val;
    }

    sort(v.begin(), v.end());

    int result = v[n-k] - v[k-1];
    
    cout << result << '\n';

    return 0;
}