n = int(input())

for x in range(2):
    for i in range(n + x):
        print((n - i) * '.', end='')
        print((2 * (i + 1) - 1) * '#', end='')
        print((n - i) * '.')

for i in range(2):
    print(n * '.', end='')
    print('#', end='')
    print(n * '.')
