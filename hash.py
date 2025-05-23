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
        else:
            self.double_hashing(data)

        print(self.hashtable)

    def double_hashing(self, data):
        # Using for loop for probing
        for i in range(self.size):
            index = (self.h1(data) + i * self.h2(data)) % self.size
            if self.hashtable[index] is None:
                self.hashtable[index] = [data[0], data[1]]
                print("Element inserted at index", index)
                print(self.hashtable)
                return
        print("Hash table is full, cannot insert element.")

    def search(self, data):
        index = self.h1(data)
        if self.hashtable[index] is not None and self.hashtable[index][0] == data[0]:
            print("Element found at index", index)
            return self.hashtable[index]
        else:
            return self.double_hash_search(data)

    def double_hash_search(self, data):
        # Using for loop for probing
        for i in range(self.size):
            new_index = (self.h1(data) + i * self.h2(data)) % self.size
            if self.hashtable[new_index] is None:
                print("Element not found.")
                return None
            elif self.hashtable[new_index][0] == data[0]:
                print("Element found at index", new_index)
                return self.hashtable[new_index]
        print("Element not found.")
        return None


class quadratic_hash:
    def __init__(self, size):
        self.hashtable = [None] * size
        self.size = size
        print(self.hashtable)

    def h1(self, data):
        return data[0] % self.size

    def insert(self, data):
        index = self.h1(data)
        if self.hashtable[index] is None:
            self.hashtable[index] = [data[0], data[1]]
            print("Element inserted at index", index)
        else:
            self.quadratic_probing(data)

        print(self.hashtable)

    def quadratic_probing(self, data):
        for i in range(1, self.size):
            new_index = (self.h1(data) + i * i) % self.size
            if self.hashtable[new_index] is None:
                self.hashtable[new_index] = [data[0], data[1]]
                print("Element inserted at index", new_index)
                return
        print("Hash table is full, cannot insert element.")
        
    def search(self, data):
        index = self.h1(data)
        if self.hashtable[index] is not None and self.hashtable[index][0] == data[0]:
            print("Element found at index", index)
            return self.hashtable[index]
        else:
            return self.quadratic_search(data)

    def quadratic_search(self, data):
        for i in range(1, self.size):
            new_index = (self.h1(data) + i * i) % self.size
            if self.hashtable[new_index] is None:
                print("Element not found.")
                return None
            elif self.hashtable[new_index][0] == data[0]:
                print("Element found at index", new_index)
                return self.hashtable[new_index]
        print("Element not found.")
        return None

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
