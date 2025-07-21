// Read input
n, m, k = input()
a = [votes for votes in input()]

// Sort candidates by votes received
sorted_candidates = sort(a)

// Calculate prefix sum of sorted votes
prefix_sum = [0] * (n + 1)
for i in range(1, n + 1):
    prefix_sum[i] = prefix_sum[i-1] + sorted_candidates[i-1]

// Calculate minimum votes needed for each candidate
for each candidate in sorted_candidates:
    m_minus_one = m - 1
    if candidate > m_minus_one:
        votes_needed = m_minus_one - candidate
    else:
        votes_needed = 0

    // Check if it is possible to guarantee victory
    if votes_needed > (k - sum(a)):
        print(-1)
    else:
        print(votes_needed)