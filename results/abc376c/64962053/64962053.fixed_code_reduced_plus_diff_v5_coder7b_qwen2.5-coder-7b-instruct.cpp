#include <bits/stdc++.h>
using namespace std;

bool canStore(int x, vector<int>& va, vector<int>& vb) {
    multiset<int> boxes{vb.begin(), vb.end()};
    for (int size : va) {
        auto it = boxes.lower_bound(size);
        if (it == boxes.end()) return false;
        boxes.erase(it);
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> va(n), vb(n-1);
    for (int i = 0; i < n; ++i)
        cin >> va[i];
    for (int i = 0; i < n-1; ++i)
        cin >> vb[i];

    sort(va.begin(), va.end(), greater<int>());
    sort(vb.begin(), vb.end());

    int left = 1, right = 1e9, mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (canStore(mid, va, vb))
            right = mid - 1;
        else
            left = mid + 1;
    }

    if (left > 1e9) cout << -1 << endl;
    else cout << left << endl;

    return 0;
}