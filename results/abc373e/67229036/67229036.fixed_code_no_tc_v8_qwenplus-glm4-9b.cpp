#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m,k,ans[N];
int a[N], b[N], c[N];

// Binary search to find the minimum X such that candidate i will always be elected
bool canWinWithX(int candidate, int votes, int X, const vector<int>& sorted_votes, const vector<int>& votes_needed) {
    int num_more_votes = votes + X;
    return lower_bound(sorted_votes.begin(), sorted_votes.end(), num_more_votes + M + 1) - sorted_votes.begin() < n - m;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    sort(a, a + n);
    reverse(a, a + n); // Sort in descending order to make a[0] the candidate with the most votes
    
    // Precompute votes needed to win for each candidate
    vector<int> votes_needed(n, 0);
    for (int i = 0; i < n; ++i) {
        if (i < m) {
            votes_needed[i] = a[i] + (i + 1) * (m - i - 1);
        } else {
            votes_needed[i] = a[i] + (i + 1) * m;
        }
    }
    
    // Iterate over each candidate from the most votes to the least
    for (int i = 0; i < n; ++i) {
        int votes = a[i];
        int X = votes_needed[i] - votes; // Total votes needed for the current candidate to win
        
        // Binary search for the minimum X
        int low = 0, high = k, mid;
        while (low < high) {
            mid = (low + high) / 2;
            if (canWinWithX(i, votes, mid, a, votes_needed)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        
        // The minimum X is the smallest number that makes the candidate win
        ans[i] = low;
    }
    
    // Output the result
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    
    return 0;
}