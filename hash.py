class double_hash:
    def __init__(self, size):
        self.hashtable = [None] * size
        self.comparisons = 0
        self.size = size
        print(self.hashtable)

    def h1(self, data):
        return data[0] % self.size

    def h2(self, data):
        return 8 - (data[0] % 8)

    def insert(self, data):
        index = self.h1(data)
        if self.hashtable[index] is None:
            self.hashtable[index] = [data[0], data[1]]
            print("Element inserted at index", index)
            print(self.hashtable)
        else:
            self.double_hashing(data)

    def double_hashing(self, data):
        i = 0
        index = (self.h1(data) + i * self.h2(data)) % self.size
        while self.hashtable[index] is not None:
            i += 1
            self.comparisons += 1
            index = (self.h1(data) + i * self.h2(data)) % self.size
        self.hashtable[index] = [data[0], data[1]]
        print("Element inserted at index", index)
        print(self.hashtable)

    def search(self, data):
        i = 0
        index = (self.h1(data) + i * self.h2(data)) % self.size
        while self.hashtable[index] != data:
            i += 1
            index = (self.h1(data) + i * self.h2(data)) % self.size
            if i == self.size - 1:
                break
        if i == self.size - 1:
            print("Element not present")
        else:
            print("Element found at index", index)

class quadratic_hash:
    def __init__(self, size):
        self.hashtable = [None] * size
        self.size = size
        print(self.hashtable)

    def h1(self, data):
        return data[0] % self.size

    def insert(self, data):
        index = self.h1(data)
        i = 0
        while self.hashtable[index] is not None:
            i += 1
            index = (self.h1(data) + i * i) % self.size  # Quadratic probing
        self.hashtable[index] = [data[0], data[1]]
        print("Element inserted at index", index)
        print(self.hashtable)

    def search(self, data):
        index = self.h1(data)
        i = 0
        while self.hashtable[index] is not None:
            if self.hashtable[index] == data:
                print("Element found at index", index)
                return
            i += 1
            index = (self.h1(data) + i * i) % self.size  # Quadratic probing
            if i == self.size - 1:
                break
        print("Element not present")

# Main Menu
while True:
    print("Select Hashing Technique:")
    print("1. Double Hashing")
    print("2. Quadratic Hashing")
    print("3. Exit")
    choice = int(input("Enter your choice: "))

    if choice == 1:
        size = int(input("Enter size of hashtable: "))
        obj = double_hash(size)
        data = [None] * 2
        while True:
            print("Enter choice:\n1. Insert\n2. Search\n3. Back to Main Menu")
            ch = int(input())
            if ch == 1:
                print("Enter telephone no. and name")
                data[0] = int(input())
                data[1] = input()
                obj.insert(data)
            if ch == 2:
                print("Enter telephone no. and name")
                data[0] = int(input())
                data[1] = input()
                obj.search(data)
            if ch == 3:
                break

    elif choice == 2:
        size = int(input("Enter size of hashtable: "))
        obj = quadratic_hash(size)
        data = [None] * 2
        while True:
            print("Enter choice:\n1. Insert\n2. Search\n3. Back to Main Menu")
            ch = int(input())
            if ch == 1:
                print("Enter telephone no. and name")
                data[0] = int(input())
                data[1] = input()
                obj.insert(data)
            if ch == 2:
                print("Enter telephone no. and name")
                data[0] = int(input())
                data[1] = input()
                obj.search(data)
            if ch == 3:
                break

    elif choice == 3:
        break
