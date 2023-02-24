def find_max(list):
    if len(list) == 2:
        return list[0] if list[0] > list[1] else list[1]
    sub_max = find_max(list[1:])
    return list[0] if list[0] > sub_max else sub_max


def test():
    list1 = [-1, 4, 234, 997, 0]
    a = find_max(list1)
    print("最大值为：{0}".format(a))


if __name__ == "__main__":
    test()