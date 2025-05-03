class SetADT:
    def __init__(self):
        self.items = []

    def add(self, element):
        if element not in self.items:
            self.items.append(element)

    def remove(self, element):
        if element in self.items:
            self.items.remove(element)

    def contains(self, element):
        return element in self.items

    def size(self):
        return len(self.items)

    def iterator(self):
        return iter(self.items)

    def intersection(self, other_set):
        result = SetADT()
        for item in self.items: 
            if other_set.contains(item):
                result.add(item)
        return result

    def union(self, other_set):
        result = SetADT()
        for item in self.items:
            result.add(item)
        for item in other_set.iterator():
            result.add(item)
        return result

    def difference(self, other_set):
        result = SetADT()
        for item in self.items:
            if not other_set.contains(item):
                result.add(item)
        return result

    def is_subset(self, other_set):
        for item in self.items:
            if not other_set.contains(item):
                return False
        return True
    
    # from itertools import chain,combinations
    # for i in range(len(s1)):
	# 	print(list(combinations(s1,i)))

# Example usage
if __name__ == "__main__":
    a = SetADT()
    b = SetADT()

    for i in [1, 2, 3, 4]:
        a.add(i)
    for i in [3, 4, 5, 6]:   
        b.add(i)

    print("Set A:", list(a.iterator()))
    print("Set B:", list(b.iterator()))
    print("Intersection:", list(a.intersection(b).iterator()))
    print("Union:", list(a.union(b).iterator()))
    print("Difference (A - B):", list(a.difference(b).iterator()))
    print("Is A subset of B?", a.is_subset(b))
