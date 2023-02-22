def find_smallest(arr):
    """
    参数：数组
    返回值：最小值的数组索引
    """
    smallest = arr[0]
    smallest_index = 0
    for x in range(1, len(arr)):
        if arr[x] < smallest:
            smallest = arr[x]
            smallest_index = x
    return smallest_index


def selection_sort(arr):
    new_arr = []
    for x in range(len(arr)):
        smallest = find_smallest(arr)
        new_arr.append(arr.pop(smallest))
    return new_arr


def test():
    arr = [24234, 4325, -4, 2, 5, 2, 45, 3, 263, 235]
    print('before:', arr)
    print('after:', selection_sort(arr))

if __name__ == "__main__":
    test()
