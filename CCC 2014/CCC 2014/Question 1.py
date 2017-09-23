k = int(raw_input())
m = int(raw_input())

friends = [i for i in range(1, k + 1)]
removals = [int(raw_input()) for _ in range(m)]

index = 0

for remove in removals:
    index = 0
    counter = 0
    difference = 0
    while index < len(friends) - difference:
        counter += 1
        friends[index] = friends[index + difference]
        if counter % remove == 0:
            difference += 1
        else:
            index += 1

print friends[:counter - index + 1]
