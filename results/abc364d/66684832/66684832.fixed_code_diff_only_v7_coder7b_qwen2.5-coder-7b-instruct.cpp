#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

#define int long long
#define endl '\n'

const int MAXN = 1e5 + 7;

int n, q;
vector<int> a;

int binary_search(int target, int k) {
    int left = 0, right = n - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (abs(target - a[mid]) * 2 < abs(target - a[left])) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return abs(target - a[left]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    while (q--) {
        int b, k;
        cin >> b >> k;
        cout << binary_search(b, k) << endl;
    }

    return 0;
}