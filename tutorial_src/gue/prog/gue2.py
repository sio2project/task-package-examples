from gue_lib import init, isGreater, answer

if __name__ == "__main__":
    start = 1
    end = init()
    while start < end:
        mid = (start + end) // 2
        if isGreater(mid):
            start = mid + 1
        else:
            end = mid
    answer(start)
