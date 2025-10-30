N, M, K = map(int, input().split())
A = list(map(int, input().split()))

# Calculate the total votes received by the top M candidates
top_m_votes = sum(sorted(A)[-M:])

# Calculate the maximum additional votes needed by any candidate to ensure they are ahead of the second-place candidate
max_needed = float('inf')
for vote_count in A:
    needed = max(0, (top_m_votes + vote_count + K - sum(A)) // (M + 1) - vote_count)
    max_needed = min(max_needed, needed)

# Determine the result for each candidate
result = []
for vote_count in A:
    if vote_count > top_m_votes:
        result.append(0)
    elif vote_count + max_needed > top_m_votes:
        result.append(vote_count + max_needed - top_m_votes)
    else:
        result.append(-1)

# Output the results
print(" ".join(map(str, result)))