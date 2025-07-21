#include <bits/stdc++.h>
using namespace std;

bool canPlace(vector<int>& va, vector<int>& vb, int x) {
    int n = va.size();
    vector<bool> used(n, false);
    for (int i = 0; i < n - 1; ++i) {
        int j = i + 1;
        while (j < n && !used[j]) {
            if (va[j] <= vb[i] + x) {
                used[j] = true;
                break;
            }
            ++j;
        }
        if (j == n) return false;
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

    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());

    int low = 0, high = 1e9;
    while (low < high) {
        int mid = (low + high) / 2;
        if (canPlace(va, vb, mid))
            high = mid;
        else
            low = mid + 1;
    }

    cout << (canPlace(va, vb, low) ? low : -1) << endl;
    return 0;
}