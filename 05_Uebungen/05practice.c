/*
Willkommen zum fünften Übungsblatt vom Programmierkurs.

Nachdem Sie in einem Terminal mittels des `cd` Befehls in das Verzeichnis gewechselt sind, in dem diese Datei liegt,
können Sie mit folgendem Befehl ihre Lösungen überprüfen:
cc -std=c11 -g -Wall 05practice_test.c -o 05practice_test.o -lm && ./05practice_test.o

Auf diesem Blatt geht es um Rekursion.
*/

#include <stdio.h>
#include "05_canvas.h"

/*
Zeichne eine vertikale Linie der Höhe `height` mit unterstem Pixel an Position `(x, y)`.

Löse die Aufgabe ohne Schleifen zu verwenden.
*/
Canvas vertical_line(Canvas c, int x, int y, int height) {
    if (height > 0 && y != canvas_height(c)) {
        c = canvas_set_black(c, x, y);
        return vertical_line(c, x, y+1 ,height-1);
    }
    return c;
    
}

/*
Wie viele Dezimalstellen hat `n` (`n` ist nicht negativ)?

Löse die Aufgabe ohne Schleifen zu verwenden.
*/
int count_digits(int n) {
    if (n/10 != 0) {
        return 1 + count_digits(n/10);
    } 
    return 1;
}

/*
Zeichne eine Pyramide: die unterste Zeile ist komplett schwarz, die zweitunterste Zeile lässt den ersten und letzten Pixel weiß, die drittunterste Zeile lässt die ersten zwei und die letzten zwei Pixel weiß, usw..

Löse die Aufgabe ohne Schleifen zu verwenden.
*/
Canvas print_row(Canvas c, int start_x, int start_y, int width) {
    // rekusriv wird ein schwarzer Punkt gesetzt um eine Reihe zu formen vom Punkt (start_x, start_y)
    // nur start_x wird dabei erhöht (Linie horizontal entlang x-Achse)

    if (start_x < width) {
        c = canvas_set_black(c, start_x, start_y);
        print_row(c, start_x+1, start_y, width);
    }
    return c;
    
}
Canvas print_pyramid(Canvas c, int x, int y, int width) {
    // solange (x,y) nicht größer ist als die Canvas-Größe, wird von unten nach oben eine schwarze Reihe gesetzt.
    // Funktion wird rekursiv wieder aufgerufen, mit jeder Reihe verringert sich die Breite um 1 und x startet eins weiter
    
    if (x < canvas_width(c) && y < canvas_height(c)) {
        c = print_row(c, x, y, width);
        print_pyramid(c, x+1, y+1, width-1);
    }
    return c;
}

Canvas pyramid(Canvas c) {
    c = print_pyramid(c, 0, 0, canvas_width(c));
    return c;
}



/*
Die Fibonaccizahlen sind wie folgt definiert:

- die nullte Fibonaccizahl ist 1,
- die erste Fibonaccizahl ist ebenfalls 1, und
- jede weitere Fibonaccizahl ist die Summe der zwei vorigen Fibonaccizahlen.

Berechne die `n`-te Fibonaccizahl.
*/
int fibonacci(int n) {
    return 0;
}

/*
Zeichne ein Rechteck der Breite `width` und der Höhe `height` mit einem Schachbrettmuster. Der Pixel der linken unteren Ecke liegt bei `(x, y)` und ist schwarz.

Löse die Aufgabe ohne Schleifen zu verwenden.
*/
Canvas chessboard_rectangle(Canvas c, int x, int y, int width, int height) {
    return c;
}

/*
Der Binomialkoeffizient von `n` und `k` ("n über k"), mit `0 <= k <= n` ist wie folgt definiert:

- bin(n, 0) = 1, sonst
- bin(n, n) = 1, sonst
- bin(n, k) = bin(n - 1, k - 1) + bin(n - 1, k)

Berechne `bin(n, k)`.
*/
int binomial_coefficient(int n, int k) {
    return 0;
}

/*
Hinweis: Diese Aufgabe ist deutlich schwieriger als die vorangegangen, und ist als besondere Herausforderung gedacht :)
Eine *knifflige* Zahl ist eine Zahl deren einzige Dezimalziffern die Vier und die Sieben sind, und in der nie zwei
Siebenen aufeinander folgen.
Berechne die Anzahl der kniffligen Zahlen mit genau `n` Dezimalziffern.

Beispiel: die kniffligen Zahlen mit drei Dezimalziffern sind 444, 447, 474, 744, 747.
*/
int tricky_numbers(int n) {
    return 0;
}
