import java.io.*;

class DD {

    static class Node {
        int data;
        Node prev;
        Node next;

        public Node(int data) {
            this.data = data;
            this.prev = null;
            this.next = null;
        }
    }

    static Node deleteFirstNode(Node head) {
        if (head == null) {
            System.out.println("List is empty. Unable to delete.");
            return null;
        }
        Node temp = head;
        head = head.next;
        if (head != null) {
            head.prev = null;
        }
        temp.next = null;
        System.out.println("First node deleted successfully.");
        return head;
    }

    static Node deleteLastNode(Node head) {
        if (head == null) {
            System.out.println("List is empty. Unable to delete.");
            return null;
        }
        Node temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }
        if (temp.prev != null) {
            temp.prev.next = null;
        } else {
            head = null;
        }
        temp.prev = null;
        System.out.println("Last node deleted successfully.");
        return head;
    }

    static Node deleteNode(Node head, int key) {
        if (head == null) {
            System.out.println("List is empty. Unable to delete.");
            return null;
        }
        Node temp = head;
        while (temp != null && temp.data != key) {
            temp = temp.next;
        }
        if (temp == null) {
            System.out.println("Node with data " + key + " not found.");
        } else {
            if (temp.prev != null) {
                temp.prev.next = temp.next;
            } else {
                head = temp.next;
            }
            if (temp.next != null) {
                temp.next.prev = temp.prev;
            }
            temp.prev = null;
            temp.next = null;
            System.out.println("Node with data " + key + " deleted successfully.");
        }
        return head;
    }

    static void displayDoublyLinkedList(Node head) {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Node head = new Node(1);
        Node second = new Node(2);
        Node third = new Node(3);

        head.next = second;
        second.prev = head;
        second.next = third;
        third.prev = second;

        System.out.print("Original Doubly Linked List: ");
        displayDoublyLinkedList(head);

        head = deleteFirstNode(head);
        displayDoublyLinkedList(head);

        head = deleteLastNode(head);
        displayDoublyLinkedList(head);

        head = deleteNode(head, 2);
        displayDoublyLinkedList(head);
    }
}
