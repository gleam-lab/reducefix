#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    
    vector<int> a(n), p(n), b(n), q(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    
    int l = 0, r = 1e9 + 5;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        long long sum = 0;
        
        for (int i = 0; i < n; ++i) {
            int min_cost = INT_MAX;
            for (int j = 0; j <= b[i]; ++j) {
                if ((mid - j * a[i]) >= 0) {
                    min_cost = min(min_cost, (long long)j * p[i]);
                    if ((mid - j * a[i]) % b[i] == 0) {
                        min_cost = min(min_cost, (long long)j * p[i] + (mid - j * a[i]) / b[i] * q[i]);
                    } else {
                        min_cost = min(min_cost, (long long)j * p[i] + ((mid - j * a[i]) / b[i] + 1) * q[i]);
                    }
                }
            }
            for (int j = 0; j <= a[i]; ++j) {
                if ((mid - j * b[i]) >= 0) {
                    min_cost = min(min_cost, (long long)j * q[i]);
                    if ((mid - j * b[i]) % a[i] == 0) {
                        min_cost = min(min_cost, (long long)j * q[i] + (mid - j * b[i]) / a[i] * p[i]);
                    } else {
                        min_cost = min(min_cost, (long long)j * q[i] + ((mid - j * b[i]) / a[i] + 1) * p[i]);
                    }
                }
            }
            sum += min_cost;
        }
        
        if (sum <= x) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    
    cout << r << endl;
    return 0;
}