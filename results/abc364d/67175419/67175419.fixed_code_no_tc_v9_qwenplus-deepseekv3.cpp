#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n, q, a[N];

// Function to count the number of elements in a within [x - d, x + d]
int count_within_distance(int x, int d) {
    int left = lower_bound(a, a + n, x - d) - a;
    int right = upper_bound(a, a + n, x + d) - a;
    return right - left;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    while(q--) {
        int b, k;
        cin >> b >> k;
        int low = 0, high = 2e8;
        int answer = 0;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int cnt = count_within_distance(b, mid);
            if(cnt >= k) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << answer << "\n";
    }
    return 0;
}