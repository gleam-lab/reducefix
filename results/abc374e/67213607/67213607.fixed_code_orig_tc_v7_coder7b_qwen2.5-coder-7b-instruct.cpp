#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, x;
    cin >> n >> x;
    
    vector<int> a(n), p(n), b(n), q(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    
    int l = 0, r = 1e9 + 5;
    while(l < r) {
        int mid = l + (r - l) / 2;
        long long sum = 0;
        
        for(int i = 0; i < n; ++i) {
            int min_cost = INT_MAX;
            for(int j = 0; j <= b[i]; ++j) {
                int cost = j * p[i];
                if(mid >= j * a[i])
                    cost += (mid - j * a[i]) / b[i] * q[i];
                else
                    cost += ((mid - j * a[i]) / b[i] + 1) * q[i];
                min_cost = min(min_cost, cost);
            }
            for(int j = 0; j <= a[i]; ++j) {
                int cost = j * q[i];
                if(mid >= j * b[i])
                    cost += (mid - j * b[i]) / a[i] * p[i];
                else
                    cost += ((mid - j * b[i]) / a[i] + 1) * p[i];
                min_cost = min(min_cost, cost);
            }
            sum += min_cost;
        }
        
        if(sum <= x) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    
    cout << l - 1;
    return 0;
}