caseNum: int = 1
calendar = [
    '',
    'Jan:',
    'Feb:',
    'Mar:',
    'Apr:',
    'May:',
    'Jun:',
    'Jul:',
    'Aug:',
    'Sep:',
    'Oct:',
    'Nov:',
    'Dec:'
]

while True:
    N: int = int(input())
    if N == 0:
        break

    answer = [0 for col in range(13)]
    for _ in range(N):
        C = list(map(int, input().split()))
        answer[C[1]] += 1

    caseStr: str = 'Case #' + str(caseNum) + ':'
    print(caseStr)

    for i in range(1, 13):
        calendarStr = calendar[i] + ('*' * answer[i])
        print(calendarStr)

    caseNum += 1


'''
birth = {1: "Jan:", 2: "Feb:", 3: "Mar:", 4: "Apr:",
             5: "May:", 6: "Jun:", 7: "Jul:", 8: "Aug:",
             9: "Sep:", 10: "Oct:", 11: "Nov:", 12: "Dec:"}
for _ in range(N):
    d, m, y = map(int, input().split())
    birth[m] += '*'
print("Case #{}:".format(t))     // string format, f
print(*birth.values(), sep='\n') // unpack dict_values and pass value to print(...) one by one
'''