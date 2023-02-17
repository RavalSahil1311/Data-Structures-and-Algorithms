import java.util.LinkedList;
import java.util.Queue;

class NormalTree {

    static class Node {

        int key;
        Node left, right;

        Node(int key) {
            this.key = key;
            left = right = null;
        }
    }

    static Node root;
    static Node temp = root;

    static int Height(Node root) {
        // Node temp=new Node(0);
        if (root == null) {
            return 0;
        }
        return 1 + Math.max(Height(root.left), Height(root.right));
    }

    static int Diameter(Node root) {
        if (root == null) {
            return 0;
        }

        int lheight = Height(root.left);
        int rheight = Height(root.right);
        int ldiameter = Diameter(root.left);
        int rdiameter = Diameter(root.right);

        return Math.max(lheight + rheight + 1, Math.max(ldiameter, rdiameter));
    }

    static void InOrder(Node temp) {
        if (temp == null) {
            return;
        }

        InOrder(temp.left);
        System.out.print(temp.key + " ");
        InOrder(temp.right);
    }

    static void PreOrder(Node temp) {
        if (temp == null) {
            return;
        }

        System.out.print(temp.key + " ");
        PreOrder(temp.left);
        PreOrder(temp.right);
    }

    static void PostOrder(Node temp) {
        if (temp == null) {
            return;
        }

        PostOrder(temp.left);
        PostOrder(temp.right);
        System.out.print(temp.key + " ");
    }

    static void LevelOrder(Node root) {
        Queue<Node> q = new LinkedList<Node>();
        q.add(root);
        Node temp = null;

        while (!q.isEmpty()) {
            temp = q.poll();
            System.out.print(temp.key + " ");
            if (temp.left != null) {
                q.add(temp.left);
            }
            if (temp.right != null) {
                q.add(temp.right);
            }
        }
    }

    static void Insert(Node temp, int key) {
        if (temp == null) {
            root = new Node(key);
            return;
        }

        Queue<Node> q = new LinkedList<Node>();
        q.add(temp);

        while (!q.isEmpty()) {
            temp = q.peek();
            q.remove();
            if (temp.left == null) {
                temp.left = new Node(key);
                break;
            } else {
                q.add(temp.left);
            }
            if (temp.right == null) {
                temp.right = new Node(key);
                break;
            } else {
                q.add(temp.right);
            }
        }
    }

    static void DeleteDeepest(Node root, Node delNode) {
        Queue<Node> q = new LinkedList<Node>();
        Node temp = null;
        q.add(root);

        while (!q.isEmpty()) {
            temp = q.poll();
            if (temp == delNode) {
                temp = null;
                return;
            }
            if (temp.right != null) {
                if (delNode == temp.right) {
                    temp.right = null;
                    return;
                } else {
                    q.add(temp.right);
                }
            }
            if (temp.left != null) {
                if (delNode == temp.left) {
                    temp.left = null;
                    return;
                } else {
                    q.add(temp.left);
                }
            }
        }
    }

    static void DeleteKey(Node root, int key) {
        if (root == null) {
            return;
        }
        if (root.left == null && root.right == null) {
            if (root.key == key) {
                root = null;
                return;
            } else {
                return;
            }
        }

        Queue<Node> q = new LinkedList<Node>();
        Node temp = null, KeyNode = null;
        q.add(root);

        while (!q.isEmpty()) {
            temp = q.poll();
            if (temp.key == key) {
                KeyNode = temp;
            }
            if (temp.left != null) {
                q.add(temp.left);
            }
            if (temp.right != null) {
                q.add(temp.right);
            }
        }
        if (KeyNode != null) {
            KeyNode.key = temp.key;
            DeleteDeepest(root, temp);
        }
    }

    // lowest common ansester
    public static void main(String[] args) {
        root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.left = new Node(6);
        root.right.left.right = new Node(6);
        root.right.right = new Node(7);
        // System.out.println(Height(root));
        // Insert(root, 1);
        // Insert(root, 2);
        // Insert(root, 3);
        // Insert(root, 4);
        // Insert(root, 5);
        // Insert(root, 0);
        // Insert(root, 4);
        // LevelOrder(root);
        // System.out.println();
        // DeleteKey(root, 0);
        // LevelOrder(root);
        // System.out.println();
        // PreOrder(root);
        // System.out.println();
        // LevelOrder(root);
        // System.out.println();
        // PostOrder(root);
        // System.out.println();
        // InOrder(root);
        // System.out.println();
        // PreOrder(root);
        System.out.println(Diameter(root));
    }
}
