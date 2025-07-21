#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int n, m, k, sum, cnt, a[N], b[N];

// Auxiliary function to find the minimum votes needed to guarantee victory
int find_min_votes(int id, int votes_needed, int remaining_votes) {
    if ( votes_needed > remaining_votes ) {
        return -1;
    }
    
    int num_more_votes_than_i = 0;
    for ( int j = 0; j < n; j++ ) {
        if ( j == id ) continue;
        
        // Number of votes needed for candidate j to have more votes than candidate id
        int needed_for_j = votes_needed + m - 1;
        int current_votes_for_j = a[j];
        
        if ( current_votes_for_j >= needed_for_j ) {
            num_more_votes_than_i++;
        }
    }
    
    // If the number of candidates with more votes than candidate id is less than m, then id can win
    if ( num_more_votes_than_i >= m - 1 ) {
        return votes_needed;
    }
    
    return -1;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    
    sum = 0;
    for ( int i = 0; i < n; i++ ) {
        cin >> a[i];
        sum += a[i];
    }
    
    int remaining_votes = k - sum;
    
    for ( int i = 0; i < n; i++ ) {
        int min_votes_needed = find_min_votes(i, 0, remaining_votes);
        
        if ( min_votes_needed == -1 ) {
            cout << "-1 ";
        } else {
            // Check for each possible amount of votes from 0 to remaining_votes
            for ( int votes = 0; votes <= remaining_votes; votes++ ) {
                int result_votes_needed = find_min_votes(i, votes, remaining_votes - votes);
                if ( result_votes_needed != -1 ) {
                    cout << result_votes_needed;
                    break;
                }
            }
            cout << " ";
        }
    }
    
    return 0;
}