#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
int n, q;

int count_within(int b, int d) {
    int l = lower_bound(a, a + n, b - d) - a;
    int r = upper_bound(a, a + n, b + d) - a;
    return r - l;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    while(q--) {
        int b, k;
        cin >> b >> k;
        int left = 0, right = 2e8, answer = 2e8;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            int cnt = count_within(b, mid);
            if(cnt >= k) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        cout << answer << "\n";
    }
    return 0;
}