import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Comparator;

class Node {
    int data;
    char C;
    Node left;
    Node right;
}

class MyComparator implements Comparator<Node> {
    public int compare(Node x, Node y) {
        return x.data - y.data;
    }
}

public class Huffman {

    static void PrintCode(Node root, String s) {
        if (root.left == null && root.right == null && Character.isLetter(root.C)) {
            System.out.println(root.C + ": " + s);
            return;
        }
        PrintCode(root.left, s + "0");
        PrintCode(root.right, s + "1");
    }

    static Node HuffmanTree(int Frequency[], char Character[]) {
        PriorityQueue<Node> q = new PriorityQueue<Node>(Frequency.length, new MyComparator());
        for (int i = 0; i < Frequency.length; i++) {
            Node temp = new Node();

            temp.data = Frequency[i];
            temp.C = Character[i];

            temp.left = null;
            temp.right = null;

            q.add(temp);
        }

        while (q.size() > 1) {
            Node x = q.poll();
            Node y = q.poll();
            // System.out.println(count + " " + " Node1 " + x.data + " Node2 " + y.data);
            Node new_Node = new Node();
            new_Node.data = x.data + y.data;
            new_Node.C = '-';
            new_Node.left = x;
            new_Node.right = y;
            q.add(new_Node);
        }
        Node temp = q.poll();
        return temp;
    }

    public static void main(String[] args) {
        Scanner Input = new Scanner(System.in);
        System.out.println("Enter Number of letters");
        int n = Input.nextInt();
        char[] Character = new char[n];
        int[] Frequency = new int[n];
        System.out.println("Enter " + n + " Characters : ");
        for (int i = 0; i < Character.length; i++) {
            Character[i] = Input.next().charAt(0);
        }
        System.out.println("Enter " + n + " Frequency : ");
        for (int i = 0; i < Frequency.length; i++) {
            Frequency[i] = Input.nextInt();
        }
        // char[] Character = { 'a', 'b', 'c', 'd', 'e', 'f' };
        // int[] Frequency = { 5, 9, 12, 13, 16, 45 };
        Node root = HuffmanTree(Frequency, Character);
        // System.out.println(root.data);
        // LevelOrder(root);
        PrintCode(root, "");
        Input.close();
    }
}