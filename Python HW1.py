#The code for Q1

def dels(list1, list2):
    if len(list1) > len(list2):
        list1=list1[len(list2):]
        print(list1)
    
    elif len(list1) < len(list2):
        list3 = [list2[0]]
        list3.extend(list1)
        list3.extend(list2[1:])
        print(list3)
        
    
    elif len(list1) == len(list2):
        list3 = []
        print(list3)

dels([3,4,2,5,6,7],[1,3,4])
dels([2,5],[3,4,7,8,9])
dels([2,3,4],[8,7,9])

#The code for Q2 part A

mylist = []
def digits(k):
    global mylist
    
    if(k % 10 != k):
        mylist.insert(0, int(k%10))
        k = int(k / 10)
        digits (k)
    else:
        mylist.insert(0,int(k))
        print(mylist)

digits(532)

#The code for Q2 part B

list1 = []
def multiply(a,b):
    global list1
    
    if(a % 10 != a):
        list1.insert(0, int(a % 10))
        a = int(a / 10)
        multiply(a, 0)
    
    elif(a != 0):
        list1.insert(0,a)
        
    if(b % 10 != b):
        list1.append(int(b % 10))
        b = int(b / 10)
        multiply(0, b)
            

multiply(532, 1000)
print(list1)