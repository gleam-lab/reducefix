#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 5;
int t, n, k;
int a[maxN], b[maxN];
pair<int, int> p[maxN];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            p[i].first = b[i];
            p[i].second = a[i];
        }

        sort(p, p + n, [](pair<int, int>& p1, pair<int, int>& p2) {
            return p1.first > p2.first;
        });

        long long sum = 0, max_val = 0;
        for (int i = 0; i < k; i++) {
            sum += p[i].first;
            max_val = p[i].second;
        }

        long long min_ans = max_val * sum;

        for (int i = k; i < n; i++) {
            sum -= p[i - k].first;
            max_val = p[i - k + 1].second;
            sum += p[i].first;

            long long cur_ans = max_val * sum;
            min_ans = min(min_ans, cur_ans);
        }

        cout << min_ans << '\n';
    }

    return 0;
}