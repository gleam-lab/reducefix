#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m,k,sum,cnt,a[N],b[N],c[N];

// Function to check if candidate i can secure their victory with x additional votes
bool check(int i, int x) {
    int maxVotes = k - sum + x; // Total votes left including x additional votes for candidate i
    vector<int> votes(n); // Votes after considering x additional votes for candidate i
    
    // Calculate votes for each candidate after adding x votes to candidate i
    for(int j = 1; j <= n; ++j) {
        if(j == i) {
            votes[j] = a[j] + x;
        } else {
            votes[j] = a[j];
        }
    }
    
    // Sort the votes to determine the ranking
    sort(votes.begin() + 1, votes.end());
    
    // Check if candidate i can secure their victory
    for(int j = 1; j < m; ++j) {
        if(votes[j] > votes[n]) return false;
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int i, j, x, y, z, t;
    cin >> n >> m >> k;
    sum = 0;
    
    // Read initial vote counts and calculate total votes counted so far
    for(i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    
    // Initialize binary search range
    int l = 0, r = k + 1;
    
    for(i = 1; i <= n; ++i) {
        while(l < r) {
            int mid = (l + r) / 2;
            if(check(i, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        
        // If l exceeds k, it means candidate i cannot secure their victory
        if(l > k) {
            cout << "-1 ";
        } else {
            cout << l << " ";
        }
        
        // Reset l and r for the next iteration
        l = 0, r = k + 1;
    }
    
    return 0;
}