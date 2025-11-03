import sys

def solve():
    N, M, K = map(int, input().split())
    A = list(map(int, input().split()))
    
    total_votes = sum(A)
    remaining_votes = K - total_votes
    
    # If M == N, all candidates will be elected (since less than M candidates have more votes)
    if M == N:
        print(' '.join(['0'] * N))
        return
    
    # Create list of (votes, original_index) for sorting
    candidates = [(A[i], i) for i in range(N)]
    candidates.sort(reverse=True)
    
    # Result array for each candidate
    result = [0] * N
    
    # For each candidate, calculate minimum additional votes needed
    for idx in range(N):
        votes, orig_idx = candidates[idx]
        
        # Check if already guaranteed victory
        # Count how many candidates currently have strictly more votes
        stronger_count = 0
        for i in range(N):
            if A[i] > votes:
                stronger_count += 1
        
        # If already less than M candidates have more votes, no additional votes needed
        if stronger_count < M:
            result[orig_idx] = 0
            continue
        
        # We need to ensure at most M-1 candidates have more votes than us
        # Strategy: we need to surpass at least (stronger_count - (M-1)) candidates
        # Find the vote threshold we need to reach
        
        # Get the votes of the M-th strongest candidate (0-indexed M-1)
        # But we need to consider that some candidates might tie with us
        threshold_idx = M - 1
        
        # If we're already in top M, we might just need to maintain position
        if idx < M:
            # We're in top M, but tied or below others - we need to get ahead
            # Find the minimum votes needed to be among top M
            if idx == 0:
                # Already highest, just need to maintain
                result[orig_idx] = 0
                continue
                
            # We need to beat enough candidates to be in top M
            # Find the vote count of the M-th place candidate
            if M < N:
                target_votes = candidates[M-1][0]
                # If we're tied with the M-th place, we might still lose on tiebreak
                # So we need one more vote than the M-th place if we're not already above
                if votes <= target_votes:
                    needed = target_votes + 1 - votes
                    result[orig_idx] = max(0, needed)
                else:
                    result[orig_idx] = 0
            else:
                # M == N case already handled
                result[orig_idx] = 0
        else:
            # We're not in top M, so we need to get into top M
            # We need to have more votes than the current M-th place candidate
            target_votes = candidates[M-1][0]
            
            # If there are ties at the M-th position, we need to surpass all of them
            # Count how many candidates are at or above the M-th position
            mth_votes = candidates[M-1][0]
            candidates_above_mth = 0
            for i in range(M):
                if candidates[i][0] > mth_votes:
                    candidates_above_mth += 1
            
            # We need to surpass the M-th place candidate
            needed = mth_votes + 1 - votes
            result[orig_idx] = max(0, needed)
    
    # Re-check with a more robust method
    result = [0] * N
    
    for i in range(N):
        current_votes = A[i]
        
        # Count candidates with strictly more votes
        stronger_count = sum(1 for j in range(N) if A[j] > current_votes)
        
        if stronger_count < M:
            result[i] = 0
            continue
            
        # We need to reduce the number of candidates with more votes to at most M-1
        # So we need to surpass at least (stronger_count - (M-1)) candidates
        
        # Collect all vote counts from other candidates
        other_votes = [A[j] for j in range(N) if j != i]
        other_votes.sort(reverse=True)
        
        # We need to be better than at least (N - M) candidates
        # Specifically, we need to have more votes than the M-th best candidate overall
        if M <= len(other_votes):
            threshold = other_votes[M-1]  # M-th best among others
            
            # We need strictly more than this threshold
            if current_votes <= threshold:
                needed = threshold + 1 - current_votes
                result[i] = needed
            else:
                result[i] = 0
        else:
            result[i] = 0
    
    # Final verification and adjustment for edge cases
    for i in range(N):
        if result[i] > remaining_votes:
            # Check if it's actually possible
            current_votes = A[i]
            target_votes = current_votes + result[i]
            
            # Simulate worst case: all remaining votes go to other candidates
            # Distribute remaining votes optimally against candidate i
            other_votes = A[:]
            other_votes[i] = current_votes  # reset to current
            
            # Give all remaining votes to candidates who can challenge i
            remaining = remaining_votes
            # First, give votes to candidates who could potentially surpass our target
            for j in range(N):
                if j == i:
                    continue
                # Give as many votes as possible to candidate j
                while remaining > 0 and other_votes[j] < target_votes:
                    other_votes[j] += 1
                    remaining -= 1
                    if other_votes[j] >= target_votes:
                        break
            
            # Count how many candidates have more votes than i's target
            stronger_count = sum(1 for j in range(N) if j != i and other_votes[j] > target_votes)
            
            if stronger_count >= M:
                result[i] = -1
            else:
                # Recalculate minimum needed
                other_sorted = sorted([A[j] for j in range(N) if j != i], reverse=True)
                if M > 0 and M <= len(other_sorted):
                    threshold = other_sorted[M-1]
                    needed = max(0, threshold + 1 - A[i])
                    if needed <= remaining_votes:
                        result[i] = needed
                    else:
                        result[i] = -1
                else:
                    result[i] = 0
    
    # Simplified correct approach
    result = [-1] * N
    
    for i in range(N):
        # How many candidates currently have more votes than candidate i?
        stronger_count = sum(1 for j in range(N) if A[j] > A[i])
        
        if stronger_count < M:
            result[i] = 0
            continue
            
        # We need to ensure at most M-1 candidates have more votes
        # So we need to surpass at least (stronger_count - (M-1)) candidates
        # Find the minimum votes needed
        
        # Consider all other candidates' votes
        others = [A[j] for j in range(N) if j != i]
        others.sort(reverse=True)
        
        # To be in top M, we need more votes than the M-th highest among others
        if M == 0:
            target = -1
        elif M <= len(others):
            target = others[M-1]
        else:
            target = -1  # This shouldn't happen since M <= N
        
        if M == 0:
            needed = 0
        else:
            needed = max(0, target + 1 - A[i])
        
        # Check if this is achievable
        if needed <= remaining_votes:
            # Verify that with 'needed' additional votes, candidate i wins
            new_vote_count = A[i] + needed
            
            # In worst case, all other remaining votes go to opponents
            opp_remaining = remaining_votes - needed
            opponent_votes = A[:]
            opponent_votes[i] = new_vote_count
            
            # Distribute remaining votes to maximize number of candidates > new_vote_count
            arr = [(opponent_votes[j], j) for j in range(N) if j != i]
            arr.sort(reverse=True)
            
            # Give extra votes to candidates just below our threshold
            for votes, j in arr:
                while opp_remaining > 0 and opponent_votes[j] < new_vote_count:
                    opponent_votes[j] += 1
                    opp_remaining -= 1
                    if opponent_votes[j] >= new_vote_count:
                        break
            
            # Count how many have more votes than us
            stronger = sum(1 for j in range(N) if j != i and opponent_votes[j] > new_vote_count)
            
            if stronger < M:
                result[i] = needed
            else:
                result[i] = -1
        else:
            result[i] = -1
    
    # Final simplified and correct approach
    result = [0] * N
    others = sorted(A, reverse=True)
    
    for i in range(N):
        # Count how many have more votes
        stronger = sum(1 for j in range(N) if A[j] > A[i])
        
        if stronger < M:
            result[i] = 0
            continue
            
        # Need to pass the M-th place candidate
        # Find what the M-th highest score is among all candidates
        # But be careful about ties
        
        # Create a list without candidate i
        temp = [A[j] for j in range(N) if j != i]
        temp.sort(reverse=True)
        
        if M <= len(temp):
            threshold = temp[M-1]
            needed = max(0, threshold + 1 - A[i])
            
            # Check if possible
            if needed <= remaining_votes:
                result[i] = needed
            else:
                # Try to see if any lower value could work
                # Binary search on the answer might be needed, but let's check simply
                found = False
                for trial in range(min(needed, remaining_votes) + 1):
                    my_votes = A[i] + trial
                    # Worst case: distribute remaining-trial votes to help others beat me
                    rem = remaining_votes - trial
                    opp = A[:]
                    opp[i] = my_votes
                    
                    # Greedy: give votes to candidates who can become > my_votes
                    candidates_list = [(opp[j], j) for j in range(N) if j != i]
                    candidates_list.sort(reverse=True)
                    
                    for votes, j in candidates_list:
                        while rem > 0 and opp[j] < my_votes:
                            opp[j] += 1
                            rem -= 1
                            if opp[j] >= my_votes:
                                break
                    
                    stronger_count = sum(1 for j in range(N) if j != i and opp[j] > my_votes)
                    if stronger_count < M:
                        result[i] = trial
                        found = True
                        break
                
                if not found:
                    result[i] = -1
            else:
                result[i] = needed
        else:
            result[i] = 0
    
    # Correct final approach
    result = [-1] * N
    
    for i in range(N):
        if remaining_votes < 0:
            result[i] = -1
            continue
            
        # Try binary search on the number of additional votes needed
        lo, hi = 0, remaining_votes + 1
        
        while lo < hi:
            mid = (lo + hi) // 2
            my_final = A[i] + mid
            
            # Check if with 'mid' additional votes, candidate i is guaranteed to win
            # Worst case: other candidates get the remaining votes optimally to challenge i
            
            rem = remaining_votes - mid
            if rem < 0:
                hi = mid
                continue
                
            # Simulate worst-case distribution
            opp_votes = A[:]
            opp_votes[i] = my_final
            
            # Give remaining votes to other candidates to maximize those > my_final
            candidates = [(opp_votes[j], j) for j in range(N) if j != i]
            candidates.sort(reverse=True)  # Sort by current votes
            
            # Greedy: prioritize giving votes to candidates with high current votes
            # But we want to create as many candidates > my_final as possible
            # So focus on candidates just below my_final
            
            # First, try to push candidates to exceed my_final
            for votes, j in candidates:
                while rem > 0 and opp_votes[j] < my_final:
                    opp_votes[j] += 1
                    rem -= 1
                    if opp_votes[j] >= my_final:
                        break
            
            # Count how many candidates have more votes than i
            stronger_count = sum(1 for j in range(N) if j != i and opp_votes[j] > my_final)
            
            if stronger_count < M:  # i is elected
                hi = mid
            else:
                lo = mid + 1
        
        if lo <= remaining_votes:
            result[i] = lo
        else:
            result[i] = -1
    
    print(' '.join(map(str, result)))

solve()