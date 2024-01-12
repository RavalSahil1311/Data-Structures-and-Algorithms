import java.util.HashMap;
import java.util.Scanner;

public class Activity_Selection_Problem {
    public static void main(String[] args) {
        Scanner Input = new Scanner(System.in);
        System.out.print("Enter the number of activitites:");
        int n = Input.nextInt();
        int[] start = new int[n];
        int[] finish = new int[n];
        HashMap<Integer, Integer> map = new HashMap<>();
        System.out.println("Enter the starting time of activity by order:");
        for (int i = 0; i < n; i++) {
            start[i] = Input.nextInt();
        }
        System.out.println("Enter the finishing time of activity by order:");
        for (int i = 0; i < n; i++) {
            finish[i] = Input.nextInt();
        }
        for (int i = 0; i < n; i++) {
            map.put(finish[i], i);
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (finish[i] > finish[j]) {
                    int temp = finish[i];
                    finish[i] = finish[j];
                    finish[j] = temp;
                    temp = start[i];
                    start[i] = start[j];
                    start[j] = temp;
                }
            }
        }        
        for (int i = 0; i < n; i++) {
        }
        Input.close();
    }
}
