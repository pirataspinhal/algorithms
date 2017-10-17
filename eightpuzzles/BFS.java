package com.trustgeek.puzzles.eightpuzzles;

import java.util.*;
import java.util.Queue;
public class BFS {
    String goalState = "123456780";
    int count = 0;
    Queue<State> queue = new LinkedList<State>();
    State root=null;
    BFS(String rootState, String finalState ) {
        this.goalState = finalState;
        root = new State(rootState);  
        root.setParent(null);
        queue.add(root);
        // System.out.println("Root Parent: " + root.getParent());
    }

    private static boolean checkRepeats(State n) {
        boolean containValue = false;
        State checkNode = n;

        // While n's parent isn't null, check to see if it's equal to the node
        // we're looking for.
        while (n.getParent() != null && !containValue) {
            if (n.getParent().toString().equals(checkNode.toString())) {
                containValue = true;
            }
            n = n.getParent();
        }

        return containValue;
    }

    public void play() {
        State soln =  traverse(root);
        printpath(soln);
    }

    public State traverse(State root) {
        State curState = null;
        while (!queue.isEmpty()) {
            curState = queue.poll();
            if (!curState.toString().equals(goalState)) {
                ArrayList<State> possibleMoves = curState.getChild();
                for (State st : possibleMoves) {
                    if (!checkRepeats(st))
                        queue.add(st);
                    count++;
                }
            } else {
                return curState;
            }
        }
        return null;
    }

    public  void printpath(State soln) {
        if (soln == null)
            System.out.println("No solution found.");
        else {
            System.out.println("Solution is given below: ");
            List<State> correctSolns = new ArrayList<State>();
            State st = soln;
            while (st != null) {
                correctSolns.add(st);
                st = st.getParent();
            }
            System.out.println("Size: " + correctSolns.size());
            for (int i = correctSolns.size() - 1; i >= 0; i--) {
                st = correctSolns.get(i);
                // System.out.println(st.toString());
                st.printState();
                System.out.println();
            }
        }
    }
}