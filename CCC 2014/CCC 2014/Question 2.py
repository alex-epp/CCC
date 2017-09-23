import sys

N = int(raw_input())
names = str(raw_input()).split()
partners = str(raw_input()).split()
try:
    for i in range(len(names)):
        for j in range(i, len(partners)):
            if names[i] == partners[j] and names[j] != partners[i]:
                print "bad"
                sys.exit()
    print "good"
except:
    pass
