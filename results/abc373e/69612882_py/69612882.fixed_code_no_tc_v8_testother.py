import sys

def solve():
    N, M, K = map(int, input().split())
    A = list(map(int, input().split()))
    
    total_counted = sum(A)
    remaining_votes = K - total_counted
    
    # If there are no remaining votes, we just check current status
    if remaining_votes == 0:
        # Count how many have more votes than candidate i
        ans = [0] * N
        for i in range(N):
            count_better = sum(1 for j in range(N) if A[j] > A[i])
            if count_better >= M:
                ans[i] = -1
            else:
                ans[i] = 0
        print(*ans)
        return
    
    # Special case: if M == N, then everyone wins (since less than N people can't have more votes)
    if M == N:
        print(*[0] * N)
        return
    
    # We'll compute for each candidate the minimum additional votes needed
    ans = [0] * N
    
    # Create list of (votes, original_index) and sort by votes descending
    candidates = [(A[i], i) for i in range(N)]
    candidates.sort(reverse=True)
    
    # For each candidate, determine minimum votes to guarantee election
    for votes, orig_idx in candidates:
        # How many candidates currently have strictly more votes than this candidate?
        # But we need to ensure that at most M-1 candidates end up with more votes
        
        # Worst-case scenario: all other candidates get as many votes as possible
        # to try to beat this candidate
        
        # We assume that we give x additional votes to candidate orig_idx
        # Then we want that at most M-1 candidates have > (A[orig_idx] + x) votes
        
        # So we need to "beat" at least N-M+1 candidates (i.e., have at least as many votes as them)
        
        # Let's consider: what is the minimal x such that even in worst case,
        # no more than M-1 candidates can exceed A[orig_idx] + x?
        
        # Strategy:
        # Suppose we give x votes to candidate i.
        # Then the opponents will try to assign the remaining (remaining_votes - x) votes
        # to maximize the number of candidates who exceed A[i] + x.
        
        # To prevent that, we must make x large enough so that even if others get votes optimally,
        # at most M-1 candidates can surpass A[i]+x.
        
        # We can use binary search on x for each candidate, but that might be too slow.
        # Instead, we can use a greedy strategy.
        
        current = A[orig_idx]
        # We want: number of candidates j != i such that final_votes[j] > current + x <= M-1
        # In worst case, other candidates get distributed optimally to maximize those exceeding current+x
        
        # How many candidates could possibly exceed current + x?
        # We simulate: after giving x to candidate i, we have R = remaining_votes - x left
        # These R votes can be distributed arbitrarily among the other N-1 candidates.
        # We want to know: what's the maximum number of other candidates that can reach > current + x?
        
        # This is equivalent to: start from current vote counts, and distribute R votes to others
        # to maximize count of j where final_votes[j] > current + x.
        
        # The optimal way to maximize the count is to greedily push candidates just above the threshold.
        
        # However, we can reframe: we want the smallest x such that it's impossible for M candidates 
        # (other than i) to exceed current + x.
        
        # That is: even if we used all remaining_votes - x to help other candidates,
        # we cannot make M or more candidates exceed current + x.
        
        # How much does it cost to make one candidate j exceed current + x?
        # If A[j] <= current + x, then we need at least (current + x - A[j] + 1) votes to push j above.
        # But if A[j] > current + x already, then 0 cost.
        
        # So total cost to make M candidates exceed current + x is the sum of the smallest M costs
        # among j != i.
        
        # We want: total_cost > remaining_votes - x
        # => then it's impossible to have M candidates exceed current+x, so candidate i is safe.
        
        # So we want smallest x >= 0 such that:
        #   sum_{j in S} max(0, current + x - A[j] + 1) > remaining_votes - x
        # where S is the set of M smallest-cost candidates among j != i.
        
        # Note: if x is very large, LHS grows linearly with coefficient (# of j with A[j] <= current+x)
        # which eventually exceeds any RHS.
        
        # But note: if there are already M or more candidates with votes > current, even before adding votes,
        # then unless we can overtake some, we may not win. But our condition accounts for that.
        
        # We'll do binary search on x in range [0, remaining_votes + 1] (and beyond? but x cannot exceed remaining_votes)
        # Actually x can be at most remaining_votes, since only that many votes exist.
        
        lo, hi = 0, remaining_votes + 1
        best = -1
        
        while lo <= hi:
            mid = (lo + hi) // 2
            if mid > remaining_votes:
                break
                
            # Can candidate orig_idx secure victory with mid additional votes?
            my_votes = current + mid
            other_votes_left = remaining_votes - mid
            
            # If negative, invalid
            if other_votes_left < 0:
                hi = mid - 1
                continue
                
            # Compute minimum votes needed to make M different candidates (not orig_idx) exceed my_votes
            costs = []
            for j in range(N):
                if j == orig_idx:
                    continue
                if A[j] > my_votes:
                    # Already exceeds, cost 0
                    costs.append(0)
                else:
                    # Need A[j] + c > my_votes => c >= my_votes - A[j] + 1
                    cost = my_votes - A[j] + 1
                    costs.append(cost)
            
            # Sort costs ascending and take sum of smallest M
            costs.sort()
            min_total_cost = sum(costs[:M])
            
            # If min_total_cost > other_votes_left, then it's impossible to have M candidates exceed me
            # so I am guaranteed to have at most M-1 candidates above me -> I win
            if min_total_cost > other_votes_left:
                best = mid
                hi = mid - 1
            else:
                lo = mid + 1
        
        if best == -1:
            ans[orig_idx] = -1
        else:
            ans[orig_idx] = best
    
    print(*ans)

solve()