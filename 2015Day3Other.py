with open('2015Day3Input.txt') as f:
    contents = str(f.readlines())
    currpos = [0, 0]
    beento = [currpos]
    index = 0
    while (index < len(contents)):
        if (contents[index] == '^'):
            currpos = [currpos[0], currpos[1] + 1]
        elif (contents[index] == 'v'):
            currpos = [currpos[0], currpos[1] - 1]
        elif (contents[index] == '>'):
            currpos = [currpos[0] + 1, currpos[1]]
        elif (contents[index] == '<'):
            currpos = [currpos[0] - 1, currpos[1]]
        beenhere = False
        for x in beento:
            if x[0] == currpos[0] and x[1] == currpos[1]:
                beenhere = True
                break
        if beenhere == False:
            beento.append(currpos)
        index = index + 2
    index = 1
    currpos=[0,0]
    while (index < len(contents)):
        if (contents[index] == '^'):
            currpos = [currpos[0], currpos[1] + 1]
        elif (contents[index] == 'v'):
            currpos = [currpos[0], currpos[1] - 1]
        elif (contents[index] == '>'):
            currpos = [currpos[0] + 1, currpos[1]]
        elif (contents[index] == '<'):
            currpos = [currpos[0] - 1, currpos[1]]
        beenhere = False
        for x in beento:
            if x[0] == currpos[0] and x[1] == currpos[1]:
                beenhere = True
                break
        if beenhere == False:
            beento.append(currpos)
        index = index + 2
answer = len(beento)
print (contents)
print(answer)