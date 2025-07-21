bool f(long long k, int i){
    // k is the number of additional votes to candidate i
    // i is the index of candidate i in the sorted array
    long long votes_needed = A[i].a + 1 - A[i + 1].a; // votes needed to exceed next candidate
    long long votes_to_beat = 0; // total votes to be exceeded
    for (int j = i - 1; j >= i - M; --j) {
        votes_to_beat += (A[j].a + 1); // votes needed to exceed j-th candidate
    }
    // Check if candidate i can win with k additional votes
    return votes_needed * (i - (i - M)) <= k && k <= votes_to_beat;
}