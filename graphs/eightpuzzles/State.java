package com.trustgeek.puzzles.eightpuzzles;

import java.util.*;

public class State {
    private Status curSt = Status.UNVISITED;
    private ArrayList<State> child = null;
    // private int hammingDistance = 0, wrongPlaced = 0;
    private String state = null;
    private int[] valueChild = null;
    public State parent = null;
    private int childCount = 0;
    private String goalState;
    State strmove = null;

    State(String state) {
        this.state = state;
    }

    public Status getStatus() {
        return curSt;
    }

    public void setStatus(Status st) {
        this.curSt = st;
    }

    public void printNode() {
        System.out.println(this.state);// + "- " + this.curSt.toString()+" - "+this.parent);
    }

    ArrayList<State> childCompute() {
        ArrayList<State> lst = new ArrayList<State>();
        if ((strmove = moveUp(state)) != null) {
            lst.add(strmove);
            childCount++;
        }
        if ((strmove = moveRight(state)) != null) {
            lst.add(strmove);
            childCount++;
        }
        if ((strmove = moveDown(state)) != null) {
            lst.add(strmove);
            childCount++;
        }
        if ((strmove = moveLeft(state)) != null) {
            lst.add(strmove);
            childCount++;
        }
        return lst;
    }

    public ArrayList<State> getChild() {
        return childCompute();
    }
    public void setParent(State parentState) {
        this.parent = parentState;
    }
    public State getParent() {
        return parent;
    }

    public State moveLeft(String s) {
        int a = s.indexOf("0");
        if (a != 0 && a != 3 && a != 6) {
            State temp = new State(s.substring(0, a - 1) + "0" + s.charAt(a - 1) + s.substring(a + 1));
            temp.setParent(this);
            return temp;
        }
        return null;
    }

    public State moveUp(String s) {
        int a = s.indexOf("0");
        if (a > 2) {
            State temp =  new State(s.substring(0, a - 3) + "0" + s.substring(a - 2, a) + s.charAt(a - 3) + s.substring(a + 1));
            temp.setParent(this);
            return temp;
        }
        return null;
    }

    public State moveRight(String s) {
        int a = s.indexOf("0");
        if (a != 2 && a != 5 && a != 8) {
            State temp = new State(s.substring(0, a) + s.charAt(a + 1) + "0" + s.substring(a + 2));
            temp.setParent(this);
            return temp;
        }
        return null;
    }

    public State moveDown(String s) {
        int a = s.indexOf("0");
        if (a < 6) {
            State temp =  new State(s.substring(0, a) + s.substring(a + 3, a + 4) + s.substring(a + 1, a + 3) + "0" + s.substring(a + 4));
            temp.setParent(this);
            return temp;
        }
        return  null;
    }

    public int getChildCount() {
        return childCount;
    }

    public void printState() {
        String[][] test = new String[3][3];
        int n = 0 ;
        //1. change string to matrix representation
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                test[i][j] = this.state.substring(n, n + 1);
                n++;
            }
        }
        // System.out.println(this.state);
        //2. print the matrix representation
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {

                System.out.print(" | " + ((test[i][j] != "0") ? test[i][j] : " "));
            }
            System.out.println(" |");
        }
    }

    @Override
    public String toString() {
        return  state;
    }

}