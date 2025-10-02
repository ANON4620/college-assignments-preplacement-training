class Hash:
    def __init__(self, buckets):
        self.bucket_count = buckets
        self.table = [[] for _ in range(self.bucket_count)]

    def insert(self, key):
        index = self.get_hash_index(key)
        self.table[index].append(key)

    
    def remove(self, key):
        index = self.get_hash_index(key)
        if key in self.table[index]:
            self.table[index].remove(key)

    def display(self):
        for i in range(self.bucket_count):
            print(i, end="")
            for key in self.table[i]:
                print(" -->", key, end="")
            print()

    def get_hash_index(self, key):
        return key % self.bucket_count

if __name__ == "__main__":
    keys = [7, 18, 12, 25]

    hash_table = Hash(7)

    for key in keys:
        hash_table.insert(key)

    hash_table.remove(12)
    hash_table.display()