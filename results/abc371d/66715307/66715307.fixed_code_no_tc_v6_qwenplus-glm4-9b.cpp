#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector<int> x(n + 1), p(n + 1), a(n + 1);
    for (int i = 1; i <= n; i++) cin >> x[i];
    a[1] = p[1];
    for (int i = 2; i <= n; i++) {
        cin >> p[i];
        a[i] = a[i - 1] + p[i];
    }
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        int left = lower_bound(x.begin() + 1, x.end() + 1, l) - x.begin();
        int right = upper_bound(x.begin() + 1, x.end() + 1, r) - x.begin() - 1;
        cout << a[right] - (left == 0 ? 0 : a[left - 1]) << endl;
    }
    return 0;
}