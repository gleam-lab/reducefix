#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> A(n);
    ll votes_sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        votes_sum += A[i];
    }
    
    vector<ll> votes_needed(n);
    for (int i = 0; i < n; ++i) {
        // Calculation to determine the votes needed to secure the election
        // A_i + (M-1) * max votes of other candidates
        // Since we need at least as many votes as the maximum to be guaranteed,
        // we use max(A) as a placeholder for max votes of other candidates
        votes_needed[i] = A[i] + (m - 1) * A.back();
    }

    // Array to store the minimum additional votes needed
    vector<ll> additional_votes_needed(n);
    
    // Sort the votes needed in descending order
    sort(votes_needed.rbegin(), votes_needed.rend());
    
    // Iterate through the sorted votes needed and calculate minimum additional votes needed
    for (int i = 0; i < n; ++i) {
        if (votes_needed[i] > k - votes_sum) {
            // If the votes needed are more than what's left, set to -1
            additional_votes_needed[i] = -1;
        } else {
            // Calculate additional votes needed
            additional_votes_needed[i] = votes_needed[i] - A[i];
        }
    }
    
    // Output the result
    for (ll vote_needed : additional_votes_needed) {
        cout << vote_needed << " ";
    }
    cout << endl;
    
    return 0;
}