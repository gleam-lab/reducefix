#include <bits/stdc++.h>
using namespace std;
const int maxN = 200005;

int t, n, k;
int a[maxN], b[maxN];

int main()
{
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        vector<pair<int, int>> p(n + 1);

        for (int i = 1; i <= n; i++)
            cin >> a[i];

        for (int i = 1; i <= n; i++)
            cin >> b[i];

        for (int i = 1; i <= n; i++)
            p[i] = {a[i], b[i]};

        // Sort by A_i descending, then B_i descending
        sort(p.begin() + 1, p.begin() + n + 1, [](pair<int, int> &x, pair<int, int> &y) {
            if (x.first != y.first)
                return x.first > y.first;
            return x.second > y.second;
        });

        long long sum = 0;
        long long ans = p[k].first * accumulate(&b[1], &b[1] + k, 0LL);

        for (int i = k + 1; i <= n; i++)
        {
            sum += b[i];
            ans = min(ans, p[i].first * sum);
        }

        cout << ans << "\n";
    }

    return 0;
}