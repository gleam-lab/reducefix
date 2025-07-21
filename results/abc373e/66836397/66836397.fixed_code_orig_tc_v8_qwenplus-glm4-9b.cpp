// Read input
int N, M, K;
vector<int> A(N);

// Calculate sum of current votes and remaining votes
long long sum_of_current_votes = 0;
for (int i = 0; i < N; ++i) {
    cin >> A[i];
    sum_of_current_votes += A[i];
}
long long remaining_votes = K - sum_of_current_votes;

// Sort the array of current votes
sort(A.begin(), A.end());

// Iterate over sorted array of current votes
for (int i = 0; i < N; ++i) {
    // Check if the candidate already has a guaranteed win
    if (i < M) {
        // Candidate is guaranteed to win
        cout << 0 << " ";
        continue;
    }

    // Binary search or two-pointer technique to find minimum votes needed
    long long min_votes_needed = find_minimum_votes_needed(A, N, i, remaining_votes, M);

    // Print the minimum votes needed
    cout << min_votes_needed << " ";
}