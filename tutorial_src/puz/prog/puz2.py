n = int(input())

if n % 2 != 0:
    print("Can't do that")
    exit()

print(3 * n // 2)

i = 0
while i < n:
    print("%d %d 0" % (i, i))
    print("%d %d 1" % (i, i + 1))
    print("%d %d 1" % (i + 1, i + 1))
    i += 2
