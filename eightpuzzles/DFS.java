package com.trustgeek.puzzles.eightpuzzles;

import java.util.*;
class DFS {
    int depth = 5; //default depth for DFS is 5
    Stack<State> stack = new Stack<State>();
    State root = null;
    String finalState;
    DFS(String initialState, String finalState, int depth) {
        // this.initialState = initialState;
        this.finalState = finalState;
        this.depth = depth;

        root = new State(initialState);
        stack.add(root);
    }

    //find the next States that are possible from the given State
    private static boolean checkRepeats(State n) {
        boolean containValue = false;
        State checkState = n;

        // While n's parent isn't null, check to see if it's equal to the State
        // we're looking for.
        while (n.getParent() != null && !containValue) {
            if (n.getParent().toString().equals(checkState.toString())) {
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
        while (!stack.isEmpty()) {
            curState = stack.pop();
            if (!curState.toString().equals(finalState)) {
                ArrayList<State> possibleMoves = curState.getChild();
                for (State st : possibleMoves) {
                    if (!checkRepeats(st))
                        stack.add(st);
                    // count++;
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