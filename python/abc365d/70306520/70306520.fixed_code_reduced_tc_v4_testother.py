N = int(input())
S = input().strip()

# Mapping of what move beats Aoki's move
# If Aoki plays 'R' (Rock), Takahashi should play 'P' (Paper) to win
# If Aoki plays 'P' (Paper), Takahashi should play 'S' (Scissors) to win
# If Aoki plays 'S' (Scissors), Takahashi should play 'R' (Rock) to win
win_move = {'R': 'P', 'P': 'S', 'S': 'R'}

# Opponent's move -> index mapping
idx_map = {'R': 0, 'P': 1, 'S': 2}

# dp[i][j] will represent the maximum wins up to game i, ending with move j
# j: 0=R, 1=P, 2=S
dp = [[-1] * 3 for _ in range(N)]

# Initialize first round
for j in range(3):
    move = "RPS"[j]
    if move == win_move[S[0]]:
        dp[0][j] = 1  # Win
    elif move == S[0]:
        dp[0][j] = 0  # Draw
    else:
        dp[0][j] = -1  # Not allowed (loss)

# Fill DP table
for i in range(1, N):
    for j in range(3):
        move = "RPS"[j]
        current_result = -1
        
        # Check if this move is valid against Aoki's move
        if move == win_move[S[i]]:
            current_result = 1  # Win
        elif move == S[i]:
            current_result = 0  # Draw
        else:
            continue  # Loss not allowed
        
        # Transition from previous state with different move
        best_prev = -1
        for k in range(3):
            if k != j and dp[i-1][k] != -1:
                if dp[i-1][k] > best_prev:
                    best_prev = dp[i-1][k]
        
        if best_prev != -1:
            dp[i][j] = best_prev + current_result
        else:
            dp[i][j] = -1

# Find maximum wins from last round
result = max(dp[N-1])
print(result)