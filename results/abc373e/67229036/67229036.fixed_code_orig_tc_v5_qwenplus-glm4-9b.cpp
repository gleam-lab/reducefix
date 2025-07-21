#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m,k,sum,a[N],b[N];
int min_votes_needed[N];

bool can_win_with_votes(int candidate_index, int additional_votes, int remaining_votes) {
    int current_votes = a[candidate_index] + additional_votes;
    int competitors = upper_bound(b, b+n, current_votes) - b;
    
    // Calculate votes needed for the Mth place
    long long votes_needed_for_mth_place = current_votes + m - competitors;
    
    // Calculate the total votes needed to guarantee Mth place
    long long votes_needed = votes_needed_for_mth_place + sum - a[0];
    
    return votes_needed <= remaining_votes;
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Sort the votes received so far
    sort(a, a + n);
    
    // Calculate the sum of votes received
    sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }
    
    // Create an array of votes to be considered (received votes plus remaining votes)
    int total_votes[N];
    for (int i = 0; i < n; ++i) {
        total_votes[i] = a[i];
    }
    
    // Binary search for minimum additional votes
    for (int i = 0; i < n; ++i) {
        int low = 0, high = k - sum, mid, min_additional_votes = -1;
        
        while (low <= high) {
            mid = (low + high) / 2;
            if (can_win_with_votes(i, mid, k - sum)) {
                high = mid - 1;
                min_additional_votes = mid;
            } else {
                low = mid + 1;
            }
        }
        
        min_votes_needed[i] = min_additional_votes;
    }
    
    // Output the results
    for (int i = 0; i < n; ++i) {
        cout << min_votes_needed[i] << (i < n - 1 ? ' ' : '\n');
    }
    
    return 0;
}