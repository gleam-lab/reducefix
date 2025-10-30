def min_additional_votes(N, M, K, A):
    # Calculate the total number of votes currently counted
    current_total_votes = sum(A)
    
    # Sort the votes in descending order along with their indices
    sorted_votes = sorted([(v, i) for i, v in enumerate(A)], reverse=True)
    
    # Calculate the maximum number of votes any candidate can have after all votes are counted
    max_possible_votes = K
    
    # Calculate the sum of votes for the top M candidates
    top_M_sum = sum(sorted_votes[i][0] for i in range(M))
    
    # Initialize the result array
    result = [-1] * N
    
    # Iterate over each candidate
    for i in range(N):
        # Calculate the minimum number of additional votes needed for candidate i to win
        # If candidate i is one of the top M candidates
        if i < M:
            needed_votes = ((top_M_sum + max_possible_votes + 1) // (M + 1)) - sorted_votes[i][0]
        else:
            needed_votes = ((top_M_sum + max_possible_votes + 1) // (M + 1)) - sorted_votes[i][0]
        
        # Check if the needed votes are valid
        if needed_votes >= 0 and needed_votes <= K - current_total_votes:
            result[sorted_votes[i][1]] = needed_votes
        else:
            result[sorted_votes[i][1]] = 0
    
    return result

# Read input
N, M, K = map(int, input().split())
A = list(map(int, input().split()))

# Get the result
result = min_additional_votes(N, M, K, A)

# Print the result
print(" ".join(str(x) for x in result))