#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;
int n, m, k, a[N], sorted[N], prefix[N];

int find_min_votes(int candidate_votes) {
    int low = 0, high = k;
    int answer = -1;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        int total = candidate_votes + mid;
        
        int pos = upper_bound(sorted + 1, sorted + n + 1, total) - sorted - 1;
        if (n - pos < m) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    return answer;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sorted[i] = a[i];
    }
    
    sort(sorted + 1, sorted + n + 1);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + sorted[i];
    }
    
    for (int i = 1; i <= n; ++i) {
        int candidate_votes = a[i];
        int low = 0, high = k;
        int answer = -1;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            int total = candidate_votes + mid;
            
            int pos = upper_bound(sorted + 1, sorted + n + 1, total) - sorted - 1;
            if (n - pos < m) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        if (answer != -1 && answer <= k) {
            cout << answer << " ";
        } else {
            cout << "-1 ";
        }
    }
    
    return 0;
}