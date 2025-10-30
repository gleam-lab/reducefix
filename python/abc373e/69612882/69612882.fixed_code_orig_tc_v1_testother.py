import sys

def solve():
    N, M, K = map(int, input().split())
    A = list(map(int, input().split()))
    
    # If M == N, everyone is elected regardless
    if M == N:
        print(' '.join(['0'] * N))
        return
    
    total_votes = sum(A)
    remaining_votes = K - total_votes
    
    # Create array with original indices to track candidates after sorting
    candidates = [(A[i], i) for i in range(N)]
    # Sort by votes descending
    candidates.sort(key=lambda x: x[0], reverse=True)
    
    # Result array
    result = [-1] * N
    
    # For each candidate, calculate minimum additional votes needed
    for orig_idx in range(N):
        current_votes = A[orig_idx]
        
        # Find position of this candidate in sorted list
        pos = -1
        for i in range(N):
            if candidates[i][1] == orig_idx:
                pos = i
                break
        
        # We need to ensure that at most M-1 candidates have more votes than us
        # So we need to be in top M
        
        # If already in top M, check if we can stay there without extra votes
        if pos < M:
            # Check if we are safe: even if all remaining votes go to others,
            # we still have at most M-1 people with more votes
            
            # Count how many candidates have strictly more votes than us
            count_greater = 0
            for i in range(N):
                if i != orig_idx and A[i] > current_votes:
                    count_greater += 1
            
            # If already <= M-1 people have more votes, we're safe
            if count_greater < M:
                result[orig_idx] = 0
                continue
        
        # We need to gain votes to be in top M
        # Strategy: we need to surpass enough candidates so that at most M-1 have more votes than us
        
        min_votes_needed = float('inf')
        
        # Try to target being better than the M-th place candidate
        # We need to have more votes than at least (N-M) candidates
        # Or equivalently, at most M-1 candidates should have more votes than us
        
        # Consider different thresholds
        for threshold in range(M):
            # We want to be better than the candidate currently at position threshold
            # But we also need to consider worst-case distribution of remaining votes
            
            if threshold >= N:
                continue
                
            target_votes = candidates[threshold][0]
            
            # If we're already above this target, no need to consider
            if current_votes > target_votes:
                result[orig_idx] = 0
                min_votes_needed = 0
                break
                
            # Calculate how many votes we need to reach target+1
            needed = target_votes + 1 - current_votes
            if needed <= 0:
                needed = 0
                
            # But we also need to make sure that even if remaining votes are distributed
            # adversarially, we still end up in top M
            
            # In worst case, other candidates get the remaining votes
            # We need to simulate if with 'needed' additional votes, we can guarantee victory
            
            # After we get 'needed' votes, our total is current_votes + needed
            our_final = current_votes + needed
            
            # Count how many candidates could potentially have more votes than us
            # in the worst case distribution
            potential_greater = 0
            remaining_after_us = remaining_votes - needed
            
            for i in range(N):
                if i == orig_idx:
                    continue
                candidate_votes = A[i]
                # Worst case: this candidate gets as many votes as possible
                # but we need to see if they can exceed our_final
                if candidate_votes >= our_final:
                    potential_greater += 1
                elif candidate_votes + remaining_after_us >= our_final:
                    # They could potentially surpass us if given enough votes
                    potential_greater += 1
            
            # If at most M-1 candidates can have more votes than us, we're good
            if potential_greater < M and needed <= remaining_votes:
                min_votes_needed = min(min_votes_needed, needed)
        
        # Additional strategy: try to directly compute the minimum votes needed
        # by considering how many people we need to surpass
        
        # We need at most M-1 candidates to have more votes than us
        # So we need to surpass at least (N - (M-1)) candidates
        
        # Sort all other candidates by their vote count
        others = []
        for i in range(N):
            if i != orig_idx:
                others.append(A[i])
        
        others.sort(reverse=True)
        
        # We need to be better than the (M-1)-th highest among others
        # Actually, we need at most M-1 candidates to have more votes than us
        # So we need to have at least as many votes as the M-th highest candidate overall
        # in the final ranking
        
        # Consider the M-th highest score among all candidates (excluding us initially)
        if M > 0:
            # We need to have more votes than the (M-1)-th ranked candidate from others
            # to ensure at most M-1 have more than us
            
            # Get the first M scores from others (the top M contenders)
            top_m_others = others[:M] if len(others) >= M else others
            
            # Our target: we need to have more votes than the smallest of these top M
            if len(top_m_others) < M:
                # Not enough other candidates to fill M spots, we're automatically in top M
                result[orig_idx] = 0
            else:
                target = top_m_others[-1]  # The M-th highest among others
                
                # We need our final votes > target
                # But consider worst case: remaining votes go to those who can challenge us
                needed = max(0, target + 1 - current_votes)
                
                # Verify this works
                our_final = current_votes + needed
                remaining_after = remaining_votes - needed
                
                if remaining_after >= 0:
                    # Count how many candidates can still have more votes than us
                    count_greater = 0
                    for vote_count in others:
                        if vote_count > our_final:
                            count_greater += 1
                        elif vote_count == our_final and vote_count > current_votes:
                            # If they started with more and can maintain tie
                            count_greater += 1
                    
                    # Also consider candidates who can use remaining votes to surpass us
                    for vote_count in others:
                        if vote_count <= our_final and vote_count + remaining_after > our_final:
                            count_greater += 1
                    
                    if count_greater < M and needed < min_votes_needed:
                        min_votes_needed = needed
        
        # One more approach: binary search on the answer
        left, right = 0, remaining_votes + 1
        ans = -1
        
        while left <= right:
            mid = (left + right) // 2
            our_final = current_votes + mid
            remaining_after = remaining_votes - mid
            
            if remaining_after < 0:
                right = mid - 1
                continue
                
            # Count how many candidates will definitely or potentially have more votes than us
            count_greater = 0
            for i in range(N):
                if i == orig_idx:
                    continue
                if A[i] > our_final:
                    count_greater += 1
                elif A[i] + remaining_after > our_final:
                    # This candidate could receive enough votes to surpass us
                    count_greater += 1
            
            if count_greater < M:  # At most M-1 have more votes than us
                ans = mid
                right = mid - 1
            else:
                left = mid + 1
        
        if ans != -1:
            result[orig_idx] = ans
        else:
            result[orig_idx] = -1
    
    # Special case: if remaining_votes is 0, then we can only win if already qualified
    if remaining_votes == 0:
        for i in range(N):
            # Count how many have more votes than candidate i
            count_greater = sum(1 for j in range(N) if j != i and A[j] > A[i])
            if count_greater < M:
                result[i] = 0
            else:
                result[i] = -1
    
    print(' '.join(map(str, result)))

solve()