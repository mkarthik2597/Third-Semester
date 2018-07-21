def Symbol(Pattern):
    if Pattern=="A":
        return 0
    elif Pattern=="C":
        return 1
    elif Pattern=="G":
        return 2
    else:
        return 3


def PatternToNumber(Pattern):
    if len(Pattern)==1:
        return Symbol(Pattern)

    return 4*PatternToNumber(Pattern[:-1])+Symbol(Pattern[-1:])

print PatternToNumber("TTGTGGATGGGTACCGACG")
