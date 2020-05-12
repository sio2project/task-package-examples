n = int(input())

if n % 2 != 0:
    print("Can't do that")
    exit()

print(3 * n // 2)

i = 0
while i < n:
    print("%d 0 0" % i)
    print("%d 1 0" % i)
    print("%d 2 0" % i)
    i += 2
