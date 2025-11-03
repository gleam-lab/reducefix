N = int(input())
S = input().strip()

# Map each of Aoki's moves to the winning move for Takahashi
win_move = {'R': 'P', 'P': 'S', 'S': 'R'}
lose_move = {'R': 'S', 'P': 'R', 'S': 'P'}

# dp[i][move] will store the maximum wins up to game i, where move is last move (0=R, 1=P, 2=S)
# We use 0: R, 1: P, 2: S
dp = [[-1] * 3 for _ in range(N)]

def get_win_value(taka_move, aoki_move):
    if taka_move == win_move[aoki_move]:
        return 1
    elif taka_move == aoki_move:
        return 0  # draw
    else:
        return -10**9  # invalid (loss)

# Initialize first game
for move_idx in range(3):
    taka_move = "RPS"[move_idx]
    result = get_win_value(taka_move, S[0])
    if result >= 0:  # valid: win or draw
        dp[0][move_idx] = result

# Fill DP table
for i in range(1, N):
    for curr in range(3):
        taka_curr = "RPS"[curr]
        if get_win_value(taka_curr, S[i]) < 0:
            continue  # Skip losing moves
        for prev in range(3):
            if prev == curr:
                continue  # Consecutive same move not allowed
            if dp[i-1][prev] != -1:
                dp[i][curr] = max(dp[i][curr], dp[i-1][prev] + get_win_value(taka_curr, S[i]))

print(max(dp[N-1]))