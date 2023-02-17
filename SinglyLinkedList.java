class SinglyLinkedList {
    Node head;

    class Node {
        int data;
        Node next;
        Node(int d) {
            data = d;
            next = null;
        }
    }

    void push(int data) {
        // if (head==null) {
        // head.data=data;
        // }
        Node new_Node = new Node(data);
        new_Node.next = head;
        head = new_Node;
    }

    void AfterNode(Node previousNode, int data) {
        if (previousNode == null) {
            System.out.println("Previous Node Can not NULL");
            return;
        }
        Node new_Node = new Node(data);
        new_Node.next = previousNode.next;
        previousNode.next = new_Node;
    }

    void AfterIndex(int num, int data) {
        if (head == null) {
            Node new_Node = new Node(data);
            new_Node.next = null;
            return;
        }
        Node temp = head;
        for (int i = 0; i < num - 1; i++) {
            temp = temp.next;
        }
        Node new_Node = new Node(data);
        new_Node.next = temp.next;
        temp.next = new_Node;
    }

    void PushAtEnd(int data) {
        Node new_Node = new Node(data);
        if (head == null) {
            head = new_Node;
            return;
        }
        Node temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }
        temp.next = new_Node;
        new_Node.next = null;
    }

    void Removehead() {
        if (head==null) {
            return;
        }
        head = head.next;
    }

    void RemoveNode(int key) {
        Node temp = head, prev = null;
        if (temp.data == key && temp != null) {
            head = temp.next;
            return;
        }
        while (temp != null && temp.data != key) {
            prev = temp;
            temp = temp.next;
        }
        if (temp == null) {
            System.out.println("Key Does Not Exist In List");
            return;
        }
        prev.next = temp.next;
    }

    void RemoveIndex(int num) {
        if (head == null) {
            System.out.println("List Is Empty");
            return;
        }
        Node temp = head;
        for (int i = 0; temp != null && i < num - 1; i++) {
            temp = temp.next;
        }
        if (temp == null || temp.next == null) {
            System.out.println("Index is Bigger Than Size Of List");
            return;
        }
        temp.next = temp.next.next;
    }

    int Listlength(Node node) {
        Node temp = node;
        int count = 0;
        while (temp != null) {
            count++;
            temp = temp.next;
        }
        return count;
    }

    int ListlengthRecursive(Node node) {
        if (node == null) {
            return 0;
        }
        return 1 + ListlengthRecursive(node.next);
    }

    void PrintLinkedList() {
        Node temp = head;
        while (temp != null) {
            System.out.println(temp.data + " ");
            temp = temp.next;
        }
    }

    void DeleteList(Node headNode) {
        head = null;
    }

    int LinearSearch(Node headNode, int key) {
        Node temp = headNode;
        int c = 0;
        while (temp != null) {
            c++;
            if (temp.data == key) {
                return c;
            }
            temp = temp.next;
        }
        return -1;
    }

    int PrintNthNode(Node headNode, int num) {
        Node temp = headNode;
        int count = 0;
        while (temp != null) {
            if (count == num) {
                return temp.data;
            }
            temp = temp.next;
            count++;
        }
        if (temp == null) {
            System.out.println("Index Bigger Than Size Of LinkedList");
        }
        return -1;
    }

    int PrintNthFromLast(Node headNode, int num) {
        Node temp = headNode;
        int l = Listlength(headNode);
        if (l < num) {
            System.out.println("Number Is Bigger Than Length");
            return -1;
        }
        int count = 0;
        while (temp != null) {
            if (l - num == count) {
                return temp.data;
            }
            temp = temp.next;
            count++;
        }
        // return temp.data;
        return -1;
    }

    public static void main(String[] args) {
        SinglyLinkedList l = new SinglyLinkedList();
        // l.push(6);
        // l.push(5);
        // l.push(4);
        // l.push(3);
        // l.push(2);
        // l.push(1);
        l.Removehead();
        l.PrintLinkedList();
        // l.AfterIndex(4, 0);
        // l.AtEnd(10);
        // l.PrintLinkedList();
        // l.DeleteList(l.head);
        // System.out.println("deleted");
        // System.out.println("After New ");
        // l.AfterNode(l.head.next, 12);
        // System.out.println("After Extra Insertion");
        // l.PrintLinkedList();
        // l.RemoveNode(8);
        // l.RemoveIndex(3);
        // System.out.println();
        // System.out.println("Node From Last:" + l.PrintNthFromLast(l.head, 7));
        // l.PrintLinkedList();
        // System.out.println("node:"+l.PrintNthNode(l.head, 5));
        // System.out.println("node:"+l.PrintNthNode(l.head, 15));
        // System.out.println();
        // System.out.println("Element Found At index"+l.LinearSearch(l.head, 6));
        // System.out.println("Length Of List iterative :" + l.Listlength(l.head));
        // System.out.println("Length Of List Recursive :" +
        // l.ListlengthRecursive(l.head));
    }
}