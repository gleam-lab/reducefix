#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n, q;
    cin >> n;
    vector<long long> x(n + 1), p(n + 1); // +1 to use 1-based indexing logic with 0-based array
    vector<long long> sum(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i];
    }

    cin >> q;
    while (q--) {
        long long l, r;
        cin >> l >> r;
        auto it_l = lower_bound(x.begin() + 1, x.end(), l) - x.begin();
        auto it_r = upper_bound(x.begin() + 1, x.end(), r) - x.begin();

        // Since we are using 1-based indexing logic, adjust the indices accordingly
        cout << sum[it_r - 1] - sum[it_l - 1] << endl;
    }

    return 0;
}