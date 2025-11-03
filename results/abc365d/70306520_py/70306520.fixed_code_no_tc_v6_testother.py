N = int(input())
S = input().strip()

# Map opponent's move to the winning counter move
win_move = {'R': 'P', 'P': 'S', 'S': 'R'}
lose_move = {'R': 'S', 'P': 'R', 'S': 'P'}

# dp[i][j] will store the maximum wins up to game i, where j represents Takahashi's move in game i
# 0: Rock, 1: Paper, 2: Scissors
dp = [[-1] * 3 for _ in range(N)]

def get_move_index(move):
    return {'R': 0, 'P': 1, 'S': 2}[move]

def get_move_char(idx):
    return ['R', 'P', 'S'][idx]

# Initialize first game
opp_first = S[0]
winning_move = win_move[opp_first]
losing_move = lose_move[opp_first]

# Can choose winning move (win) or same as opponent (draw), but not losing move
for m in range(3):
    move_char = get_move_char(m)
    if move_char == losing_move:
        continue  # Cannot choose losing move
    dp[0][m] = 1 if move_char == winning_move else 0

# Fill DP table
for i in range(1, N):
    opp_move = S[i]
    win_m = win_move[opp_move]
    lose_m = lose_move[opp_move]
    
    for curr in range(3):
        curr_char = get_move_char(curr)
        if curr_char == lose_m:
            continue  # Invalid: would lose
        
        # Try to come from each possible previous move
        best_prev = -1
        for prev in range(3):
            if prev == curr:  # Consecutive moves must be different
                continue
            if dp[i-1][prev] == -1:
                continue
            best_prev = max(best_prev, dp[i-1][prev])
        
        if best_prev == -1:
            continue  # No valid previous state
            
        # Add win if current move beats opponent
        win_bonus = 1 if curr_char == win_m else 0
        dp[i][curr] = best_prev + win_bonus

print(max(dp[N-1]))