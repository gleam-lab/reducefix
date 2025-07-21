// Input Parsing
int N, M, K;
vector<long long> A(N);
input(N, M, K);
for (int i = 0; i < N; ++i) input(A[i]);

// Sorting and Preparation
sort(A.begin(), A.end());

// Vote Analysis
vector<long long> votes_needed(N, -1); // Initialize with -1 (default: cannot secure victory)

for (int i = 0; i < N; ++i) {
    long long total_votes_possible = A[i] + (K - accumulate(A.begin(), A.end(), 0LL) - A[i]); // All remaining votes
    long long votes_to_surpass = total_votes_possible - M + 1; // Votes to surpass M leading candidates

    if (votes_to_surpass <= 0) {
        votes_needed[i] = 0; // Already have enough votes
        continue;
    }

    // Calculate the minimum votes needed to ensure victory
    // This part of the logic needs to be implemented
}

// Output
for (auto& x : votes_needed) {
    if (x == -1) pr(-1); // Candidate cannot secure victory
    else pr(x);
}