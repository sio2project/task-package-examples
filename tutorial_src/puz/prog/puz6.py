# No newlines after last line of output.

n = int(input())

if n % 2 != 0:
    print("Can't do that", end='')
    exit()

print(3 * n // 2)

i = 0
while i < n:
    print("%d 0 0" % i)
    print("%d 1 1" % i)
    if i < n - 2:
        print("%d 1 1" % (i + 1))
    else:
        print("%d 1 1" % (i + 1), end='')
    i += 2
