import sys

def main():
    print "The fibonacci number " + sys.argv[1] + " is",
    d = {}
    print fibonacci(int(sys.argv[1]), d)


def fibonacci(n, d):
    if n == 0:
        return 0
    if n == 1:
        return 1
    if d.has_key(n):
        return d[n]
    else:
        k = fibonacci(n-1, d) + fibonacci(n-2, d)
        d[n] = k
        return k


if __name__ == "__main__":
    main()

