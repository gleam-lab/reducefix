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
    int del = k / 2;
    int md = k % 2;
    int st = del;
    int gl = (n - 1) - del;
    
    // Corrected calculation of the result based on whether k is odd or even
    int ans = md ? min(num[gl] - num[st], num[gl - 1] - num[st]) : num[gl] - num[st];
    cout << ans << endl;
}