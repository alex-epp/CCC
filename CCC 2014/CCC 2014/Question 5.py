
def distance2(p1, p2):
    return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1])

N = int(raw_input())
coords = []
for _ in range(N):
    x, y = raw_input().split()
    xy = [int(x), int(y)]
    coords.append(xy)

# Construct a node array
# Which, for any two node indices, stores the distance
node_array = [[distance2(coords[i], coords[j]) for i in range(len(coords))] for j in range(len(coords))]

cache = dict()
def get_max_treats(curr_node, max_distance):
    global coords
    global cache

    if cache.has_key((curr_node, max_distance)):
      return cache[(curr_node, max_distance)]
    max_treats = 0
    for i in range(N):
        if i == curr_node:
            continue
        if node_array[i][curr_node] < max_distance or max_distance == -1:
            max_treats = max(max_treats, get_max_treats(i, node_array[i][curr_node]) + 1)
    cache[(curr_node, max_distance)] = max_treats
    return max_treats

print max({get_max_treats(i, -1) for i in range(N)})