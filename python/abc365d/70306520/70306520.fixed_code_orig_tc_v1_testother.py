N = int(input())
S = input().strip()

# Map for what move beats each of Aoki's moves
win_move = {'R': 'P', 'P': 'S', 'S': 'R'}
lose_move = {'R': 'S', 'P': 'R', 'S': 'P'}

# dp[i][j] will store the maximum wins up to game i, where j represents Takahashi's move in game i
# 0: Rock (R), 1: Paper (P), 2: Scissors (S)
dp = [[-1] * 3 for _ in range(N)]

# Initialize first game
aoki_first = S[0]
# Takahashi can choose any move except losing move
for move_idx, move_char in enumerate("RPS"):
    if move_char == lose_move[aoki_first]:
        continue  # Cannot choose a losing move
    if move_char == win_move[aoki_first]:
        dp[0][move_idx] = 1  # Win
    else:
        dp[0][move_idx] = 0  # Draw

# Fill DP table
for i in range(1, N):
    aoki_move = S[i]
    for curr in range(3):
        curr_char = "RPS"[curr]
        # Skip if this move loses to Aoki's move
        if curr_char == lose_move[aoki_move]:
            continue
        
        # Compute win value for current move
        win_val = 1 if curr_char == win_move[aoki_move] else 0
        
        # Transition from previous state with different move
        best_prev = -1
        for prev in range(3):
            if prev != curr and dp[i-1][prev] != -1:
                if dp[i-1][prev] > best_prev:
                    best_prev = dp[i-1][prev]
        
        if best_prev != -1:
            dp[i][curr] = best_prev + win_val

print(max(dp[N-1]))