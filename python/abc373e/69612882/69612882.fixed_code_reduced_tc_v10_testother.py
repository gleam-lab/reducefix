import sys

def main():
    input = sys.stdin.read
    data = input().split()
    
    index = 0
    N = int(data[index])
    M = int(data[index + 1])
    K = int(data[index + 2])
    index += 3
    
    A = []
    for _ in range(N):
        A.append(int(data[index]))
        index += 1
    
    # Sort candidates by votes in descending order
    sorted_candidates = sorted(range(N), key=lambda x: A[x], reverse=True)
    
    # Calculate the total votes needed to elect M candidates
    S = sum(A[:M])
    
    # Calculate the remaining votes available
    remaining_votes = K - sum(A)
    
    # Initialize the result array
    results = [-1] * N
    
    # Determine the minimum additional votes needed for each candidate
    for i in range(N):
        if i < M:
            # The top M candidates need no additional votes to win
            results[sorted_candidates[i]] = 0
        else:
            # Calculate the maximum votes other candidates can get
            max_other_votes = sum(A[j] for j in range(M) if j != sorted_candidates[i])
            
            # Calculate the minimum votes needed to win
            min_votes_needed = (S + max_other_votes + remaining_votes + 1) // (M + 1)
            
            # Calculate the additional votes needed
            additional_votes_needed = min_votes_needed - A[sorted_candidates[i]]
            
            # Ensure the additional votes do not exceed the remaining votes
            if additional_votes_needed > remaining_votes:
                additional_votes_needed = -1
            
            results[sorted_candidates[i]] = additional_votes_needed
    
    # Print the results
    print(" ".join(map(str, results)))

if __name__ == "__main__":
    main()