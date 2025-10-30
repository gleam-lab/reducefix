import sys

def solve():
    data = sys.stdin.read().split()
    N = int(data[0])
    M = int(data[1])
    K = int(data[2])
    A = list(map(int, data[3:3+N]))
    
    total_counted = sum(A)
    remaining_votes = K - total_counted
    
    # If there are no remaining votes, we can only check current state
    if remaining_votes == 0:
        # Count how many have strictly more votes than candidate i
        ans = []
        for i in range(N):
            more_votes = sum(1 for j in range(N) if A[j] > A[i])
            if more_votes < M:
                ans.append(0)
            else:
                ans.append(-1)
        print(" ".join(map(str, ans)))
        return
    
    # Special case: if M >= N, then at most N-1 people can have more votes, so everyone wins
    if M >= N:
        print(" ".join(["0"] * N))
        return
        
    # We need to compute for each candidate the minimum additional votes needed
    ans = []
    
    # Sort candidates by current votes descending, keeping original index
    candidates = [(A[i], i) for i in range(N)]
    candidates.sort(reverse=True, key=lambda x: x[0])
    
    # For each candidate, determine the minimum X such that even in the worst-case distribution
    # of the remaining votes (excluding the X given to this candidate), 
    # the number of candidates with strictly more votes than candidate i is less than M.
    
    for i in range(N):
        a_i = A[i]
        orig_idx = i
        needed = 0
        
        # We try to find minimal X such that candidate i wins no matter how the rest (remaining_votes - X) are distributed
        # After giving X votes to candidate i, their total is a_i + X.
        # The adversary will try to make as many other candidates as possible exceed this value.
        
        # We want: number of candidates j != i with final_votes[j] > a_i + X  < M
        
        # So we must ensure that at most M-1 candidates can get above a_i + X.
        # That means we must "block" at least N - M + 1 candidates from exceeding a_i + X.
        # But note: we cannot control how votes are assigned except that we assign X to candidate i.
        
        # Alternate approach:
        # Let’s assume we give X votes to candidate i. Then the remaining votes R = remaining_votes - X
        # can be used to boost other candidates.
        # To prevent candidate i from winning, an opponent would try to make at least M candidates have > a_i+X votes.
        # So to guarantee victory, we must make it impossible to have M candidates with > a_i+X.
        
        # How? Consider all other candidates. We can simulate: what is the minimal X such that
        # even if we use up to R votes optimally to raise other candidates above a_i+X,
        # we cannot get M candidates above a_i+X?
        
        # Note: we can choose X. We want minimal X >= 0 such that:
        # It's impossible to assign R = remaining_votes - X votes among the other N-1 candidates
        # to make M of them have vote count > a_i + X.
        
        # Strategy: sort other candidates by current votes.
        # To create a candidate j with > a_i+X votes, we need max(0, a_i + X + 1 - A[j]) votes.
        # We want to know: can we make M candidates exceed a_i+X using at most R votes?
        # So sort other candidates by the cost to push them above a_i+X (ascending).
        # Sum the smallest M such costs. If that sum > R, then it's impossible -> candidate i wins.
        
        # We can binary search on X in [0, remaining_votes], but N and values are large.
        # Instead, we can try to compute directly.
        
        # However, note: we can also consider that if X is too small, then many candidates are already above or near a_i+X.
        
        # Alternative efficient idea:
        # Let’s fix candidate i. We want min X such that:
        #   sum_{j ≠ i} max(0, min(remaining_votes - X + 1, a_i + X + 1 - A[j])) ??? Not straightforward.
        
        # Better: simulate the worst-case scenario.
        # We want the minimal X such that the number of candidates that can be pushed above a_i+X 
        # with the remaining R = remaining_votes - X votes is at most M-1.
        
        # How many candidates can be pushed above threshold T = a_i + X?
        # For each j ≠ i, cost_j = max(0, T + 1 - A[j]) = max(0, a_i + X + 1 - A[j])
        # Sort cost_j for j ≠ i, take the M smallest, if their sum <= R = remaining_votes - X → then M candidates can be made to beat i → i loses.
        # So we need: sum of smallest M costs > remaining_votes - X → then i wins.
        
        # We want the minimal X such that:
        #   sum_{j in S} max(0, a_i + X + 1 - A[j]) > remaining_votes - X, where S is any set of M candidates from others.
        # Actually, we take the M cheapest ones.
        
        # But note: if there are fewer than M other candidates, then M-1 maximum can beat i → always wins.
        if N - 1 < M:
            ans.append(0)
            continue
            
        # List of costs for all j ≠ i to exceed a_i + X
        # But X is variable → cost depends on X.
        # Define f(X) = minimum total cost to make M other candidates exceed a_i + X
        # f(X) = sum of min(M, N-1) smallest values of max(0, a_i + X + 1 - A[j]) for j ≠ i
        # We need f(X) > remaining_votes - X
        # => f(X) + X > remaining_votes
        
        # f(X) is piecewise linear and non-decreasing in X.
        # So left-hand side is increasing in X → we can binary search on X in [0, remaining_votes+1]
        
        lo, hi = 0, remaining_votes + 1
        best = -1
        
        while lo <= hi:
            mid = (lo + hi) // 2
            T = a_i + mid  # candidate i's total
            costs = []
            for j in range(N):
                if j == i:
                    continue
                # votes needed for j to exceed T
                need = T + 1 - A[j]
                if need > 0:
                    costs.append(need)
                # else 0, but we don't need to add 0s because they don't contribute
            costs.sort()
            total_cost = sum(costs[:M]) if len(costs) >= M else sum(costs)
            
            if total_cost > remaining_votes - mid:
                best = mid
                hi = mid - 1
            else:
                lo = mid + 1
                
        if best == -1:
            ans.append(-1)
        else:
            ans.append(best)
            
    print(" ".join(map(str, ans)))

solve()