total = 0
with open("2015Day2Input.txt") as fileIn:
    for line in fileIn:
        l, b, h = [int(s) for s in line.split('x')]
        total = total + min([2*l+2*h,2*l+2*b,2*b+2*h]) + l*b*h
print(total)