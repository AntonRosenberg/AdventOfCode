def is_safe(seq):
    if seq[1] - seq[0] > 0:
        decreasing = False
    elif seq[1] - seq[0] < 0:
        decreasing = True

    for i in range(len(seq)-1):
        diff = seq[i+1] - seq[i]
        if diff < 0 and not decreasing or abs(diff) > 3 or diff == 0:
            return False
        elif diff > 0 and decreasing or abs(diff) > 3 or diff == 0:
            return False
        if i == len(seq) - 2:
            return True
    return False

if __name__ == "__main__":
    with open("input", "r") as f:
        inputs = f.readlines()
        inputs = [list(map(int, l.strip("\n").split(" "))) for l in inputs]

    correct = 0
    correct_remove = 0
    
    for seq in inputs:
        if is_safe(seq):
            correct += 1
            correct_remove += 1
        else:
            for ind, num in enumerate(seq):
                tmpSeq = list(seq)
                tmpSeq.pop(ind)
                if is_safe(tmpSeq):
                    correct_remove += 1
                    break
    
    print("Part1: ", correct)
    print("Part2: ", correct_remove)
    