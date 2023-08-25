
class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None


def delete_first_node(head):
    if not head:
        print("List is empty. Unable to delete.")
        return None
    temp = head
    head = head.next
    if head:
        head.prev = None
    temp.next = None
    print("First node deleted successfully.")
    return head


def delete_last_node(head):
    if not head:
        print("List is empty. Unable to delete.")
        return None
    temp = head
    while temp.next:
        temp = temp.next
    if temp.prev:
        temp.prev.next = None
    else:
        head = None
    temp.prev = None
    print("Last node deleted successfully.")
    return head


def delete_node(head, key):
    if not head:
        print("List is empty. Unable to delete.")
        return None
    temp = head
    while temp and temp.data != key:
        temp = temp.next
    if not temp:
        print(f"Node with data {key} not found.")
    else:
        if temp.prev:
            temp.prev.next = temp.next
        else:
            head = temp.next
        if temp.next:
            temp.next.prev = temp.prev
        temp.prev = None
        temp.next = None
        print(f"Node with data {key} deleted successfully.")
    return head


def display_doubly_linked_list(head):
    temp = head
    while temp:
        print(temp.data, end=" ")
        temp = temp.next
    print()


if __name__ == "__main__":
    head = Node(1)
    second = Node(2)
    third = Node(3)

    head.next = second
    second.prev = head
    second.next = third
    third.prev = second

    print("Original Doubly Linked List:", end=" ")
    display_doubly_linked_list(head)

    head = delete_first_node(head)
    display_doubly_linked_list(head)

    head = delete_last_node(head)
    display_doubly_linked_list(head)

    head = delete_node(head, 2)
    display_doubly_linked_list(head)
