class Node {

    int data;
    Node left, right;

    Node(int data) {
        this.data = data;
        left = right = null;
    }
}

class BST {

    static Node root;

    BST() {
        root = null;
    }

    static Node Succeser(Node root, int key) {
        Node succNode = null;
        while (root != null) {
            if (root.data > key) {
                succNode = root;
                root = root.left;
            } else {
                root = root.right;
            }
        }
        return succNode;
    }

    Node Predessor(Node root, int key) {
        Node predNode = null;
        while (root != null) {
            if (root.data < key) {
                predNode = root;
                root = root.right;
            } else {
                root = root.left;
            }
        }
        return predNode;
    }

    static Node DeleteRec(Node root, int key) {
        if (root == null) {
            return root;
        }
        if (root.data > key) {
            root.left = DeleteRec(root.left, key);
        } else if (root.data < key) {
            root.right = DeleteRec(root.right, key);
        } else {
            if (root.left == null) {
                return root.right;
            }
            if (root.right == null) {
                return root.left;
            }
            root.data = Succeser(root.right, key).data;
            root.right = DeleteRec(root.right, root.data);
        }
        return root;
    }

    void InsertItr(Node root, int key) {
        Node x = new Node(key);
        if (root == null) {
            root = x;
            return;
        }
        Node prev = null;
        Node temp = root;
        while (temp != null) {
            prev = temp;
            if (key > temp.data) {
                temp = temp.right;
            } else {
                temp = temp.left;
            }
        }
        if (key < prev.data) {
            prev.left = x;
        } else {
            prev.right = x;
        }
    }

    void Insertitr(int key) {
        InsertItr(root, key);
    }

    void Insertrec(int key) {
        root = InsertRec(root, key);
    }

    static Node InsertRec(Node root, int key) {
        if (root == null) {
            root = new Node(key);
            // temp = flag;
            return root;
        }
        if (root.data > key) {
            root.left = InsertRec(root.left, key);
        } else {
            root.right = InsertRec(root.right, key);
        }
        return root;
    }

    void Levelorder() {
        LevelOrder(root);
    }

    static void LevelOrder(Node root) {
        if (root == null) {
            return;
        }
        System.out.print(root.data + " ");
        LevelOrder(root.left);
        LevelOrder(root.right);
    }

    void Inorder() {
        InOrder(root);
    }

    static void InOrder(Node temp) {
        if (temp == null) {
            // System.out.println("Hello");
            return;
        }
        InOrder(temp.left);
        System.out.print(temp.data + " ");
        InOrder(temp.right);
    }

    public static void main(String[] args) {
        BST tree = new BST();
        tree.Insertrec(10);
        tree.Insertrec(5);
        tree.Insertrec(15);
        tree.Insertrec(2);
        tree.Insertrec(8);
        tree.Insertrec(13);
        tree.Insertrec(18);
        tree.Insertitr(20);
        System.out.println("This is example of BST");
        tree.Levelorder();
        tree.Inorder();
        System.out.println();
        System.out.println(tree.Predessor(root, 8).data);
        Node tempNode = DeleteRec(root, 15);
        System.out.println(tempNode.data);
        // DeleteRec(root, 0);
        // System.out.println(tempNode1.data);
        LevelOrder(root);
    }
}
