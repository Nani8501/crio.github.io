
class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None


def insert_at_beginning(head, data):
    new_node = Node(data)
    if not head:
        head = new_node
    else:
        new_node.next = head
        head.prev = new_node
        head = new_node
    print(f"Node with data {data} inserted at the beginning.")
    return head


def insert_at_end(head, data):
    new_node = Node(data)
    if not head:
        head = new_node
    else:
        temp = head
        while temp.next:
            temp = temp.next
        temp.next = new_node
        new_node.prev = temp
    print(f"Node with data {data} inserted at the end.")
    return head


def insert_after_node(head, data, key):
    if not head:
        print("List is empty. Unable to insert.")
        return None
    new_node = Node(data)
    temp = head
    while temp and temp.data != key:
        temp = temp.next
    if not temp:
        print(f"Node with data {key} not found.")
    else:
        new_node.next = temp.next
        if temp.next:
            temp.next.prev = new_node
        temp.next = new_node
        new_node.prev = temp
        print(f"Node with data {data} inserted after node with data {key}.")
    return head


def insert_before_node(head, data, key):
    if not head:
        print("List is empty. Unable to insert.")
        return None
    new_node = Node(data)
    temp = head
    while temp and temp.data != key:
        temp = temp.next
    if not temp:
        print(f"Node with data {key} not found.")
    else:
        new_node.prev = temp.prev
        if temp.prev:
            temp.prev.next = new_node
        else:
            head = new_node
        new_node.next = temp
        temp.prev = new_node
        print(f"Node with data {data} inserted before node with data {key}.")
    return head


def display_doubly_linked_list(head):
    temp = head
    while temp:
        print(temp.data, end=" ")
        temp = temp.next
    print()


head = None
head = insert_at_beginning(head, 3)
head = insert_at_beginning(head, 2)
head = insert_at_beginning(head, 1)

print("Original Doubly Linked List:", end=" ")
display_doubly_linked_list(head)

head = insert_at_end(head, 4)
head = insert_at_end(head, 5)

print("Updated Doubly Linked List after insertions at the beginning and end:", end=" ")
display_doubly_linked_list(head)

head = insert_after_node(head, 6, 3)

print("Updated Doubly Linked List after insertion after node with data 3:", end=" ")
display_doubly_linked_list(head)

head = insert_before_node(head, 7, 4)

print("Updated Doubly Linked List after insertion before node with data 4:", end=" ")
display_doubly_linked_list(head)
              
