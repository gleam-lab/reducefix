#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int _ = 0; _ < q; ++_) {
        int b, k;
        cin >> b >> k;
        vector<int> dists;
        for (int ai : a) {
            dists.push_back(abs(ai - b));
        }
        nth_element(dists.begin(), dists.begin() + k - 1, dists.end());
        cout << dists[k - 1] << '\n';
    }

    return 0;
}