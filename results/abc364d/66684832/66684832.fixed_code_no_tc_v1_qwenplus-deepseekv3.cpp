#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long

const int N = 1e5 + 5;
int a[N];

int find_kth_distance(int n, int b, int k) {
    int left = 0, right = 2e8;
    int answer = right;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        
        // Count the number of elements <= b + mid and >= b - mid
        int lower = lower_bound(a, a + n, b - mid) - a;
        int upper = upper_bound(a, a + n, b + mid) - a;
        int count = upper - lower;
        
        if (count >= k) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return answer;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    
    while (q--) {
        int b, k;
        cin >> b >> k;
        cout << find_kth_distance(n, b, k) << '\n';
    }
    
    return 0;
}