N = int(input())
S = input().strip()

# Map Aoki's move to the winning and losing moves for Takahashi
# For each of Aoki's moves, determine what Takahashi should play to win or draw
win_move = {'R': 'P', 'P': 'S', 'S': 'R'}  # Takahashi's move to win
lose_move = {'R': 'S', 'P': 'R', 'S': 'P'}  # Takahashi's move to lose (not allowed)

# We'll use DP where dp[i][j] = maximum wins up to game i, with Takahashi playing move j at game i
# Represent moves: 0 = Rock (R), 1 = Paper (P), 2 = Scissors (S)
# But we can work directly with characters for clarity

# To avoid using list of lists with characters, we use indices
move_to_idx = {'R': 0, 'P': 1, 'S': 2}
idx_to_move = ['R', 'P', 'S']

# dp[i][j] = max wins up to i-th game if Takahashi plays move j (by index) in game i
dp = [[-1] * 3 for _ in range(N)]

# Initialize first game
aoki_first = S[0]
winning_move = win_move[aoki_first]
drawing_move = aoki_first  # same move leads to draw

# Takahashi can choose any move except the one that loses
for move_idx in range(3):
    move_char = idx_to_move[move_idx]
    if move_char == lose_move[aoki_first]:
        continue  # cannot choose losing move
    if move_char == winning_move:
        dp[0][move_idx] = 1  # win
    else:  # it's a draw
        dp[0][move_idx] = 0

# Fill DP for remaining games
for i in range(1, N):
    aoki_move = S[i]
    win_m = win_move[aoki_move]
    lose_m = lose_move[aoki_move]
    
    for curr in range(3):
        curr_move = idx_to_move[curr]
        if curr_move == lose_m:
            continue  # cannot lose
        
        # Consider transitions from previous move
        best_prev = -1
        for prev in range(3):
            if prev == curr:  # consecutive same move not allowed
                continue
            if dp[i-1][prev] == -1:
                continue
            if dp[i-1][prev] > best_prev:
                best_prev = dp[i-1][prev]
        
        if best_prev == -1:
            continue  # no valid previous state
        
        # Add win if current move beats Aoki's move
        add = 1 if curr_move == win_m else 0
        dp[i][curr] = best_prev + add

# Answer is the maximum value in the last row
result = max(dp[N-1])
print(result)