import sys

def solve():
    N, M, K = map(int, input().split())
    A = list(map(int, input().split()))
    
    total_votes = sum(A)
    remaining_votes = K - total_votes
    
    # If M == N, all candidates will be elected regardless
    if M >= N:
        print(' '.join(['0'] * N))
        return
    
    # Create list of (votes, original_index) for sorting
    candidates = [(A[i], i) for i in range(N)]
    candidates.sort(reverse=True)
    
    # Result array for each candidate
    result = [0] * N
    
    # For each candidate, calculate minimum additional votes needed
    for i in range(N):
        current_votes, orig_idx = candidates[i]
        
        # We need to ensure that at most M-1 candidates have more votes than us
        # So we need to be at least tied for the M-th highest position
        
        # Count how many candidates currently have more votes than us
        higher_count = 0
        for j in range(N):
            if A[j] > current_votes:
                higher_count += 1
        
        # If already less than M candidates have more votes, we're good
        if higher_count < M:
            result[orig_idx] = 0
            continue
            
        # We need to surpass enough candidates to be in top M
        # Find the vote count of the M-th highest candidate (0-indexed M-1)
        # But we might need to tie with them or beat them
        
        # Sort the vote counts in descending order
        sorted_votes = sorted(A, reverse=True)
        
        # The threshold is the M-th highest vote count
        threshold = sorted_votes[M-1]
        
        # If we're already at or above threshold, check if we're in top M
        if current_votes >= threshold:
            # Count how many have strictly more votes than us
            strictly_higher = sum(1 for votes in A if votes > current_votes)
            if strictly_higher < M:
                result[orig_idx] = 0
                continue
        
        # We need to reach at least threshold + 1 to guarantee being in top M
        # But we also need to consider that others might get votes too
        target = threshold
        
        # Check if staying at threshold is enough
        # Count how many candidates have more than threshold votes
        above_threshold = sum(1 for votes in A if votes > threshold)
        
        # If we can reach threshold and there are already M or more above threshold,
        # we need to go higher
        if above_threshold >= M:
            target = threshold + 1
        
        # Calculate minimum additional votes needed
        needed = max(0, target - current_votes)
        
        # Check if it's even possible
        if needed > remaining_votes:
            result[orig_idx] = -1
        else:
            result[orig_idx] = needed
    
    print(' '.join(map(str, result)))

solve()