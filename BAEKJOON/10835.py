import sys

dp = [[-1] * 2001] * 2001


input = sys.stdin.readline
N = int(input())
input_left = list(map(int, input().split()))
input_right = list(map(int, input().split()))

def solve(left, right):
    if left < 0 or right < 0:
        return 0

    ret = dp[left][right]
    if ret != -1:
        return ret

    ret = 0
    # case 1
    ret = max(ret, solve(left - 1, right))
    ret = max(ret, solve(left - 1, right - 1))
    if input_left[left] > input_right[right]:
        ret = max(ret, solve(left, right - 1) + input_right[right])
    return ret
    
print(solve(N-1, N-1))