#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const int N = 2e5 + 9, M = 1e9 + 5;

int n, q;
vector<int> a(N), b(N), k(N);

bool check(int pos, int radius, int k) {
    int left = lower_bound(a.begin(), a.end(), pos - radius) - a.begin();
    int right = lower_bound(a.begin(), a.end(), pos + radius) - a.begin();
    int count = right - left;
    if (count < k) return false;
    while (left + k - 1 < right) {
        int mid = left + k / 2;
        if (a[mid] > pos - radius) left = mid + 1;
        else k -= k / 2;
    }
    return a[left] <= pos + radius;
}

int findans(int pos, int k) {
    int left = 0, right = M;
    while (left < right) {
        int mid = (left + right + 1) / 2;
        if (check(pos, mid, k)) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> q;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < q; ++i) cin >> b[i] >> k[i];
    
    sort(b.begin(), b.end());
    sort(k.begin(), k.end());
    
    for (int i = 0; i < q; ++i) {
        int result = findans(b[i], k[i]);
        cout << result << '\n';
    }
    
    return 0;
}