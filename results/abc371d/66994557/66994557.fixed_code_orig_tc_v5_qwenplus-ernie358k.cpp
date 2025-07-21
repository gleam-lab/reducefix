#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector<long long> x(n), p(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    vector<long long> sum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        sum[i + 1] = sum[i] + p[i];
    }
    cin >> q;
    while (q--) {
        long long L, R;
        cin >> L >> R;
        auto itL = lower_bound(x.begin(), x.end(), L);
        auto itR = upper_bound(x.begin(), x.end(), R);
        int l = itL - x.begin();
        int r = itR - x.begin();
        cout << sum[r] - sum[l] << endl;
    }
    return 0;
}