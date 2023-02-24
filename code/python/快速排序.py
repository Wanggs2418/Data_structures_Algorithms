def quicksort(list):
    if len(list) < 2:
        return list
    else:
        privot = list[0]
        less = [i for i in list[1:] if i <= privot]
        greater = [i for i in list[1:] if i > privot]
    return quicksort(less) + [privot] + quicksort(greater)


def test():
    list1 = [-1, 3, 6, 6, 100, 0, -99]
    print(quicksort(list1))

if __name__ == "__main__":
    test()