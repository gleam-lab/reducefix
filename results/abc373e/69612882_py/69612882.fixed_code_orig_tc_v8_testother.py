import sys

def solve():
    N, M, K = map(int, sys.stdin.readline().split())
    A = list(map(int, sys.stdin.readline().split()))
    
    total_votes_so_far = sum(A)
    remaining_votes = K - total_votes_so_far
    
    # If all candidates can be elected (M == N), then everyone already wins
    if M >= N:
        print(" ".join(["0"] * N))
        return
    
    # Create list of (votes, original_index) and sort in descending order
    candidates = [(A[i], i) for i in range(N)]
    candidates.sort(reverse=True)
    
    # We need to ensure candidate i has fewer than M candidates with more votes
    # This means they must be in the top M positions (0-indexed: positions 0 to M-1)
    
    result = [0] * N
    
    # For each candidate, calculate minimum additional votes needed
    for votes, orig_idx in candidates:
        # Current rank is determined by how many have strictly more votes
        # But we need to simulate worst-case distribution of remaining votes
        
        # We'll use binary search on the number of additional votes needed
        lo, hi = 0, remaining_votes + 1
        
        while lo < hi:
            mid = (lo + hi) // 2
            my_final_votes = votes + mid
            
            # Count how many candidates can have more votes than me in worst case
            # Distribute remaining votes optimally to maximize number of candidates > me
            remaining_after_me = remaining_votes - mid
            if remaining_after_me < 0:
                hi = mid
                continue
                
            # Count candidates that can potentially have more votes than me
            count_greater = 0
            for other_votes, _ in candidates:
                if other_votes > my_final_votes:
                    count_greater += 1
                elif other_votes == my_final_votes:
                    # They need at least one more vote to beat me
                    if remaining_after_me > 0:
                        count_greater += 1
                        remaining_after_me -= 1
                else:
                    # other_votes < my_final_votes
                    # Can they surpass me? Only if they get enough votes
                    needed = my_final_votes - other_votes + 1
                    if remaining_after_me >= needed:
                        count_greater += 1
                        remaining_after_me -= needed
            
            if count_greater < M:
                hi = mid
            else:
                lo = mid + 1
        
        result[orig_idx] = lo if lo <= remaining_votes else -1
    
    print(" ".join(map(str, result)))

solve()