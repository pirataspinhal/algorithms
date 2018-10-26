package com.trustgeek.puzzles.eightpuzzles;

import java.util.Scanner;
class MainTestClass {

    public static void main(String[] args) {
        System.out.println("Enter the initial board State: ");

        // Scanner initialInput = new Scanner(System.in);
        String initState = "283164705"; // initialInput.next();
        String finalState = "124803756"; //finalInput.next();
        
        // 102345678
        System.out.println("Enter the final board State: ");

        // Scanner finalInput = new Scanner(System.in);
        System.out.println();


        SolutionEngine sp = new SolutionEngine(initState, finalState);
        System.out.println("Select algorithm to search: \n1. BFS\n2. DFS\n3. Astar\n     >> ");
        Scanner opt = new Scanner(System.in);
        int option = opt.nextInt();
        if (option == 1) {
            sp.callAlgo(Algo.BFS);
        } else if (option == 2) {
            sp.callAlgo(Algo.DFS);
        } else if (option == 3) {
            sp.callAlgo(Algo.ASTAR);
        } else
            System.out.println("Invalid option !!!");
    }

}
