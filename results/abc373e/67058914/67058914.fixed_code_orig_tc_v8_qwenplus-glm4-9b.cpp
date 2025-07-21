function minimum_votes_needed(N, M, K, votes):
    sort(votes)  # Sort candidates based on votes received

    cumulative_votes = new array(N)
    cumulative_votes[0] = votes[0]

    for i from 1 to N-1:
        cumulative_votes[i] = cumulative_votes[i-1] + votes[i]

    remaining_votes = K - cumulative_votes[N-1]

    results = new array(N)
    for i from 0 to N-1:
        if votes[i] + remaining_votes >= N - M:
            results[i] = 0  # Already guaranteed victory
            continue

        additional_votes_needed = max(0, N - M - votes[i])
        additional_votes_needed = max(additional_votes_needed, votes[N-1] - votes[i] + 1)

        # Binary search to find the minimum additional votes
        low, high = 0, K
        while low < high:
            mid = (low + high + 1) / 2
            num_candidates_beaten = 0
            for j from 0 to N-1:
                if cumulative_votes[j] - cumulative_votes[i] >= mid:
                    num_candidates_beaten += 1

            if num_candidates_beaten >= M:
                high = mid - 1
            else:
                low = mid

        results[i] = low

    return results