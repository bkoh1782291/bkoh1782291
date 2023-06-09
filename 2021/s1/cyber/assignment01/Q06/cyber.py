import sys
import random
import string

def randomString(n):
    letters = string.ascii_letters + "{}_"
    return ''.join(random.choice(letters) for i in range(n))

def main():
    if (len(sys.argv) != 2):
        print("usage: python3 cyber <input string> ")
        sys.exit(1)
    inputstr = sys.argv[1]
    l1 = len(inputstr)
    l2 = 100
    for c in inputstr:
        p = random.randint(0, l2)
        #print('VALUE OF C :' + c)
        # length(p) + 1 = position of C
        x = '{:04d}'.format(p) + ":" + randomString(p) + c + randomString(l2 - p)
        #x = '{:04d}'.format(p) + ":" + c + randomString(l2 - p)
        print(x)

if __name__ == '__main__':
    main()
