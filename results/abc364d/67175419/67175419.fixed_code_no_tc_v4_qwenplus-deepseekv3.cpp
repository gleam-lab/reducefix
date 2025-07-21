#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N];
int n, q;

int countWithinRange(int b, int d) {
    long long left = (long long)b - d;
    long long right = (long long)b + d;
    int lower = lower_bound(a + 1, a + n + 1, left) - a;
    int upper = upper_bound(a + 1, a + n + 1, right) - a;
    return upper - lower;
}

int findKthDistance(int b, int k) {
    if (n == 1) return abs(a[1] - b);
    
    int left = 0, right = 2e8;
    int answer = right;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cnt = countWithinRange(b, mid);
        
        if (cnt >= k) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    
    while (q--) {
        int b, k;
        cin >> b >> k;
        
        int left = 0, right = 2e8;
        int ans = right;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int lower = lower_bound(a + 1, a + n + 1, b - mid) - a;
            int upper = upper_bound(a + 1, a + n + 1, b + mid) - a;
            int cnt = upper - lower;
            
            if (cnt >= k) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        // Now we need to find the exact k-th distance
        vector<int> distances;
        int lower = lower_bound(a + 1, a + n + 1, b - ans) - a;
        int upper = upper_bound(a + 1, a + n + 1, b + ans) - a;
        for (int i = lower; i < upper; ++i) {
            distances.push_back(abs(a[i] - b));
        }
        sort(distances.begin(), distances.end());
        cout << distances[k - 1] << '\n';
    }
    
    return 0;
}