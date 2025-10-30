import sys

def solve():
    N, M, K = map(int, input().split())
    A = list(map(int, input().split()))
    
    total_counted = sum(A)
    remaining_votes = K - total_counted
    
    # If there are no remaining votes, we just check current state
    if remaining_votes == 0:
        # Count how many have more votes than candidate i
        ans = []
        for i in range(N):
            more_votes = 0
            for j in range(N):
                if A[j] > A[i]:
                    more_votes += 1
            if more_votes < M:
                ans.append(0)
            else:
                ans.append(-1)
        print(*ans)
        return
    
    # Special case: if M >= N, then at most N-1 can have more votes, so everyone wins
    if M >= N:
        print(' '.join(['0'] * N))
        return
    
    # We need to compute for each candidate the minimum additional votes needed
    ans = [0] * N
    
    # For each candidate i, we want to ensure that at most M-1 candidates have more votes than i
    # That means we need to be at least M-th highest (or tied for it)
    
    for i in range(N):
        if remaining_votes == 0:
            # Already handled above, but just in case
            continue
            
        # Current votes of candidate i
        cur_votes = A[i]
        
        # We will simulate giving x additional votes to candidate i
        # and see what's the minimal x such that no matter how the other remaining votes are distributed,
        # at most M-1 candidates can have strictly more votes than candidate i.
        
        # How many candidates currently have more votes than candidate i?
        # But others can gain votes too, so we must consider worst-case distribution
        
        # Strategy:
        # To prevent candidate i from winning, an adversary would try to make as many candidates as possible
        # exceed candidate i's final vote count.
        # So we assume that after we give x votes to i, the remaining (remaining_votes - x) votes
        # are distributed optimally to other candidates to maximize the number exceeding candidate i.
        
        # Candidate i's final vote count = cur_votes + x
        # We want that at most M-1 other candidates can reach > (cur_votes + x)
        
        # Consider all other candidates j != i
        # For each j != i, we can give them extra votes up to their capacity (but only remaining_votes-x total)
        # The maximum votes candidate j can get is A[j] + (if we assign votes to them)
        
        # We want to know: what is the minimum x such that even in the worst case,
        # no more than M-1 candidates can exceed cur_votes + x?
        
        # Alternate approach:
        # Let T = cur_votes + x. We want at most M-1 candidates to be able to reach > T.
        # For a candidate j != i, the maximum they can reach is A[j] + (possibly some of the remaining votes)
        # But the total votes available for others is (remaining_votes - x)
        
        # How many candidates can possibly exceed T?
        # A candidate j can exceed T only if A[j] + allocation_j > T => allocation_j > T - A[j]
        # So if T - A[j] < 0, then even without extra votes, j already exceeds T.
        # Otherwise, we need to spend at least (T - A[j] + 1) votes on j to make them exceed T.
        
        # The adversary wants to maximize the number of candidates exceeding T,
        # using at most (remaining_votes - x) votes.
        
        # So we can simulate: sort the other candidates by the cost to push them over T.
        # But T depends on x, so we need to find minimal x such that the number of candidates
        # that can be pushed over T is at most M-1.
        
        # We can binary search on x in [0, remaining_votes]
        
        lo, hi = 0, remaining_votes
        result = -1
        
        while lo <= hi:
            mid = (lo + hi) // 2
            T = cur_votes + mid  # candidate i's final vote count
            votes_left_for_others = remaining_votes - mid
            
            if votes_left_for_others < 0:
                hi = mid - 1
                continue
                
            # Count how many candidates can be made to exceed T
            # For each j != i, compute min votes needed to make A[j] > T
            costs = []
            for j in range(N):
                if j == i:
                    continue
                # Votes needed to make candidate j exceed T
                need = T - A[j] + 1
                if need <= 0:
                    # Already exceeds T
                    continue
                if need <= votes_left_for_others:
                    costs.append(need)
            
            # Sort costs in increasing order
            costs.sort()
            count_exceed = 0
            total_cost = 0
            for cost in costs:
                if total_cost + cost <= votes_left_for_others:
                    total_cost += cost
                    count_exceed += 1
                else:
                    break
            
            # Also add those who already exceed T
            already_exceed = 0
            for j in range(N):
                if j != i and A[j] > T:
                    already_exceed += 1
            
            total_exceed = already_exceed + count_exceed
            
            if total_exceed < M:
                result = mid
                hi = mid - 1
            else:
                lo = mid + 1
        
        if result == -1:
            ans[i] = -1
        else:
            ans[i] = result
    
    print(*ans)

solve()