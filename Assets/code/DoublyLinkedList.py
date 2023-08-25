
# Python implementation of Doubly Linked List
class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None

    def insertAtEnd(self, data):
        new_node = Node(data)

        if self.head is None:
            self.head = new_node
        else:
            temp = self.head
            while temp.next is not None:
                temp = temp.next
            temp.next = new_node
            new_node.prev = temp

    def displayList(self):
        temp = self.head
        while temp is not None:
            print(temp.data, end=" ")
            temp = temp.next

list = DoublyLinkedList()
list.insertAtEnd(10)
list.insertAtEnd(20)
list.insertAtEnd(30)
list.insertAtEnd(40)

print("Doubly Linked List:", end=" ")
list.displayList()
              
