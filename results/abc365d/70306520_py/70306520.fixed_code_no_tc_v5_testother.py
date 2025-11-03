N = int(input())
S = input().strip()

# Map opponent's move to the winning move for Takahashi
winning_move = {'R': 'P', 'P': 'S', 'S': 'R'}
losing_move = {'R': 'S', 'P': 'R', 'S': 'P'}

# dp[i][j] where i is the index and j represents the move (0=R, 1=P, 2=S)
# We'll use a DP approach where we track the maximum wins up to position i ending with move j
dp = [[-1] * 3 for _ in range(N)]

# Initialize first round
for move_idx, move_char in enumerate("RPS"):
    if move_char != losing_move[S[0]]:  # Takahashi doesn't lose
        if move_char == winning_move[S[0]]:
            dp[0][move_idx] = 1  # win
        else:
            dp[0][move_idx] = 0  # draw

# Fill DP table
for i in range(1, N):
    current_opponent = S[i]
    winning = winning_move[current_opponent]
    drawing = current_opponent
    # Try each possible move for Takahashi at step i
    for curr_idx, curr_char in enumerate("RPS"):
        if curr_char == losing_move[current_opponent]:
            continue  # This move would make him lose, not allowed
        
        # Get reward for this move
        reward = 1 if curr_char == winning else 0
        
        # Check all valid previous moves (different from current)
        best_prev = -1
        for prev_idx in range(3):
            if prev_idx != curr_idx and dp[i-1][prev_idx] != -1:
                if dp[i-1][prev_idx] > best_prev:
                    best_prev = dp[i-1][prev_idx]
        
        if best_prev != -1:
            dp[i][curr_idx] = best_prev + reward

print(max(dp[N-1]))