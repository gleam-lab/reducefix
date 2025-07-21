#include <iostream>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<cstring>
using namespace std;

typedef pair<int, int> pii;

int n, q;
vector<int> a, b, k;

vector<int> solve(vector<int>& a, vector<int>& b, vector<int>& k) {
    vector<int> result;
    for (int i = 0; i < q; ++i) {
        int pos = b[i], k_val = k[i];
        auto it = lower_bound(a.begin(), a.end(), pos);
        int idx = it - a.begin();
        if (idx == 0) {
            result.push_back(abs(a[0] - pos));
        } else if (idx == n) {
            result.push_back(abs(a[n - 1] - pos));
        } else {
            int left_dist = abs(a[idx - 1] - pos);
            int right_dist = abs(a[idx] - pos);
            if (left_dist <= right_dist) {
                result.push_back(left_dist);
            } else {
                result.push_back(right_dist);
            }
        }
    }
    return result;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    a.resize(n);
    b.resize(q);
    k.resize(q);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < q; ++i) {
        cin >> b[i] >> k[i];
    }

    sort(a.begin(), a.end());

    vector<int> result = solve(a, b, k);

    for (int i = 0; i < q; ++i) {
        cout << result[i] << "\n";
    }

    return 0;
}