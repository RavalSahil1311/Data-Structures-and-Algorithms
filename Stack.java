// import java.util.Scanner;

public class Stack {
    // int n;
    static int top = -1;
    static int[] Stack = new int[10];

    static boolean isEmpty() {
        return (top < 0);
    }

    static void push(int data) {

        if (top >= 10) {
            System.out.println("Stack OverFlow");
        } else {
            Stack[++top] = data;
        }
    }

    static void pop() {
        if (top < 0) {
            System.out.println("Stack UnderFlow");
        } else {
            System.out.println(Stack[top]);
            top--;
        }
    }

    static void peep() {
        if (top < 0) {
            System.out.println("Stack UnderFlow");
        } else {
            System.out.println(Stack[top]);
        }
    }

    static void PrintStack() {
        System.out.println("Stack Elements");
        for (int i = top; i > -1; i--) {
            System.out.print(" " + Stack[i]);
        }
        System.out.println();
    }

    public static void main(String[] args) {
        // Scanner Input = new Scanner(System.in);
        // System.out.println("Enter Size Of Stack");
        // int n = Input.nextInt();
        push(10);
        push(9);
        push(8);
        push(7);
        push(6);
        PrintStack();
        pop();
        pop();
        // PrintStack();
        push(5);
        // push(4);
        // peep();
        // peep();
        System.out.println();
        PrintStack();
        System.out.println("Stack Top");
        peep();
        // pop();
        // pop();pop();pop();pop();pop();
        // System.out.println(isEmpty());
    }
}