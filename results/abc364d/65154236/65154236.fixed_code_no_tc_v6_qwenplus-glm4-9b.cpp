#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

const int N = 200005;
int a[N], cnt[N];

int solve(int x, int y) {
    int l = 1, r = N, best = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        int left_dist = a[mid] - (a[mid - 1] + cnt[mid - 1]);
        int right_dist = (a[mid + 1] + cnt[mid + 1]) - a[mid];
        if (left_dist >= y) best = mid;
        if (left_dist < y && right_dist >= y) {
            best = min(best, mid + (mid < N - 5 ? (y - left_dist) : (right_dist - y)));
            break;
        }
        if (right_dist < y) r = mid - 1;
        else l = mid + 1;
    }
    return best;
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        a[x] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i]) ++cnt[i];
        else cnt[i] = cnt[i - 1];
    }
    for (int i = 1; i <= q; ++i) {
        int b, k;
        cin >> b >> k;
        int answer = solve(b, k);
        cout << answer - b << endl;
    }
    return 0;
}