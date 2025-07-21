#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num.begin(), num.end());
    int window_size = n - k;
    int min_diff = INT_MAX;
    for (int i = 0; i + window_size <= n; i++) {
        min_diff = min(min_diff, num[i + window_size - 1] - num[i]);
    }
    cout << min_diff << endl;
}