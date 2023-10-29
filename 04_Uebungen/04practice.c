/*
Willkommen zum vierten Übungsblatt vom Programmierkurs.

Nachdem Sie in einem Terminal mittels des 'cd' Befehls in das Verzeichnis gewechselt sind, in dem diese Datei liegt,
können Sie mit folgendem Befehl ihre Lösungen überprüfen:
cc -std=c11 -g -Wall 04practice_test.c -o 04practice_test.o -lm && ./04practice_test.o

Auf diesem Blatt geht es primär darum, komplexe Probleme erfolgreich anzugehen.
*/

#include <stdio.h>
#include "04_canvas.h"

/*
Nehme eine dreistellige Zahl, sortiere ihre Ziffern absteigend, und subtrahiere von dieser Zahl die Zahl die
sich aus den aufsteigend sortierten Ziffern ergibt.
Wiederhole, bis zwei mal in Folge die gleiche Zahl herauskommt.

Beispiel:

792 ~> 972 - 279 = 693
693 ~> 963 - 369 = 594
594 ~> 954 - 459 = 495
495 ~> 954 - 459 = 495

Gebe in dieser Funktion zurück, wie viele Schritte die dreistellige Eingabezahl 'n' braucht, um bei einer Zahl anzukommen,
bei der die sortiere-und-subtrahiere Prozedur wieder die Zahl selbst ausgibt.

Beispiele: 'kaprekar_count_steps(792) == 3', 'kaprekar_count_steps(693) == 2',
           'kaprekar_count_steps(594) == 1', 'kaprekar_count_steps(495) == 0'

Hinweis: Sollte die Eingabe 'x' kleiner als 100 sein (also weniger als 3 Dezimalstellen besitzen), sollte sie trotzdem
dreistellig behandelt werden, indem Nullen vorangesetzt werden. D.H. 64 ~> 640 - 046 = 594.
*/
int absteigend(int x) {
    int a = x%10;
    int b = x/10 %10;
    int c = x/100 % 10;

    if (a>=b && a>=c) {
        a = a*100;
        if (b>=c) {
            b = b*10;
        } else {
            c = c*10;
        }
    }
    else if (b>=a && b>=c) {
        b = b*100;
        if (a>=c) {
            a = a*10;
        } else {
            c = c*10;
        }
    }
    else {
        c = c*100;
        if (a>=b) {
            a = a*10;
        } else {
            b = b*10;
        }
    }

    return a+b+c;
}
int aufsteigend(int x) {
    int a = x%10;
    int b = x/10 %10;
    int c = x/100 % 10;

    if (a<=b && a<=c) {
        a = a*100;
        if (b<=c) {
            b = b*10;
        } else {
            c = c*10;
        }
    }
    else if (b<=a && b<=c) {
        b = b*100;
        if (a<=c) {
            a = a*10;
        } else {
            c = c*10;
        }
    }
    else {
        c = c*100;
        if (a<=b) {
            a = a*10;
        } else {
            b = b*10;
        }
    }

    return a+b+c;
}

int kaprekar_count_steps(int x) {

    int current = absteigend(x) - aufsteigend(x);
    int next = -1;
    int count = 0;

    if (x==current) {
        return count;
    } else {
        while (current != next) {
            next = current;
            current = absteigend(next) - aufsteigend(next);
            count++;
        }
    }
    return count;
}

/*
Färbe alle Pixel (mit den Koordinaten '(x, y)') auf dem Canvas schwarz, für welche die sortiere-und-subtrahiere Aktion
von 'x' die Zahl 'y' ergibt.

Bonus: Gibt es ein Muster, dass man ausnutzen kann um 'kaprekar_count_steps' effizienter zu implementieren als
alle Schritte durchzuführen?
*/
int kaprekar(int x, int y) {

    int current = absteigend(x) - aufsteigend(x);
    int goal = y;

    if (current == goal) return 1;
    else {
        for (int i = 0; i<200; i++) {
            current = absteigend(current) - aufsteigend(current);
            if (current == goal) {
                return 1;
            } else {
                return 0;
            }
            
        }
    }
    
    return 0;

}


Canvas plot_kaprekar(Canvas c) {
    for(int i=0; i<canvas_width(c); i++) {
        for (int j=0; j<canvas_height(c); j++) {
            if (kaprekar(i,j) == 1) {
                canvas_set_black(c, i, j);
            }
        }
    }
    return c;
}


