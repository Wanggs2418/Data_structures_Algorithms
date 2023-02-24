# 使用双端队列
from collections import deque


graph = {}
graph['you'] = ['bob','alice','claire']
graph['bob'] = ['anuj','peggr']
graph['alice'] = ['peggr']
graph['claire'] = ['thom','jonnr']
graph['anuj'] = []
graph['peggr'] = []
graph['jonny'] = []
graph['thom'] = []

# 判断是否是水果商贩
def person_is_seller(name):
    if name[-1] == "m":
        return True


def search(name):
    search_queue = deque()
    search_queue += graph[name]
    searched = []
    while search_queue:
        person = search_queue.popleft()
        if person not in searched:
            if person_is_seller(person):
                print("{0} is seller".format(person))
                return True
            else:
                search_queue += graph[person]
                searched.append(person)
    return False

def test():
    search('you')


if __name__ == "__main__":
    test()