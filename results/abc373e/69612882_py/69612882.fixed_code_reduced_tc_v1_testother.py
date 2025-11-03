import sys

input = sys.stdin.read
data = input().split()

N = int(data[0])
M = int(data[1])
K = int(data[2])

A = list(map(int, data[3:]))

# Sort candidates based on current votes in descending order
sorted_candidates = sorted(range(N), key=lambda x: A[x], reverse=True)

# Calculate the maximum number of votes needed to secure a win
max_votes_needed = float('inf')
for i in range(M):
    max_votes_needed = min(max_votes_needed, A[sorted_candidates[i]])

# Calculate the total votes currently counted
current_total_votes = sum(A)

# Calculate the remaining votes to be counted
remaining_votes = K - current_total_votes

# Initialize the result array
result = [-1] * N

# Determine the minimum additional votes needed for each candidate
for i in range(N):
    if A[i] > max_votes_needed:
        # Candidate i can already secure a win
        result[i] = 0
    elif A[i] + remaining_votes >= max_votes_needed + 1:
        # Candidate i can secure a win with the remaining votes
        result[i] = max_votes_needed + 1 - A[i]

# Output the results
print(" ".join(map(str, result)))