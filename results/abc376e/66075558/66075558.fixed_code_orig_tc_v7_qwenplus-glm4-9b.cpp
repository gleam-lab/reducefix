#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define N 200010

pair<int, int> vec[N];
int a[N], b[N];
long long res;

bool cmp(pair<int, int> p, pair<int, int> q) {
    if (p.first == q.first)
        return p.second < q.second;
    return p.first > q.first;
}

int main() {
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
            cin >> vec[i].first >> vec[i].second;
        sort(vec, vec + n, cmp);
        long long sum = 0, ans = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            if (i >= k - 1) {
                ans = min(ans, sum * vec[i].first);
                sum -= vec[i - k + 1].second;
            }
            sum += vec[i].second;
        }
        cout << ans << endl;
    }
    return 0;
}