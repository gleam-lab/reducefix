#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, m, k, sum, cnt, a[N], b[N], c[N];

// Function to check if candidate i can win with x additional votes
bool check(int i, int x) {
    // Number of candidates with more votes than candidate i
    int greaterVotes = upper_bound(b + 1, b + n + 1, a[i] + x) - b - 1;
    
    // Calculate the total votes needed to ensure candidate i wins
    long long requiredVotes = (long long)(greaterVotes - (m - 1)) * (a[i] + x + 1);
    
    // Check if the remaining votes are sufficient
    return requiredVotes <= k - sum;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> m >> k;
    sum = 0;
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
        b[i] = a[i];
    }
    
    sort(b + 1, b + n + 1);
    
    for (int i = 1; i <= n; ++i) {
        c[i] = c[i - 1] + b[i];
    }
    
    for (int i = 1; i <= n; ++i) {
        int l = 0, r = k - sum + 1;
        
        while (l < r) {
            int mid = l + (r - l) / 2;
            
            if (check(i, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        
        if (l <= k - sum) {
            cout << l << " ";
        } else {
            cout << "-1 ";
        }
    }
    
    return 0;
}