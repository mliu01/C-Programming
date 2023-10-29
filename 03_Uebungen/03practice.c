/*
Willkommen zum dritten Übungsblatt vom Programmierkurs.

Nachdem Sie in einem Terminal mittels des 'cd' Befehls in das Verzeichnis gewechselt sind, in dem diese Datei liegt,
können Sie mit folgendem Befehl ihre Lösungen überprüfen:
cc -std=c11 -g -Wall 03practice_test.c -o 03practice_test.o -lm && ./03practice_test.o

Auf diesem Blatt geht es unter anderem um:

- Funktionsaufrufe
- Die Canvas
*/

#include <stdio.h>
#include "03_canvas.h"

/*
Geben Sie '1' zurück falls 'x' gerade ist, und '0' falls 'x' ungerade ist.
*/
int is_even(int x) {
    if (x%2 == 0) {
        return 1;
    }
    return 0;
}

/*
Geben Sie '1' zurück falls 'x' ungerade ist, und '0' falls 'x' gerade ist.
Die Ziffer '2' soll nicht direkt in Ihrer Lösung vorkommen. Nutzen Sie stattdessen 'is_even'.
*/
int is_odd(int x) {
    if (!is_even(x)) {
        return 1;
    }
    return 0;
}

/*
Erstellen Sie folgende Zeichnung auf der Canvas:
(Jedes X symbolisiert einen schwarzen Pixel an den jeweiligen (x,y)-Koordinaten)

5---------
4-X-----X-
3---------
2-X-----X-
1--XXXXX--
0---------
/012345678

Nutzen Sie am besten eine Schleife für die Mundlinie.
*/
Canvas draw_smiley(Canvas c) {

    // eyes
    canvas_set_black(c, 1, 4);
    canvas_set_black(c, 7, 4);

    // smile
    canvas_set_black(c, 1, 2);
    canvas_set_black(c, 7, 2);

    for(int i=2; i<= 6; i++) {
        canvas_set_black(c, i, 1);
    }

    return c;
}

/*
Zeichnen Sie ein klassisches Schachbrettmuster, startend bei (0,0) mit Schwarz
*/
Canvas draw_chessboard(Canvas c) {

    // x-Achse = Breite des Canvas
    for(int x = 0; x < canvas_width(c); x++) {

        // y-Achse = Länge des Canvas
        for (int y = 0; y < canvas_height(c); y++) {

            // schwarzer Tile, wenn Koordinatenpunkte beide gerade oder ungerade sind
            if (is_even(x) && is_even(y)) {
                canvas_set_black(c, x, y);

            } else if (is_odd(x) && is_odd(y)) {
                canvas_set_black(c, x, y);

            }
        }
    }
    return c;
}

/*
Diese Funktion soll gefüllte Stufen zeichnen, welche von unten links anfangend nach rechts aufsteigen.
Jede Stufe soll eine Breite von `step_width` haben und eine Höhe von `step_height` (beide sind immer größer als null).
Für mehr Details schauen Sie einfach in das Test-Feedback für den ersten Testfall.
*/
Canvas i_told_you_about_stairs(Canvas c, int step_width, int step_height) {

    int x_corr = 0; //aktueller x-Punkt für die Treppe
    int y_corr = 0; //aktueller y-Punkt für die Treppe
    int counter = 0; //benutzt um zu schauen wie oft ein Step ins Canvas passt und den X-Punkt entsprechend um so viele Steps verschiebt, die es bereits gibt

    while (y_corr<canvas_height(c)) {
        x_corr = step_width*counter; 
        
        while (x_corr<canvas_width(c)) {
            
            for(int x = x_corr; x < x_corr + step_width && x < canvas_width(c); x++) {
                for (int y = y_corr; y < y_corr + step_height && y < canvas_height(c); y++) {
                    canvas_set_black(c, x, y);
                 }   
            }
            x_corr = x_corr + step_width;
        }
        
        y_corr = y_corr + step_height;
        counter++;
    }
    return c;
}