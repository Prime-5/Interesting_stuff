a = input("Input a string = ")
for i in range(len(a)):
    if(ord(a[i]) > 96 and ord(a[i]) < 123):
        A_ord = ord(a[i]) - 32
        A_chr = chr(A_ord)
        print(A_chr, end="")
    elif ord(a[i]) > 64 and ord(a[i]) < 91 :
        A_ord = ord(a[i]) + 32
        A_chr = chr(A_ord)
        print(A_chr, end="")
    elif ord(a[i]) == 32:
        print(" ", end="")
    else:
        print("invalid letter!")

