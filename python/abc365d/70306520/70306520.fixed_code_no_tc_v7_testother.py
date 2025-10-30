python
N = int(input())
S = input().strip()

# Mapping of what move beats Aoki's move
# If Aoki plays 'R' (Rock), Takahashi must play 'P' (Paper) to win
# If Aoki plays 'P' (Paper), Takahashi must play 'S' (Scissors) to win
# If Aoki plays 'S' (Scissors), Takahashi must play 'R' (Rock) to win
win_move = {'R': 'P', 'P': 'S', 'S': 'R'}

# dp[i][j] will store the maximum wins up to game i, where j represents Takahashi's move in game i
# Represent moves as: 0='R', 1='P', 2='S'
dp = [[-1] * 3 for _ in range(N)]

# Initialize first round
for j in range(3):
    move = "RPS"[j]
    if move == win_move[S[0]]:
        dp[0][j] = 1  # Win
    elif move == S[0]:
        dp[0][j] = 0  # Draw
    else:
        continue  # Loss is not allowed, so skip (remains -1)

# Fill DP table
for i in range(1, N):
    for curr in range(3):
        curr_move = "RPS"[curr]
        aoki_move = S[i]
        
        # Check if current move leads to loss
        if (curr_move == 'R' and aoki_move == 'P') or \
           (curr_move == 'P' and aoki_move == 'S') or \
           (curr_move == 'S' and aoki_move == 'R'):
            continue  # Loss not allowed
        
        # Determine points for this move
        point = 1 if curr_move == win_move[aoki_move] else 0
        
        # Transition from previous state with different move
        for prev in range(3):
            if prev == curr:  # Consecutive same move not allowed
                continue
            if dp[i-1][prev] != -1:
                if dp[i][curr] < dp[i-1][prev] + point:
                    dp[i][curr] = dp[i-1][prev] + point

print(max(dp[N-1]))