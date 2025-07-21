#include<bits/stdc++.h>
using namespace std;

const int MAXN = 105;
const int INF = 2e9;

int n, x, a[MAXN], p[MAXN], b[MAXN], q[MAXN];

// Function to calculate minimum cost for a given time mid
int minCost(int mid) {
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        int minn = INF;
        // Calculate cost for type 1
        for (int j = 0; j <= b[i]; ++j) {
            if ((mid - j * a[i]) <= 0)
                minn = min(minn, j * p[i]);
            else if ((mid - j * a[i]) % b[i] == 0)
                minn = min(minn, j * p[i] + (mid - j * a[i]) / b[i] * q[i]);
            else
                minn = min(minn, j * p[i] + (mid - j * a[i]) / b[i] * q[i] + q[i]);
        }
        // Calculate cost for type 2
        for (int j = 0; j <= a[i]; ++j) {
            if ((mid - j * b[i]) <= 0)
                minn = min(minn, j * q[i]);
            else if ((mid - j * b[i]) % a[i] == 0)
                minn = min(minn, j * q[i] + (mid - j * b[i]) / a[i] * p[i]);
            else
                minn = min(minn, j * q[i] + (mid - j * b[i]) / a[i] * p[i] + p[i]);
        }
        sum += minn;
    }
    return sum;
}

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; ++i)
        cin >> a[i] >> p[i] >> b[i] >> q[i];

    int l = 0, r = 1000000005;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (minCost(mid) <= x)
            l = mid + 1;
        else
            r = mid;
    }

    cout << l - 1 << endl; // Since we need the maximum time that does not exceed x
    return 0;
}