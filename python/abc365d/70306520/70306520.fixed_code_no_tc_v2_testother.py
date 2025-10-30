N = int(input())
S = input().strip()

# Map each of Aoki's moves to the move Takahashi must play to win
win_move = {'R': 'P', 'P': 'S', 'S': 'R'}
# And to the move that results in a draw
draw_move = {'R': 'R', 'P': 'P', 'S': 'S'}

# dp[i][j] will store the maximum wins up to game i, where j represents Takahashi's move:
# 0: Rock, 1: Paper, 2: Scissors
dp = [[-1] * 3 for _ in range(N)]

# Initialize first game
for move_idx, move_char in enumerate("RPS"):
    if move_char == win_move[S[0]]:
        dp[0][move_idx] = 1  # Win
    elif move_char == draw_move[S[0]]:
        dp[0][move_idx] = 0  # Draw
    # Cannot lose, so no other options

# Fill DP table
for i in range(1, N):
    for curr in range(3):  # Current move
        curr_char = "RPS"[curr]
        # Determine outcome against Aoki's move
        if curr_char == win_move[S[i]]:
            base_score = 1
        elif curr_char == draw_move[S[i]]:
            base_score = 0
        else:
            continue  # Losing is not allowed
        
        # Check all valid previous moves (must be different)
        for prev in range(3):
            if prev == curr:
                continue  # Consecutive same moves not allowed
            if dp[i-1][prev] != -1:
                if dp[i][curr] < dp[i-1][prev] + base_score:
                    dp[i][curr] = dp[i-1][prev] + base_score

print(max(dp[N-1]))