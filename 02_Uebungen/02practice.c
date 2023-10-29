/*
Willkommen zum zweiten Übungsblatt vom Programmierkurs. Alles funktioniert wie auch beim ersten Aufgabenblatt.

Nachdem Sie in einem Terminal mittels des 'cd' Befehls in das Verzeichnis gewechselt sind, in dem diese Datei liegt,
können Sie mit folgendem Befehl ihre Lösungen überprüfen:
cc -std=c11 -g -Wall 02practice_test.c -o 02practice_test.o -lm && ./02practice_test.o

Auf diesem Blatt geht es unter anderem um:

- if, else und else-if
- logisches und und logisches oder (`&&` und `||`)
- verschachtelte while und for loops
*/

#include <stdio.h>

int least_common_multiple_with_8(int n) {
    int result = 0;
    /*
    Least Common Multiple With 8:
    Das kleinste gemeinsame Vielfache zweier Zahlen ist die kleinste Zahl, welche ein ganzzahliges Vielfaches von sowohl
    der einen als auch der anderen ist.
    Beispielsweise ist das kleinste gemeinsame Vielfache von 8 und 10 die 40, da '40 = 8 * 5', '40 = 10 * 4', und es
    kein kleineres gemeinsames Vielfaches gibt.

    Weisen Sie der Variable 'result' das kleinste gemeinsame Vielfache von 'n' und '8' zu.
    */
    /* BEGIN CHANGES */
    int smaller = 8;
    int bigger = n;
    if (smaller>bigger) {
        smaller = n;
        bigger = 8;
    }

    for(int i = 1; result==0; i++) {
        if (bigger*i % smaller == 0) {
            result = bigger*i;
        }
    }
    /* END CHANGES */
    return result;
}

int sum_least_common_multiples_with_8(int n) {
    int result = 0;
    /*
    Sum Of Least Common Multiples With 8:
    Weisen Sie der Variable 'result' die Summe der kleinsten gemeinsamen Vielfachen mit 8 der Zahlen von 1 bis 'n' zu.

    Beispeiel: Das KGV von 1 und 8 ist 8, das KGV von 2 und 8 ist 8, das KGV von 3 und 8 ist 24, also ist result für
    'n := 3' der Wert '8 + 8 + 24 = 40'
    */
    /* BEGIN CHANGES */
    for(int i=1; i<=n; i++) {
        result = result + least_common_multiple_with_8(i);
    }
    /* END CHANGES */
    return result;
}

int sum_first_powers(int n) {
    int result = 0;
    /*
    Sum First Powers:
    Weisen Sie der Variable `result` die Summe `n^0 + n^1 + n^2 + n^3 + ... + n^n` zu.
    Beispiel für `n = 4`: `4^0 + 4^1 + 4^2 + 4^3 + 4^4 = 1 + 4 + 16 + 64 + 256 = 341`.
    */
    /* BEGIN CHANGES */
    int power = n;
    for (int i = 0; i<=n; i++) {

        if (i==0) result = result + 1;

        else if (i==1) result = result + n;
        
        else {
            power = power * n;
            result = result + power;
        }

    }  
    /* END CHANGES */
    return result;
}
/*
Schreiben Sie ein paar nette Muster ins Terminal.


Muster 1: k-square (im Beispiel unten ist k := 8)

########
########
########
########
########
########
########
########

Muster 2: k-diagonal (im Beispiel unten ist k := 8)

#
##
###
####
#####
######
#######
########

Muster 3: k-arrow (im Beispiel unten ist k := 8)

#
##
###
####
####
###
##
#

Muster 4: k-chessboard (im Beispiel unten ist k := 8)

 # # # #
# # # # 
 # # # #
# # # # 
 # # # #
# # # # 
 # # # #
# # # # 

Muster 5: k-pyramid (im Beispiel unten ist k := 8)

   ##
  ####
 ######
########

Muster 6: k-spiral (im Beispiel unten ist k := 16)

################
               #
############## #
#            # #
# ########## # #
# #        # # #
# # ###### # # #
# # # ## # # # #
# # # #  # # # #
# # # #### # # #
# # #      # # #
# # ######## # #
# #          # #
# ############ #
#              #
################



*/