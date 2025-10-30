N = int(input())
S = input().strip()

# Map each move to its winning counter-move
win_move = {'R': 'P', 'P': 'S', 'S': 'R'}
lose_move = {'R': 'S', 'P': 'R', 'S': 'P'}

# dp[i][j] will store the maximum wins up to game i, where j represents the move at game i
# 0: Rock (R), 1: Paper (P), 2: Scissors (S)
dp = [[-1] * 3 for _ in range(N)]

# Initialize first game
for j in range(3):
    move_char = "RPS"[j]
    if move_char != lose_move[S[0]]:  # Takahashi doesn't lose
        dp[0][j] = 1 if move_char == win_move[S[0]] else 0

# Fill DP table
for i in range(1, N):
    for curr in range(3):
        curr_move = "RPS"[curr]
        # Check if current move loses
        if curr_move == lose_move[S[i]]:
            continue  # Invalid: Takahashi loses
        
        win_increment = 1 if curr_move == win_move[S[i]] else 0
        
        # Try all previous moves that are different from current
        best_prev = -1
        for prev in range(3):
            if prev != curr and dp[i-1][prev] != -1:
                if dp[i-1][prev] > best_prev:
                    best_prev = dp[i-1][prev]
        
        if best_prev != -1:
            dp[i][curr] = best_prev + win_increment

print(max(dp[N-1]))