// Sort the candidates based on votes
sort(candidates, greater_pair); 

// Function to check if a candidate can win with X additional votes
function<bool check(int candidate_index, int X) {
    // Calculate remaining votes
    int remaining_votes = K - sum_of_votes_so_far;
    
    // Calculate votes needed to guarantee victory
    int votes_needed = 0;
    for (int i = 0; i < candidate_index and i < M; i++) {
        votes_needed += candidates[i].votes + X - candidates[candidate_index].votes;
    }
    
    // Check if we have enough votes remaining
    return remaining_votes >= votes_needed;
}

// Binary search for minimum additional votes needed
for (each candidate) {
    int low = 0, high = remaining_votes + 1; 
    while (low < high - 1) {
        int mid = (low + high) / 2;
        if (check(candidate_index, mid)) {
            high = mid;
        } else {
            low = mid;
        }
    }
    // Output the minimum votes needed
    candidates[candidate_index].min_votes_needed = high;
}