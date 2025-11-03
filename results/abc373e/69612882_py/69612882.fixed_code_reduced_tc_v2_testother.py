N, M, K = map(int, input().split())
A = list(map(int, input().split()))

# Calculate the total votes needed to elect M candidates
total_votes_needed = sum(sorted(A)[-M:])
remaining_votes = K - sum(A)

# Initialize the result array with -1
result = [-1] * N

# Iterate over each candidate
for i in range(N):
    # Calculate the minimum additional votes needed for candidate i to win
    min_additional_votes = max(0, (total_votes_needed - A[i] + M) // (M + 1))
    
    # Check if the remaining votes can cover the minimum additional votes needed
    if remaining_votes >= min_additional_votes:
        result[i] = min_additional_votes

# Print the result
print(' '.join(map(str, result)))