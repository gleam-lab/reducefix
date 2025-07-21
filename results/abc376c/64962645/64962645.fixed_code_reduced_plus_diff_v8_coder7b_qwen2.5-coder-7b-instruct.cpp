#include <bits/stdc++.h>
using namespace std;

bool canStore(vector<int>& va, vector<int>& vb, int x) {
    vector<bool> used(vb.size() + 1, false);
    for (int i = 0; i < va.size(); ++i) {
        int needSize = va[i];
        for (int j = vb.size(); j >= 0; --j) {
            if (!used[j] && vb[j] >= needSize) {
                used[j] = true;
                break;
            }
        }
        if (!used.back()) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> va(n), vb(n - 1);
    for (int i = 0; i < n; ++i)
        cin >> va[i];
    for (int i = 0; i < n - 1; ++i)
        cin >> vb[i];

    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());

    int low = 0, high = 1e9, ans = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (canStore(va, vb, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}