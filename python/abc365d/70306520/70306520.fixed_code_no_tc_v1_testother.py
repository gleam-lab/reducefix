python
N = int(input())
S = input().strip()

# Map each of Aoki's moves to the move Takahashi must play to win
win_move = {'R': 'P', 'P': 'S', 'S': 'R'}
# Map each move to an index for DP: 0=R, 1=P, 2=S
move_to_idx = {'R': 0, 'P': 1, 'S': 2}

# dp[i][j] = maximum wins up to game i when Takahashi plays move j in game i
# We'll use a rolling array to save memory
prev_dp = [-1] * 3  # -1 means invalid/unreachable state

# Initialize first game
aoki_first = S[0]
for move in 'RPS':
    if move == win_move[aoki_first]:
        prev_dp[move_to_idx[move]] = 1  # win
    else:
        # Draw is allowed (never lost), but no win
        prev_dp[move_to_idx[move]] = 0

# Process each subsequent game
for i in range(1, N):
    curr_dp = [-1] * 3
    aoki_move = S[i]
    
    for curr_move in 'RPS':
        curr_idx = move_to_idx[curr_move]
        # Determine outcome against Aoki's move
        if curr_move == win_move[aoki_move]:
            win_bonus = 1
        else:
            win_bonus = 0  # draw is acceptable (not losing)
        
        # Try all possible previous moves (must be different)
        best_prev = -1
        for prev_move in 'RPS':
            prev_idx = move_to_idx[prev_move]
            if prev_move != curr_move and prev_dp[prev_idx] != -1:
                if prev_dp[prev_idx] > best_prev:
                    best_prev = prev_dp[prev_idx]
        
        if best_prev != -1:
            curr_dp[curr_idx] = best_prev + win_bonus
        # Otherwise stays -1 (invalid)
    
    prev_dp = curr_dp

print(max(prev_dp))