# 有序列表
def binary_search(list, item):
    """
    参数：
    list -- 待查找的列表
    item -- 查找的数值

    返回值：
    返回要查找对象所处列表的位置
    """
    low = 0
    high = len(list) - 1
    while low <= high:
        # python 会自动向下取整
        mid = (low + high) // 2
        guess = list[mid]
        if guess == item:
            return mid
        if guess > item:
            high = mid - 1
        else:
            low = mid + 1
    return None


# 测试函数
def test():
    demo_list = [1, 3, 5, 7, 9]
    print(binary_search(demo_list, 5))


if __name__ == "__main__":
    test()
