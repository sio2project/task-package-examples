n = int(input())

if n % 2 != 0:
    print("Can't do that")
    exit()

print(3 * n // 2)

i = 0
while i < n:
    print("%d 2 0" % i)
    print("%d 0 1" % i)
    print("%d 0 1" % (i + 1))
    i += 2
