#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
#define endl '\n'

const int N = 1e5 + 5;
int a[N];

bool check(int pos, int d, int k, int n) {
    int left = lower_bound(a, a + n, pos - d) - a;
    int right = upper_bound(a, a + n, pos + d) - a;
    return (right - left) >= k;
}

int find_kth_distance(int pos, int k, int n) {
    int low = 0, high = 2e18;
    int answer = 2e18;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(pos, mid, k, n)) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return answer;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    
    while (q--) {
        int x, k;
        cin >> x >> k;
        cout << find_kth_distance(x, k, n) << endl;
    }
    
    return 0;
}