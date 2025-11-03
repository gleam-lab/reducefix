import sys

def main():
    data = sys.stdin.read().split()
    N = int(data[0])
    M = int(data[1])
    K = int(data[2])
    A = list(map(int, data[3:3+N]))
    
    total_counted = sum(A)
    remaining_votes = K - total_counted
    
    # If there are no remaining votes, we just check current state
    if remaining_votes == 0:
        # Count how many have more votes than candidate i
        ans = []
        for i in range(N):
            count_greater = 0
            for j in range(N):
                if A[j] > A[i]:
                    count_greater += 1
            if count_greater < M:
                ans.append(0)
            else:
                ans.append(-1)
        print(*ans)
        return
    
    # Special case: if M >= N, then at most N-1 can have more votes, so everyone wins with 0 extra
    if M >= N:
        print(*[0] * N)
        return
    
    # We need to compute for each candidate the minimum additional votes needed
    ans = [0] * N
    
    # We'll process each candidate independently
    for i in range(N):
        # Candidate i currently has A[i] votes
        current_votes = A[i]
        
        # We want to ensure that at most M-1 candidates have strictly more votes than candidate i
        # That is, at least N - (M - 1) = N - M + 1 candidates (including i) have <= A[i] + x votes
        
        # We are going to try to find the minimal x (additional votes for candidate i)
        # such that no matter how the remaining votes are distributed, 
        # at most M-1 candidates can have more votes than A[i]+x.
        
        # But note: we control only the votes given to candidate i. Others may get any of the rest.
        
        # To guarantee victory, we must assume worst-case distribution of other votes.
        # We need to make sure that even if other candidates get as many votes as possible,
        # still at most M-1 have more than A[i] + x.
        
        # Strategy:
        # Let’s suppose we give x votes to candidate i -> total = A[i] + x
        # The remaining (remaining_votes - x) votes can be distributed arbitrarily among others.
        # We want to prevent more than M-1 candidates from exceeding A[i]+x.
        
        # So, we ask: what is the minimal x such that it's impossible for M or more candidates 
        # (other than i) to get more than A[i]+x?
        
        # How many votes would it take for M other candidates to surpass A[i]+x?
        # For each candidate j != i, they start at A[j], and need at least (A[i]+x+1 - A[j]) votes to beat i.
        # But if A[j] > A[i]+x, they already beat i.
        
        # We consider: if we fix x, can an adversary use the remaining (remaining_votes - x) votes 
        # to make M candidates have > A[i]+x?
        
        # We need the smallest x such that even in the worst case, fewer than M candidates can exceed A[i]+x.
        
        # Alternatively: simulate giving x to i, then compute minimum total votes needed by other candidates 
        # to have M of them exceed A[i]+x. If that required amount > (remaining_votes - x), then x works.
        
        # So define:
        #   needed_votes_for_M_others = minimum total extra votes (beyond their current counts) 
        #   needed to bring M candidates (excluding i) to at least A[i]+x+1.
        
        # But note: some candidates might already exceed A[i]+x.
        
        # We can binary search on x in [0, remaining_votes], but N and K are large, so we need efficiency.
        
        # Instead, we can try to compute directly.
        
        # Idea: sort candidates by current votes (descending), excluding candidate i.
        # We want to know: what is the minimal x such that the number of candidates that can be pushed 
        # above A[i]+x using at most (remaining_votes - x) votes is less than M.
        
        # Actually, we can reframe: we need at most M-1 candidates to end up > A[i]+x.
        # So we can allow up to M-1 candidates to be boosted above A[i]+x.
        # The cost to boost a candidate j to A[i]+x+1 is max(0, A[i]+x+1 - A[j]).
        # But we cannot control distribution — adversary will minimize the cost to create M strong candidates.
        
        # Therefore, the minimal cost for the adversary to make M candidates beat i is:
        #   Take the M candidates (excluding i) that require the least extra votes to reach A[i]+x+1.
        #   Sum their costs.
        #
        # If that sum > (remaining_votes - x), then the adversary cannot make M candidates beat i → i wins.
        
        # So we need smallest x in [0, remaining_votes] such that:
        #   sum_{j in S} max(0, A[i]+x+1 - A[j]) > (remaining_votes - x)
        # where S is the set of M candidates (j ≠ i) with smallest values of max(0, A[i]+x+1 - A[j])
        #
        # But this depends on x, so we can binary search on x.
        
        lo, hi = 0, remaining_votes + 1
        result = -1
        
        # Precompute list of other candidates' votes
        others = []
        for j in range(N):
            if j != i:
                others.append(A[j])
        others.sort(reverse=True)  # descending order
        
        while lo <= hi:
            x = (lo + hi) // 2
            # How many votes needed to make M candidates (from others) exceed A[i] + x?
            threshold = A[i] + x + 1
            cost = 0
            count = 0
            # Consider top M candidates that are easiest to boost to threshold
            temp = []
            for vote in others:
                if vote < threshold:
                    temp.append(threshold - vote)
                else:
                    temp.append(0)
            temp.sort()  # ascending: pick the cheapest M
            cost = sum(temp[:M])
            
            # Available votes for others: remaining_votes - x
            if cost > remaining_votes - x:
                result = x
                hi = x - 1
            else:
                lo = x + 1
        
        if result == -1:
            ans[i] = -1
        else:
            ans[i] = result
    
    print(*ans)

if __name__ == '__main__':
    main()