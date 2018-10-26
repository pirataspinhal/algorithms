package com.trustgeek.puzzles.eightpuzzles;

import java.util.Scanner;

public class SolutionEngine {
    private String initialState;
    private String finalState;

    SolutionEngine(String initialState, String finalState) {
        this.initialState = initialState;
        this.finalState = finalState;
    }

    void callAlgo(Algo algoSelected) {
        switch (algoSelected) {
            case DFS:
                System.out.println("Depth First Search\n----------------------------");
                System.out.print("Enter the limit: ");
                Scanner limitValue = new Scanner(System.in);
                int limit = limitValue.nextInt();
                DFS dfs = new DFS(initialState, finalState, limit);
                dfs.play();
                break;

            case BFS:
                System.out.println("Breath First Search\n------------------------------");
                BFS bfs = new BFS(initialState, finalState);
                bfs.play();
                break;

            case ASTAR:
                System.out.println("A* Search Algorithm\n------------------------------\nStill being constructed");
//            ASTAR ast = new ASTAR();
//            ast.play();
                break;
            default:
                break;
        }
    }
}