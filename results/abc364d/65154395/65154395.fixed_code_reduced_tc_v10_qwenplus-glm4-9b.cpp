#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

const int N = 2e5 + 5;
int a[N], cnt[N];
vector<int> pos;

bool check(int mid) {
    int low = upper_bound(pos.begin(), pos.end(), cnt[mid]) - pos.begin();
    int high = lower_bound(pos.begin(), pos.end(), cnt[mid] + 1) - pos.begin();
    return (high - low) >= pos.size() - mid;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < q; ++i) {
        int b, k;
        cin >> b >> k;
        cnt[b] = k;
    }

    for (int i = 0; i < n; ++i) {
        pos.push_back(a[i]);
    }

    sort(pos.begin(), pos.end());
    fill(cnt + 1, cnt + n + 1, 0);

    for (int i = 0; i < q; ++i) {
        int b = q + i;
        int left = 0, right = n;
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            if (check(mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        cout << (long long)a[left] + (long long)b << endl;
    }

    return 0;
}