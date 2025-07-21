#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num.begin(), num.end(), greater<int>());
    
    if (k <= n / 2) {
        // If k is less than or equal to half of n, we can directly handle it
        for (int i = n; i - k < n; i--) {
            cout << num[i - k] - num[i] << endl;
            return 0;
        }
    } else {
        // If k is greater than half of n, we need to remove more carefull
        int lo = 0, hi = n - 1;
        for (int i = 0; i < k; i++) {
            if (num[lo] > num[hi]) {
                hi--;
            } else {
                lo++;
            }
        }
        cout << num[hi] - num[lo] << endl;
    }
}