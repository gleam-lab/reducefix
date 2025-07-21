#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<long long> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num.begin(), num.end());
    long long result = LLONG_MAX;
    for(int i = 0; i <= k; ++i) {
        result = min(result, num[n-k+i-1]-num[i]);
    }
    cout << result << endl;
    return 0;
}