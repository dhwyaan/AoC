total = 0
with open("2015Day2Input.txt") as fileIn:
    for line in fileIn:
        l, b, h = [int(s) for s in line.split('x')]
        print(l,b,h)
        total = total + 2*l*b + 2*l*h + 2*b*h + min([l*b,l*h,b*h])
print(total)