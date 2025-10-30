N, M, K = map(int, input().split())
A = list(map(int, input().split()))

# Initialize variables
total_votes = sum(A)
remaining_votes = K - total_votes
sorted_candidates = sorted(range(N), key=lambda x: A[x], reverse=True)

# Determine the minimum votes needed for each candidate to ensure victory
for i in range(N):
    # Calculate the maximum votes other candidates can get without affecting this candidate's victory
    max_votes_others = sum(A[j] for j in range(M)) + remaining_votes - A[i]
    
    # Calculate the minimum votes required for this candidate to win
    min_votes_needed = (max_votes_others // M) * (M + 1) - A[i] + 1
    
    # Adjust if the calculation results in negative votes
    if min_votes_needed < 0:
        min_votes_needed = 0
    
    # Assign the result to the corresponding candidate
    A[sorted_candidates[i]] = min_votes_needed

# Output the results
print(" ".join(str(a) for a in A))