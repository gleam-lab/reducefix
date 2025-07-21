#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
long long n, m, k, sum, c[MAXN], b[MAXN];

// Function to check if candidate i can secure victory with x additional votes
bool check(long long i, long long x) {
    // Calculate the current total votes needed for candidate i to win
    long long needed = k + 1 - sum - x;
    
    // Find the position where candidate i ranks among the top M candidates
    auto it = upper_bound(b + 1, b + n + 1, a[i]);
    int rank = distance(b + 1, it);
    
    // Check if candidate i can win after receiving x additional votes
    return rank <= n - m && (needed - x) <= (b[n] - b[rank]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
        b[i] = a[i];
    }

    sort(b + 1, b + n + 1);  // Sort the array of votes for binary search
    c[1] = 0;  // Candidate 1 doesn't need any additional votes if he/she gets at least one vote

    for(int i = 2; i <= n; ++i) {
        long long left = 0, right = k - sum + 1;  // Binary search range for additional votes
        while(left < right) {
            long long mid = left + (right - left) / 2;
            if(check(i, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        if(left > k - sum) {  // If no valid solution exists
            c[i] = -1;
        } else {
            c[i] = left;
        }
    }

    // Output the results
    for(int i = 1; i <= n; ++i) {
        cout << c[i] << " ";
    }
    cout << endl;

    return 0;
}