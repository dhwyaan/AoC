with open('2015Day3Input.txt') as f:
    contents = f.readlines()
    currpos = dict(xpos= 0, ypos= 0)
    beento = set(currpos)
    index = 0
    while (index<=len(contents)):
        newx = 0
        newy = 0
        if (contents(index) == '^'):
            newy = currpos.get("ypos")+1
        elif (contents(index) == 'v'):
            newy = currpos.get("ypos")-1
        if (contents(index) == '>'):
            newx = currpos.get("xpos")+1
        elif (contents(index) == '<'):
            newx = currpos.get("xpos")-1
        currpos.update({"xpos": newx})
        currpos.update({"ypos": newy})
        for x in beento:
            if (currpos==x):
                break

        index++