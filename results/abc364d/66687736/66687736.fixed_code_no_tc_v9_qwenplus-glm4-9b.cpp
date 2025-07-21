#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        mp[a[i]]++;
    }

    for (int i = 0; i < q; ++i) {
        int b, k;
        cin >> b >> k;
        auto it = mp.lower_bound(b);
        if (it == mp.end() || k > it->second) {
            cout << "0\n"; // No valid X found
        } else {
            cout << b - (it->first - k + it->second) << endl;
        }
    }

    return 0;
}