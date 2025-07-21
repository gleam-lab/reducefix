#include <bits/stdc++.h>
using namespace std;

bool canFit(vector<int>& va, vector<int>& vb, int x) {
    int n = va.size();
    vector<bool> used(n, false);
    for (int i = 0; i < n - 1; ++i) {
        if (vb[i] >= x || va[i] > x) return false;
        if (!used[i]) {
            used[i] = true;
            for (int j = i + 1; j < n; ++j) {
                if (va[j] == vb[i] && !used[j]) {
                    used[j] = true;
                    break;
                }
            }
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> va(n), vb(n);
    for (int i = 0; i < n; ++i)
        cin >> va[i];
    for (int i = 0; i < n - 1; ++i)
        cin >> vb[i];

    sort(va.begin(), va.end(), greater<int>());
    sort(vb.begin(), vb.end());

    int left = 1, right = max(*max_element(va.begin(), va.end()), *max_element(vb.begin(), vb.end()));
    while (left <= right) {
        int mid = (left + right) / 2;
        if (canFit(va, vb, mid)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << (left <= *max_element(va.begin(), va.end()) ? left : -1) << endl;
    return 0;
}