N = 0
X = 0

def init():
    global N
    global X
    print("Input n: ")
    N = int(input())
    print("Input secret number: ")
    X = int(input())
    
    return N

def isGreater(x):
    global X
    print("Query: " + str(x));
    return X > x;

def answer(x):
    global X
    if x == X:
        print("Program guessed correctly!")
    else:
        print("Program answered " + str(x) + ", while the correct answer is " + str(X));
