N, M, K = map(int, input().split())
A = list(map(int, input().split()))

# Initialize variables
total_votes = sum(A)
remaining_votes = K - total_votes
sorted_candidates = sorted(range(N), key=lambda x: (-A[x], x))

# Calculate the minimum additional votes needed for each candidate
results = []
for i in range(N):
    # Calculate the maximum number of votes other candidates can get
    max_other_votes = sum(A[j] for j in range(N) if j != i and A[j] > A[i]) + remaining_votes
    # Calculate the minimum votes needed for candidate i to win
    min_votes_needed = max((max_other_votes // M) * (M + 1) - A[i], 0)
    results.append(min_votes_needed)

# Output the results
print(' '.join(map(str, results)))