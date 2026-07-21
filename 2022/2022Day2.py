inpu = open('input.txt', 'r')
f = inpu.readlines()
nwe = []
for i in f:
    nwe.append(i.strip().split())

points = 0
pointmap = {
    'X':1,
    'Y':2,
    'Z':3
}
for i in nwe:
    points += pointmap.get(i[1])
    if (i[1] == 'X' and i[0] == 'C') or (i[1] == 'Y' and i[0] == 'A') or (i[1] == 'Z' and i[0] == 'B'):
        points += 6
    elif (i[1] == 'X' and i[0] == 'A') or (i[1] == 'Y' and i[0] == 'B') or (i[1] == 'Z' and i[0] == 'C'):
        points += 3
    else:
        continue
print(points)

points = 0
pointmap = {
    'X':0,
    'Y':3,
    'Z':6
}
for i in nwe:
    points += pointmap.get(i[1])
    if (i[1] == 'X' and i[0] == 'B') or (i[1] == 'Y' and i[0] == 'A') or (i[1] == 'Z' and i[0] == 'C'):
        points += 1
    elif (i[1] == 'X' and i[0] == 'C') or (i[1] == 'Y' and i[0] == 'B') or (i[1] == 'Z' and i[0] == 'A'):
        points += 2
    else:
        points += 3
print(points)
