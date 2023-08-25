import java.io.*;

class Node {
    int data;
    Node prev;
    Node next;

    Node(int data) {
        this.data = data;
        this.prev = null;
        this.next = null;
    }
}

public class DI {
    static Node insertAtBeginning(Node head, int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
        } else {
            newNode.next = head;
            head.prev = newNode;
            head = newNode;
        }
        System.out.println("Node with data " + data + " inserted at the beginning.");
        return head;
    }

    static Node insertAtEnd(Node head, int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
        } else {
            Node temp = head;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = newNode;
            newNode.prev = temp;
        }
        System.out.println("Node with data " + data + " inserted at the end.");
        return head;
    }

    static Node insertAfterNode(Node head, int data, int key) {
        if (head == null) {
            System.out.println("List is empty. Unable to insert.");
            return null;
        }
        Node newNode = new Node(data);
        Node temp = head;
        while (temp != null && temp.data != key) {
            temp = temp.next;
        }
        if (temp == null) {
            System.out.println("Node with data " + key + " not found.");
        } else {
            newNode.next = temp.next;
            if (temp.next != null) {
                temp.next.prev = newNode;
            }
            temp.next = newNode;
            newNode.prev = temp;
            System.out.println("Node with data " + data + " inserted after node with data " + key + ".");
        }
        return head;
    }

    static Node insertBeforeNode(Node head, int data, int key) {
        if (head == null) {
            System.out.println("List is empty. Unable to insert.");
            return null;
        }
        Node newNode = new Node(data);
        Node temp = head;
        while (temp != null && temp.data != key) {
            temp = temp.next;
        }
        if (temp == null) {
            System.out.println("Node with data " + key + " not found.");
        } else {
            newNode.prev = temp.prev;
            if (temp.prev != null) {
                temp.prev.next = newNode;
            } else {
                head = newNode;
            }
            newNode.next = temp;
            temp.prev = newNode;
            System.out.println("Node with data " + data + " inserted before node with data " + key + ".");
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
        Node head = null;
        head = insertAtBeginning(head, 3);
        head = insertAtBeginning(head, 2);
        head = insertAtBeginning(head, 1);

        System.out.print("Original Doubly Linked List: ");
        displayDoublyLinkedList(head);

        head = insertAtEnd(head, 4);
        head = insertAtEnd(head, 5);

        System.out.print("Updated Doubly Linked List after insertions at the beginning and end: ");
        displayDoublyLinkedList(head);

        head = insertAfterNode(head, 6, 3);

        System.out.print("Updated Doubly Linked List after insertion after node with data 3: ");
        displayDoublyLinkedList(head);

        head = insertBeforeNode(head, 7, 4);

        System.out.print("Updated Doubly Linked List after insertion before node with data 4: ");
        displayDoublyLinkedList(head);
    }
}
