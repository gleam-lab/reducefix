#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>
#define fi first
#define se second

const int N = 2e5 + 10;

int n, k;
int a[N], b[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;

    while (t--) {
        cin >> n >> k;
        long long sum1 = 0, sum2 = 0;
        long long answer = LLONG_MAX;

        // Pair up the elements of A and B
        vector<PII> p(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cin >> b[i];
            p[i] = {a[i], b[i]};
        }

        // Sort by A values
        sort(p.begin(), p.end());

        // Calculate the sum of B values for the first k elements
        for (int i = 0; i < k; i++) {
            sum1 += p[i].se;
        }

        // Find the minimum possible value of the expression
        for (int i = k; i < n; i++) {
            sum2 = sum1 - p[i - k].se + p[i].se;
            answer = min(answer, p[i].fi * sum2);
        }

        cout << answer << "\n";
    }

    return 0;
}