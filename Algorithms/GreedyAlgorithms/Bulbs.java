// Problme definition

// Given N Bulbs ,Either ON or OFF.
// Turning on ith bulb causes all remaining bulbs on the right to flip.
// Find Minimum Number of switches to turn all the bilbs on.

import java.util.Scanner;
public class Bulbs {
    public static void main(String[] args) {
        Scanner Input = new Scanner(System.in);
        int number_of_Bulbs = Input.nextInt();
        int[] states_of_Bulbs = new int[number_of_Bulbs];
        for(int i=0;i<number_of_Bulbs;i++)
        {
            states_of_Bulbs[i] = Input.nextInt();
        }
        int cost=0;
        for(int i=0;i<number_of_Bulbs;i++)
        {
            if ((cost&1)!=0) {
                states_of_Bulbs[i]=1-states_of_Bulbs[i];
            }
            if (states_of_Bulbs[i]==0) {
                cost++;
            }
        }
        System.out.println("Total cost of  turning on all bulbes is: " + cost);
        Input.close();
    }
}
