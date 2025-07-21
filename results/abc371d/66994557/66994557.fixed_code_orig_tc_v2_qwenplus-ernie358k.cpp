#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector<long long> x(n + 1), p(n + 1);
    vector<long long> sum(n + 1);
    
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i];
    }
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        auto it_l = lower_bound(x.begin() + 1, x.end(), L);
        auto it_r = upper_bound(x.begin() + 1, x.end(), R);
        int l = distance(x.begin(), it_l) - 1;
        int r = distance(x.begin(), it_r) - 1;
        cout << sum[r] - sum[l] << endl;
    }
    return 0;
}