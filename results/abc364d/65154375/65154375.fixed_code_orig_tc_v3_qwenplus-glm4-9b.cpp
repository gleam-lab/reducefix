#include<bits/stdc++.h>
#include<array>
using namespace std;

#define endl "\n"
typedef long long ll;

const int N = 100001; // Adjust the size if needed
int a[N];

bool check(int mid, int x, int y, int n) {
    int left = max(0, x - mid);
    int right = min(n - 1, x + mid);
    int count = a[right] - (left == 0 ? 0 : a[left - 1]);
    return count >= y;
}

void solve() {
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        a[i] += a[i - 1];
    }
    for(int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        int l = 0, r = n;
        while(r > l + 1) {
            int mid = (l + r) / 2;
            if(check(mid, x, y, n)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        cout << abs(a[r] - a[x - y]) << endl;
    }
}

int main() {
    solve();
    return 0;
}