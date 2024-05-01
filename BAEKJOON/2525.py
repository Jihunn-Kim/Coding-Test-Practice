A, B = map(int, input().split())
C: int = int(input())

curTime: int = A * 60 + B
endTime: int = curTime + C

answerA: int = (endTime // 60) % 24
answerB: int = endTime % 60

print(answerA, end = ' ')
print(answerB, end = ' ')
