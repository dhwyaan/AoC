inpu = open('input.txt','r')
f = inpu.readlines()
points = 0
for i in f:
    i.strip()
    dat = [i[0 : int(len(i)/2)] , i[int(len(i)/2) : len(i)]]
    for j in dat[0]:
        if j in dat[1]:
            if j.isupper():
                points += ord(j)-ord('A')+1+26
            else:
                points += ord(j)-ord('a')+1
            break
print(points)

points = 0
for i in range(0, len(f)-2, 3):
    line = f[i]
    for j in line:
        if ((j in f[i+1]) and (j in f[i+2])):
            if j.isupper():
                points += ord(j)-ord('A')+1+26
            else:
                points += ord(j)-ord('a')+1
            break
print(points)
