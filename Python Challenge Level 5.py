import pickle
import urllib.request
import re
import brotli

url = "http://www.pythonchallenge.com/pc/def/banner.p"
webUrl = urllib.request.urlopen(url)

data = webUrl.read()

#file = open('pickle_file','wb')
#print(data)

#byte_seq=pickle.dumps(data)

#file.close()

#file = open('pickle_file','rb')
#print(file)
data = pickle.loads(data)

#print(data)

for i in data:
    for l in i:
        for item in range(int(l[1])):
            print(l[0],end = '')

    print()




#file.close()

print("Showing pickled data:")


'''pattern = re.compile(r'[A-Z]|[a-m]|[o-z]')
ans = pattern.findall(data)

words = set(ans)
l = len(words)

for i in ans:
    j =0
    while j < l:
        if words[j] == i:
            print(i)
            j+=1'''


#print(words)


#print(data)
