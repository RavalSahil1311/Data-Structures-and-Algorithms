public class CLL {

    Node head;

    public class Node {

        int data;
        Node next;

        Node(int d) {
            data = d;
        }
    }

    void Push(int data) {
        Node new_Node = new Node(data);
        if (head == null) {
            head = new_Node;
            head.next = head;
        }
        Node temp = head;
        while (temp.next != head) {
            temp = temp.next;
        }
        new_Node.next = head;
        head = new_Node;
        temp.next = head;
    }

    void PushAtIndex(int num, int data) {
        Node temp = head;
        Node new_Node = new Node(data);
        if (head == null) {
            head = new_Node;
            new_Node.next = head;
            return;
        }
        for (int i = 1; i < num - 1; i++) {
            temp = temp.next;
        }
        new_Node.next = temp.next;
        temp.next = new_Node;
    }

    void PushAtEnd(int data) {
        Node new_Node = new Node(data);
        if (head == null) {
            head = new_Node;
            new_Node.next = head;
            return;
        }
        Node temp = head;
        while (temp.next != head) {
            temp = temp.next;
        }
        new_Node.next = head;
        temp.next = new_Node;
    }

    void AfterNode(Node previousNode, int data) {
        if (previousNode == null) {
            System.out.println("Previous Node Can't be NULL");
            return;
        }
        Node new_Node = new Node(data);
        new_Node.next = previousNode.next;
        previousNode.next = new_Node;
    }

    void Removehead() {
        if (head == null) {
            return;
        }
        if (head.next == head) {
            // System.out.println("CLL s Head");
            head = null;
            return;
        }
        Node temp = head;
        while (temp.next != head) {
            temp = temp.next;
        }
        head = head.next;
        temp.next = head;
        if (head.next == head) {
            head.next = null;
        }
    }

    void RemoveNode(int key) {
        if (head.data == key) {
            Removehead();
            return;
        }
        Node temp = head, prev = null;
        while (temp.next != head && temp.data != key) {
            prev = temp;
            temp = temp.next;
        }
        if (temp == head) {
            System.out.println("Key Doesn't Exist In CLL");
            return;
        }
        prev.next = temp.next;
    }

    void RemoveIndex(int index) {
        Node temp = head, prev = null;
        if (index == 1) {
            Removehead();
            return;
        }
        for (int i = 1; i < index; i++) {
            prev = temp;
            temp = temp.next;
        }
        prev.next = temp.next;
    }

    int Listlength(Node node) {
        int count = 0;
        if (node == null) {
            return count;
        }
        Node temp = head;
        while (temp.next != head) {
            count++;
            temp = temp.next;
        }
        return count + 1;
    }

    int ListlengthRecursive(Node node) {
        if (node == null) {
            return 0;
        }
        if (node.next == head) {
            return 1;
        }
        return 1 + ListlengthRecursive(node.next);
    }

    void PrintCLL() {
        if (head == null) {
            System.out.println("CLL is Empty");
            return;
        }
        Node temp = head;
        do {
            System.out.print(temp.data + " ");
            temp = temp.next;
        } while (temp != head);
        System.out.println();
    }

    public static void main(String[] args) {
        CLL new_Cll = new CLL();
        // new_Cll.Push(6);
        // new_Cll.Push(5);
        // new_Cll.Push(4);
        // new_Cll.Push(3);
        // new_Cll.Push(2);
        // new_Cll.Push(1);
        // new_Cll.PushAtIndex(10, 0);
        // new_Cll.PushAtEnd(7);
        // new_Cll.PushAtEnd(8);
        // new_Cll.AfterNode(new_Cll.head.next, 0);
        // new_Cll.AfterNode(new_Cll.head.next.next.next, 0);
        // new_Cll.Removehead();
        // new_Cll.RemoveNode(6);
        // new_Cll.PrintCLL();
        // new_Cll.RemoveIndex(6);
        // new_Cll.RemoveIndex(2);
        // System.out.println(new_Cll.head.next.data);
        new_Cll.PrintCLL();
        System.out.println(new_Cll.ListlengthRecursive(new_Cll.head));
    }
}
