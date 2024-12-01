input_path = '../input.txt'

f = open(input_path, "r")

a = []
b = []

for line in f:
    x, y = line.split()
    a.append(int(x))
    b.append(int(y))

a.sort()
b.sort()

c = 0
for x, y in zip(a, b):
    c += abs(x - y)

print(f"total distance: {c}")
