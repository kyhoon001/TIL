a = int(input())
b = list(map(int, input().split()))
c = 0
new_point = []

for i in b:
    c += i

avg_old = c / a

for i in b:
    new_point.append(i / max(b) * 100)

print("%0.2f" % (sum(new_point) / a))