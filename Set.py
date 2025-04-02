from itertools import chain,combinations

s1={10,20,30,40}

s2={40,50,60}

def add_element(n):

    if(n==1):   

        ele=int(input("Enter element to be added in set1:"))

        if ele not in  s1:

            s1.add(ele)

            print("Element added")

    if(n==2):

        ele=int(input("Enter element to be added in set2:"))

        if ele not in s2:

            s2.add(ele)

            print("Element added")

            

def remove_element(n):  

    if(n==1):

        ele=int(input("Enter element to be removed from set1:"))

        s1.remove(ele)

    if(n==2):

        ele=int(input("Enter element to be removed from set2:"))

        s2.remove(ele)



def search_element(n):

    if(n==1):   

        ele=int(input("Enter element to be search in set1:"))

        if ele in s1:

            print("Element exists in set1")

        else:

            print("Element does not exist in set1")

    if(n==2):

        ele=int(input("Enter element to be search in set2:"))

        if ele in s2:

            print("Element exists in set2")

        else:

            print("Element does not exist in set2")



def display_size(n):

    if(n==1):

        print("Size of set1 is:",len(s1))

    if(n==2):

        print("Size of set2 is:",len(s2))

        

def display(n):

    if(n==1):

        print("Elements in set1 are:")

        for i in s1:

            print(i,end=',')

        print()

    if n==2:

        print("Elements in set2 are:")

        for i in s2:

            print(i,end=',')

        print()

    

def display_union():

    print(s1.union(s2))

def display_inter():

    print(s1.intersection(s2))

def display_diff():

    print(s1.difference(s2))

def check_sub(s,n):

    if(n==1):

        if(s.issubset(s1)):

            print("Set is subset of set1")

        else:

            print("Set is not subset of set1")

    if(n==2):

        if(s.issubset(s2)):

            print("Set is subset of set2")

        else:

            print("Set is not subset of set2")



def print_subsets():

    print("subsets in set1:")

    for i in range(len(s1)):

        print(list(combinations(s1,i)))

    

print("Initial set1:")

print(s1)

print()



print("Initial set2:")

print(s2)

print()

print_subsets()

flag='y'

while(flag=='y'):

    print("Enter choice:\n1.add element in set1\n2.add element in set2\n3.remove element from set1\n4.remove element from set2\n5.search element in set1\n6.search element in set2\n7.display size of set1\n8.display size of set2\n9.display set1\n10.dsiplay set2\n11.display union\n12.display intersection\n13.display difference\n14.check for subset in set1\n15.check for subset in set2")

    ch=int(input())

    if ch==1:

        add_element(1)

    if ch==3:

        remove_element(1)

    if ch==5:

        search_element(1)

    if ch==7:

        display_size(1)

    if ch==9:

        display(1)

    if ch==2:

        add_element(2)

    if ch==4:

        remove_element(2)

    if ch==6:

        search_element(2)

    if ch==8:

        display_size(2)

    if ch==10:

        display(2)

    if ch==11:

        display_union()

    if ch==12:

        display_inter()

    if ch==13:

        display_diff()

    if ch==14:

        n=int(input("Enter no. of elements in subset"))

        s=[]

        for i in range(n):

            s.append(int(input("Enter element")))   

            

        check_sub(set(s),1)

    if ch==15:

        n=int(input("Enter no. of elements in subset"))

        s=[]

        for i in range(n):

            s.append(int(input("Enter element")))   

            

        check_sub(set(s),2)

    print("do you want to continue(y/n):")

    flag=input()

