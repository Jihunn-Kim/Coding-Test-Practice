L, P = map(int, input().split())
participant: int = L * P

articles = input().split()
for number in articles:
    print(int(number) - participant, end=' ')
