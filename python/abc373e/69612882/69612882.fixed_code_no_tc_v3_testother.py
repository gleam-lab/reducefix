python
import sys

def solve():
    N, M, K = map(int, input().split())
    A = list(map(int, input().split()))
    
    total_counted = sum(A)
    remaining_votes = K - total_counted
    
    # If there are no remaining votes, we just check current state
    if remaining_votes == 0:
        # Count how many have more votes than candidate i
        ans = [0] * N
        for i in range(N):
            count_more = 0
            for j in range(N):
                if A[j] > A[i]:
                    count_more += 1
            if count_more >= M:
                ans[i] = -1
            else:
                ans[i] = 0
        print(*ans)
        return
    
    # Special case: if M == N, then everyone is elected (since less than N people can't have more votes)
    if M == N:
        print(' '.join(['0'] * N))
        return
    
    # We'll compute for each candidate the minimum additional votes needed
    ans = [0] * N
    
    # Sort candidates by current votes in descending order, keeping original indices
    candidates = [(A[i], i) for i in range(N)]
    candidates.sort(reverse=True)
    
    # For each candidate, determine minimum additional votes to guarantee election
    for votes, orig_idx in candidates:
        # We want candidate orig_idx to be elected no matter how the remaining votes are distributed
        
        # Candidate is elected iff fewer than M candidates have strictly more votes than them
        # So at most M-1 candidates can have more votes.
        
        # Strategy: assume worst-case distribution of remaining votes among other candidates
        # We need to ensure that at most M-1 candidates can end up with more votes than candidate orig_idx
        
        # Let x be the additional votes we give to candidate orig_idx
        # Then their final vote count is: A[orig_idx] + x
        
        # Other candidates can get at most remaining_votes - x votes in total (if we use x votes on orig_idx)
        # But in the worst case, opponents will try to maximize the number of candidates with > (A[orig_idx] + x)
        
        # How many candidates currently have >= A[orig_idx]? We must be careful about ties.
        
        target = A[orig_idx]
        needed = 0
        
        # We simulate: what is the minimal x such that even in worst-case assignment of remaining votes,
        # at most M-1 candidates can exceed target + x?
        
        # We consider all other candidates. For each candidate j != orig_idx,
        # they can receive some of the remaining votes (but not the ones we allocate to orig_idx).
        
        # We need to find smallest x >= 0 such that it's impossible for M or more candidates 
        # (other than orig_idx) to get more than target + x.
        
        # Instead, we can reframe: we want at most M-1 candidates to be able to surpass target + x.
        # So we try to "block" the top M candidates from exceeding target + x.
        
        # Consider: list all candidates except orig_idx, and see how hard it is to push M of them above target+x.
        
        # Alternate approach:
        # Let’s suppose we assign x votes to candidate orig_idx.
        # Then we have R = remaining_votes - x votes left to distribute arbitrarily among others.
        #
        # We want to prevent M candidates from having > (target + x) votes.
        # The best way for adversaries is to boost the strongest candidates.
        #
        # Consider the M candidates (excluding orig_idx) who are closest to threatening orig_idx.
        # Actually, we should consider the top M candidates in terms of potential to exceed target+x.
        #
        # Specifically, let’s collect all candidates j != orig_idx.
        # For a fixed x, the number of votes candidate j needs to exceed target+x is:
        #   max(0, target + x - A[j] + 1)
        #
        # But we want to know: can M candidates be pushed above target+x using at most R votes?
        # This is equivalent to: is the sum of the M smallest "exceed costs" <= R?
        # However, note: one candidate can only be counted once.
        #
        # So condition for failure (i.e., orig_idx not elected): 
        # There exists a set S of M candidates (j ≠ orig_idx) such that sum_{j in S} max(0, target+x+1 - A[j]) <= R
        #
        # We want to avoid this. So we want:
        # For every set S of M candidates (j ≠ orig_idx), sum_{j in S} max(0, target+x+1 - A[j]) > R
        # But checking all sets is too expensive.
        #
        # Instead, the minimal total cost to make M candidates exceed target+x is:
        # Take the M candidates j ≠ orig_idx with smallest values of max(0, target+x+1 - A[j])
        # and sum them.
        #
        # So condition for safety: 
        #   min_total_cost = sum of smallest M values of max(0, target+x+1 - A[j]) for j≠orig_idx
        #   must be > remaining_votes - x
        #
        # We want the smallest x such that:
        #   min_total_cost > remaining_votes - x
        #
        # Note: if M == 0, then condition is always satisfied (but M>=1 per constraints)
        
        if M == 0:
            ans[orig_idx] = 0
            continue
            
        # Build list of other candidates' votes
        others = []
        for j in range(N):
            if j != orig_idx:
                others.append(A[j])
        
        # Sort in descending order? Actually, for computing the minimal cost to boost M of them, 
        # we want to consider which ones are easiest to boost (i.e., already high)
        # So sort in descending order: the highest ones require least extra votes
        others.sort(reverse=True)
        
        # We are going to binary search on x in range [0, remaining_votes + 1]
        # But note: x might need to be larger than remaining_votes -> then impossible
        lo, hi = 0, remaining_votes + 1
        found = False
        
        while lo < hi:
            x = (lo + hi) // 2
            final_score = target + x
            R = remaining_votes - x  # votes available for others
            
            if R < 0:
                lo = x + 1
                continue
                
            # Compute minimal cost to make M candidates exceed final_score
            cost = 0
            count = 0
            # Consider the top (easiest to boost) candidates
            for vote_count in others:
                if count >= M:
                    break
                if vote_count <= final_score:
                    needed_votes = final_score - vote_count + 1
                    cost += needed_votes
                else:
                    # already exceeds, cost 0
                    pass
                count += 1
            
            # But wait: we should take the M candidates that require the least cost
            # Currently, we're taking the M highest ones — which is correct because they need least boost
            # However, we may have more than M candidates; we want the M with smallest cost
            # Since higher vote counts need less cost, taking the top M by vote count gives the M with smallest cost
            # So our method is correct
            
            if count < M:
                # Cannot even select M candidates? (shouldn't happen since N>=M and we have N-1 others)
                cost = float('inf')
            else:
                # We have computed cost as sum for top M others
                pass
            
            if cost > R:
                # Even in worst case, cannot make M candidates exceed final_score -> safe
                found = True
                hi = x
            else:
                lo = x + 1
        
        if lo <= remaining_votes:
            ans[orig_idx] = lo
        else:
            # Check if candidate is already safe with x=0
            final_score = target
            R = remaining_votes
            cost = 0
            count = 0
            for vote_count in sorted(others, reverse=True):
                if count >= M:
                    break
                if vote_count <= final_score:
                    cost += final_score - vote_count + 1
                count += 1
            if count >= M and cost > R:
                ans[orig_idx] = 0
            else:
                ans[orig_idx] = -1
    
    print(*ans)

solve()