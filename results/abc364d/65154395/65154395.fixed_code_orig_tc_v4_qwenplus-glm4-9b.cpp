#include<bits/stdc++.h>
#define endl "\n"

using namespace std;
typedef long long ll;

const int N = 100000 + 5;
const int M = 100000 + 5;
int n, q;
int a[N], count[N];

void solve(void) {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = x;
    }
    sort(a, a + n);  // Sort the array A

    for (int i = 1; i <= n; i++) {
        count[i] = count[i - 1] + 1;  // Prefix sum of points
    }

    for (int j = 0; j < q; j++) {
        int b, k;
        cin >> b >> k;
        // Binary search for the k-th closest point to b
        int l = 0, r = n - 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (count[m] >= k) r = m;
            else l = m;
        }
        // Calculate the distance from the k-th closest point to b
        int distance = abs(a[r] - b);
        cout << distance << endl;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}