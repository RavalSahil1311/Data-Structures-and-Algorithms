public class DLL {

    Node head;

    class Node {
        int data;
        Node next;
        Node prev;

        Node(int d) {
            data = d;
            next = null;
            prev = null;
        }
    }

    void Push(int data) {
        Node new_Node = new Node(data);
        new_Node.next = head;
        new_Node.prev = null;
        if (head != null) {
            head.prev = new_Node;
        }
        head = new_Node;
    }

    void PushAtIndex(int num, int data) {
        // int count = 0;
        Node temp = head;
        for (int i = 0; i < num - 1; i++) {
            temp = temp.next;
        }
        Node new_Node = new Node(data);
        new_Node.next = temp.next;
        new_Node.prev = temp;
        temp.next.prev = new_Node;
        temp.next = new_Node;
        if (temp != head) {
            new_Node.prev = temp;
        }
    }

    void InsertAfter(Node prev_Node, int data) {
        if (prev_Node == null) {
            System.out.println(
                    "Privous Node Can't be NULL \nPlease Enter Valid Node");
            return;
        }
        Node new_Node = new Node(data);
        new_Node.next = prev_Node.next;
        if (prev_Node.next != null) {
            prev_Node.next.prev = new_Node;
        }
        prev_Node.next = new_Node;
        new_Node.prev = prev_Node;
    }

    void InsertBefore(Node next_Node, int data) {
        if (next_Node == null) {
            System.out.println("Next Node Can't be NULL \nPlease Enter Valid Node");
            return;
        }
        Node new_Node = new Node(data);
        new_Node.prev = next_Node.prev;
        next_Node.prev = new_Node;
        new_Node.next = next_Node;
        if (new_Node.prev != null) {
            new_Node.prev.next = new_Node;
        } else {
            head = new_Node;
        }
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
        new_Node.prev = temp;
        new_Node.next = null;
    }

    void RemoveHead() {
        if (head == null) {
            return;
        }
        if (head.next == null) {
            head = null;
            return;
        }
        Node temp = head;
        head = head.next;
        temp.next.prev = null;
        return;
    }

    void RemoveNode(Node dNode) {
        if (dNode == null || head == null) {
            return;
        }
        if (dNode == head) {
            head = head.next;
        }
        if (dNode.next != null) {
            dNode.next.prev = dNode.prev;
        }
        if (dNode.prev != null) {
            dNode.prev.next = dNode.next;
        }
        return;
    }

    void RemoveIndex(int num) {
        Node temp = head;
        int c = 1;
        while (c != num) {
            temp = temp.next;
            c++;
        }
        if (temp == null) {
            System.out.println("Enter Valid Index");
            return;
        }
        if (temp.prev != null) {
            temp.next.prev = temp.prev;
        }
        if (temp.next != null) {
            temp.prev.next = temp.next;
        }
    }

    int Listlength() {
        if (head == null) {
            return 0;
        }
        int l = 1;
        Node temp = head;
        while (temp.next != null) {
            temp = temp.next;
            l++;
        }
        return l;
    }

    int ListlengthRecursive(Node head) {
        if (head == null) {
            return 0;
        }
        return 1 + ListlengthRecursive(head.next);
    }

    void PrintDLL(Node head) {
        Node temp = head;
        while (temp != null) {
            System.out.println(temp.data);
            temp = temp.next;
        }
    }

    public static void main(String[] args) {
        DLL New_Dll = new DLL();
        New_Dll.Push(7);
        New_Dll.Push(6);
        New_Dll.Push(5);
        New_Dll.Push(4);
        New_Dll.Push(3);
        New_Dll.Push(2);
        New_Dll.Push(1);
        
        // New_Dll.PushAtEnd(0);
        // New_Dll.PushAtEnd(6);
        // New_Dll.RemoveNode(New_Dll.head.next.next);
        // New_Dll.RemoveHead();
        // New_Dll.PushAtIndex(3, 0);
        // New_Dll.InsertAfter(New_Dll.head.next.next.next.next, 0);
        // New_Dll.InsertBefore(New_Dll.head.next.next.next, 0);
        // New_Dll.RemoveIndex(3);
        System.out.println(New_Dll.Listlength());
        // System.out.println(New_Dll.ListlengthRecursive(New_Dll.head));
        // New_Dll.PrintDLL(New_Dll.head);
    }
}
