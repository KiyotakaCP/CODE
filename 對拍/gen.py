from random import randint

n = randint(1, 100)
mp = {}
print(n)
for i in range(n):
    l = randint(1, 99)
    r = randint(l + 1, 100)
    while mp.get((l, r)) != None:
        l = randint(1, 99)
        r = randint(l + 1, 100)
    mp[(l, r)] = 1

    print(l, r)