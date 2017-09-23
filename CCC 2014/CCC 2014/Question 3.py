# smallest = 1
# smallestTrack = undef
# Test if current == smallest, if so, increment position and smallest
# if current > smallest, test if current > smallestTrack, if so, impossible
# if current < smallestTrack, set smallestTrack to current

T = int(raw_input())
res = []
for _ in range(T):
    N = int(raw_input())
    cars = [int(raw_input()) for _ in range(N)]

    smallest = 1
    smallest_track = cars[-1]
    possible = True
    for car in reversed(cars):
        if car == smallest:
            smallest += 1
        elif car > smallest_track:
            possible = False
            break
        elif car < smallest_track:
            smallest_track = car
    if possible:
        res.append("Y")
    else:
        res.append("N")

for r in res:
    print r