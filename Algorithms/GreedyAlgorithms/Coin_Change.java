import java.util.Scanner;
import java.util.Vector;

public class Coin_Change {
    static void FindChange(int n) {
        int coins[] = { 1, 2, 5, 10, 20, 50, 100, 500, 2000 };
        int length = coins.length;
        Vector<Integer> vector = new Vector<>();
        for (int i = length - 1; i >= 0; i--) {
            while (n >= coins[i]) {
                n -= coins[i];
                vector.add(coins[i]);
            }
        }
        for (int i = 0; i < vector.size(); i++) {
            System.out.print(vector.elementAt(i) + " ");
        }
    }

    public static void main(String[] args) {
        Scanner Input = new Scanner(System.in);
        int n = Input.nextInt();
        FindChange(n);
        Input.close();
    }
}
