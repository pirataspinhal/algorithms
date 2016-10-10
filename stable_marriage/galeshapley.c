// # pseudocode
// function stableMatching {
//     Initialize all m ∈ M and w ∈ W to free
//     while ∃ free man m who still has a woman w to propose to {
//        w = first woman on m’s list to whom m has not yet proposed
//        if w is free
//          (m, w) become engaged
//        else some pair (m', w) already exists
//          if w prefers m to m'
//             m' becomes free
//            (m, w) become engaged
//          else
//            (m', w) remain engaged
//     }
// }
//
//

#include <stdio.h>
#include <stdlib.h>

#define bool char
#define TRUE 1
#define FALSE 0

bool menLeft(int n, int* wife) {
    int i;
    for (i = 0; i < n; i++) {
        if (wife[i] != 0) {
            return TRUE;
        }
    }
    return FALSE;
}

void galeShapley(int n, int* men, int* women) {

    int i;
    // marriages
    int marriages = 0;
    int* wife = NULL;
    int* husband = NULL;
    // number of proposals
    int count[n];
    // initializes marriages
    for (i = 0; i < n; i++) {
        wife[i] = -1;
        husband[i] = -1;
        count[i] = 0;
    }

    int m = 0; // current single man index
    int w = 0; // current woman index
    while (marriages < n && count[i] < n) {
        w = men[m];
        // check if woman is free
        if (husband[w] == 0) {
            // free, marry them!
            wife[m] = w;
            husband[w] = m; 
        } else if (women[m] > women[husband[w]]) {
            // if woman is married but prefers the man that's proposing, marry them!
            wife[m] = w;

        }



    }








}
