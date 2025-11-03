N = int(input())
S = input().strip()

# Map each move to the move that beats it
win_move = {'R': 'P', 'P': 'S', 'S': 'R'}
opposite = {'R': 'S', 'S': 'P', 'P': 'R'}

# dp[i][move] will store the maximum wins up to game i, ending with move
# We'll use 0=R, 1=P, 2=S for indexing
dp = [[-1] * 3 for _ in range(N)]

def char_to_idx(c):
    return 0 if c == 'R' else 1 if c == 'P' else 2

def idx_to_char(idx):
    return 'R' if idx == 0 else 'P' if idx == 1 else 'S'

# Initialize first round
aoki_first = S[0]
winning_move = win_move[aoki_first]
losing_move = opposite[aoki_first]

# Can choose winning move (win) or same move (draw), but not losing move
for move_idx in range(3):
    move_char = idx_to_char(move_idx)
    if move_char == losing_move:
        continue  # Cannot lose
    if move_char == winning_move:
        dp[0][move_idx] = 1  # Win
    else:
        dp[0][move_idx] = 0  # Draw

# Fill DP table
for i in range(1, N):
    aoki_move = S[i]
    win_m = win_move[aoki_move]
    lose_m = opposite[aoki_move]
    
    for curr in range(3):
        curr_char = idx_to_char(curr)
        if curr_char == lose_m:
            continue  # Cannot lose
        
        # Get previous best that doesn't repeat the move
        best_prev = -1
        for prev in range(3):
            if prev == curr:  # Different from previous move
                continue
            if dp[i-1][prev] != -1:
                best_prev = max(best_prev, dp[i-1][prev])
        
        if best_prev == -1:
            continue
            
        # Add win if current move beats Aoki's move
        add = 1 if curr_char == win_m else 0
        dp[i][curr] = best_prev + add

print(max(dp[N-1]))