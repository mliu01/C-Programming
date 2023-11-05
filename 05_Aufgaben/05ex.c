/*
Willkommen zum fünften Aufgabenblatt vom Programmierkurs. Auf diesem Aufabenblatt geht es um Rekursion.

Um die Tests für dieses Blatt zu kompilieren und zu starten, führen Sie den folgenden Befehl aus:
cc -std=c11 -g -Wall 05ex_test.c -o 05ex_test.o -lm && ./05ex_test.o
*/

#include "05_canvas.h"
#include <stdio.h>
#include <math.h>

/*
Aufgabe 1a:
Zeichnen Sie eine horizontale Linie der Länge `width`, deren am weitesten links liegender Pixel bei `(x, y)` ist.

_Benutzen Sie keine Schleifen - Die Aufgabe soll über Rekursion gelöst werden!_

*/
Canvas recursive_line(Canvas c, int x, int y, int width) {
    if (width > 0) {
        if (x>=0 && x < canvas_width(c)) {
            c = canvas_set_black(c, x, y);
        }
        return recursive_line(c, x+1, y, width-1);
    }
    return c;
}

/*
Aufgabe 1b:
Zeichnen Sie ein Rechteck mit der Breite `width` und der Höhe `height`. Der Pixel der linken unteren Ecke liegt bei `(x, y)`.

_Benutzen Sie keine Schleifen, die Aufgabe soll über Rekursion gelöst werden!_
*/
Canvas recursive_rectangle(Canvas c, int x, int y, int width, int height) {
    if (height > 0) {
        if (y >= 0 && y < canvas_height(c)) {
            c = recursive_line(c, x, y, width);
        }
        return recursive_rectangle(c, x, y+1, width, height-1);
    }
    return c;
}

/*
Aufgabe 2:
Der *Sierpinski Carpet der Ordnung 0* ist ein einzelnes schwarzes Pixel.
Der *Sierpinski Carpet der Ordnung n+1* besteht aus acht Sierpinski Carpets der Ordnung n, angeordnet als drei-mal-drei
Quadrat dessen Mittelstück fehlt.

Beispiele (`X` stellt schwarze Pixel dar)
=========================================

Ordnung 0:

X

Ordnung 1:

XXX
X X
XXX

Ordnung 2:

XXXXXXXXX
X XX XX X
XXXXXXXXX
XXX   XXX
X X   X X
XXX   XXX
XXXXXXXXX
X XX XX X
XXXXXXXXX

Siehe auch die Datei `05sierpinski.jpg`

Aufgabe 2a:
Um in der nächsten Aufgabe den Sierpinski-Carpet auf die Canvas zeichnen zu können müssen Potenzen berechnet werden.
Implementieren Sie die Berechnung der Potenz einer nicht-negativen, ganzzahligen Basis `b` mit einem
nicht-negativen, ganzzahligen Exponenten `exp`.

_Benutzen Sie keine Schleifen, die Aufgabe soll über Rekursion gelöst werden!_
*/
int power(int b, int exp){
    if (exp == 0) {
        return 1;
    }
    return b * power(b, exp-1);
}

/*
Aufgabe 2b:
Diese Funktion soll den Sierpinski Carpet der Ordnung `n` auf die Canvas zeichnen, mit unterer linker Ecke an Koordinate `(x, y)`.

_Benutzen Sie keine Schleifen, die Aufgabe soll über Rekursion gelöst werden!_
*/

Canvas draw(Canvas c, int n, int x, int y, int size, int sector) {
    if (n == 0) {
        return canvas_set_black(c, x, y);
    }

    if (sector > 0) { // acht "Koordinaten" für jeden Pixel
        c = draw(c, n-1, x, y, sector, sector/3);                           // Pixel/Bereich unten links
        c = draw(c, n-1, x + sector, y, sector, sector/3);                  // unten mitte
        c = draw(c, n-1, x + sector*2, y, sector, sector/3);                // unten rechts
        c = draw(c, n-1, x, y + sector, sector, sector/3);                  // mitte links
        c = draw(c, n-1, x + sector*2, y + sector, sector, sector/3);       // mitte rechts
        c = draw(c, n-1, x, y + sector*2, sector, sector/3);                // oben links
        c = draw(c, n-1, x + sector, y + sector*2, sector, sector/3);       // oben mitte
        c = draw(c, n-1, x + sector*2, y + sector*2, sector, sector/3);     // oben rechts
    }
    
    return c;
}

Canvas sierpinski_carpet(Canvas c, int n, int x, int y) {
    int size = power(3, n);
    int sector = size/3;

    return draw(c, n, x, y, size, sector);
}



/*
Aufgabe 3:
Implementieren Sie einen Fülleimer. Gegeben eine Koordinate `(x, y)` auf einer (bereits bemalten) Canvas, soll die komplette
zusammenhängende Fläche aller Pixel der selben Farbe (schwarz oder weiß) schwarz gefärbt werden.
Zwei Pixel sind Teil der selben Fläche wenn sie die selbe Farbe haben und direkt benachbart sind. Jeder Pixel hat bis
zu vier direkte Nachbarn - die Diagonalen zählen nicht.

Funktionen, um die Farbe eines Pixels auf der Canvas zu bestimmen, sind im Headerfile der Canvas dokumentiert.
*/
Canvas bucket_fill(Canvas c, int x, int y) {
    return c;
}
