N, M, K = map(int, input().split())
A = list(map(int, input().split()))

# Calculate the total number of votes already counted
total_votes_counted = sum(A)

# Initialize the result array with -1 (default value indicating failure)
C = [-1] * N

# Sort the votes in descending order along with their indices
sorted_A = sorted((v, i) for i, v in enumerate(A))

# Calculate the maximum number of votes needed to ensure a candidate's victory
max_needed = float('inf')
for i in range(M-1, -1, -1):
    # Calculate the threshold for the current candidate to win
    threshold = (total_votes_counted + sum(sorted_A[j][0] for j in range(i+1, M)) + K) // (M+1)
    if threshold > sorted_A[i][0]:
        max_needed = min(max_needed, threshold - sorted_A[i][0])

# Determine the minimum additional votes needed for each candidate
for i in range(N):
    if C[i] != -1:
        continue
    if sorted_A[i][0] >= max_needed:
        C[i] = 0
    else:
        C[i] = max_needed - sorted_A[i][0]

# Print the results
print(" ".join(map(str, C)))