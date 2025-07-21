#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n, m, k, a[N], b[N];
int min_votes_needed[N];

// Function to calculate the number of votes needed to guarantee victory for candidate i
int calculate_votes_needed(int i, int additional_votes) {
    int votes_needed = 0;
    int max_votes = a[i] + additional_votes;
    int total_votes = a[i] + additional_votes;
    
    // Subtract the number of candidates who currently have more or equal votes
    int cnt = 0;
    for (int j = 1; j <= n; ++j) {
        if (a[j] > max_votes) {
            votes_needed += max_votes - a[j] + 1;
            total_votes += votes_needed;
            if (++cnt >= m) break;
        } else if (a[j] == max_votes) {
            votes_needed = 0;
            total_votes += votes_needed;
            if (++cnt >= m) break;
        }
    }
    
    // Check if the total number of votes is less than k
    if (total_votes > k) {
        return -1; // Cannot guarantee victory
    }
    
    return votes_needed;
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }
    
    // Sort the candidates based on votes, in descending order
    sort(b + 1, b + n + 1, greater<int>());
    
    for (int i = 1; i <= n; ++i) {
        // Find the minimum additional votes needed to guarantee victory
        int l = 0, r = k + 1;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            int votes_needed = calculate_votes_needed(i, mid);
            if (votes_needed >= 0) {
                r = mid;
            } else {
                l = mid;
            }
        }
        
        // If we find a valid number of additional votes, store it; otherwise, store -1
        min_votes_needed[i] = r == (k + 1) ? -1 : r;
    }
    
    // Output the results
    for (int i = 1; i <= n; ++i) {
        cout << min_votes_needed[i] << " ";
    }
    cout << endl;
    
    return 0;
}