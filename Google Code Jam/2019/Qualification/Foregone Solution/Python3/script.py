
def Foregone(N):
    A = ""
    B = ""
    for i in range(len(N)):
        if (N[i] == '4'):
            A += '2'
            B += '2'
        else:
            A += N[i]
            B += '0'
    return (str(int(A)), str(int(B)))


for T in range(int(input())):
    N = input()
    A, B = Foregone(N)
    print("Case #{}: {} {}".format(T+1, A, B))
