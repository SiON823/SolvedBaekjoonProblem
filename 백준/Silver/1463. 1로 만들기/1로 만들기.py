N=int(input())
dp={1:0}
def go(n):
    if n in dp.keys():
        return dp[n]
    if (n%3==0) and (n%2==0):
        dp[n] = min(go(n//3)+1, go(n//2)+1)
    elif n%3==0:
        dp[n] = min(go(n//3)+1, go(n-1)+1)
    elif n%2==0:
        dp[n] = min(go(n//2)+1, go(n-1)+1)
    else:
        dp[n] = go(n-1)+1
    return dp[n]

print(go(N))