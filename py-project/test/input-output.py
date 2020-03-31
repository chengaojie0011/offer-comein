import sys
if __name__ == "__main__":
    while 1:
        N, M = list(map(int,input().split(" ")))
        res = []
        for i in range(M):
            a, b, c = map(int, input().split())
            if c == 1:
                r = [a, b] if a < b else [b, a]
                res.append(r)
                print(res)
        s = set()
        s.add(1)
        res.sort()
        print(res)
        for i in res:
            if i[0] in s:
                s.add(i[1])
        print(len(s) - 1)