#1,11,21,1211,111221
#Look and say sequence
a ="1"
count=1
ans = ""

n = int(input("Enter a number (PS: better keep it short)\n"))
print("The Look and Say sequence")
print(a)
for j in range(1,n):
    i=0
    ans = ""

    while True:

        if i<len(a)-1 and a[i] == a[i+1] :
            #Counting the number of times a digit appears
            count+=1
        else:
            #no of times and the digit
            ans+=str(count)+a[i]
            count =1
            if i == len(a)-1:
                break

        i+=1
    print(ans)
    a=ans
