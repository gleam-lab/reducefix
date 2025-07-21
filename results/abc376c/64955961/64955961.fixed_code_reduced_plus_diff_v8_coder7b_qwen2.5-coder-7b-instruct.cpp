#include <bits/stdc++.h>

using namespace std;

bool canFit(int x, vector<int>& a, vector<int>& b) {
    int boxes = 1;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) {
            ++i;
        } else {
            ++j;
            ++boxes;
        }
    }
    return i == a.size() || (i == a.size() - 1 && j == b.size());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n), b(n-1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n-1; ++i) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int left = 0, right = 1e9 + 10;
    while (left < right) {
        int mid = (left + right) / 2;
        if (canFit(mid, a, b)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    if (left > 1e9) cout << -1 << endl;
    else cout << left << endl;

    return 0;
}