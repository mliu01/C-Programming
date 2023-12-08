#include <stdlib.h>
#include <string.h>
#include <math.h>  // definiert den speziellen Wert NaN für floats
#include "introprog_stacks-rpn.h"
#include "introprog_input_stacks-rpn.h"

/* 
 * Füge Element am Anfang des Stacks ein
 *
 * char* - Ein Pointer auf den Stack.
 * float - Zahl, die als neues Element auf den Stack gelegt
 *         werden soll.
 */
void stack_push(stack* astack, float value)
{
    /* HIER implementieren */
    stack_element* new_elem = (stack_element*)malloc(sizeof(stack_element));
    new_elem->value = value;
    new_elem->next = astack->top;
    astack->top = new_elem;
}

/* 
 * Nehme das letzte eingefügte Element vom Anfang des Stacks
 * Gebe NaN zurück, wenn keine Element vorhanden ist.
 *
 * stack* - Ein Pointer auf den Stack
 *
 * Gebe die im Element enthaltenen Zahl zurück
 */
float stack_pop(stack* astack)
{
    /* HIER implementieren */
    if (astack->top == NULL) {
        return NAN;
    }

    float value = astack->top->value;
    stack_element* tmp = astack->top;
    astack->top = astack->top->next;
    free(tmp);

    return value;
}

/*
 * Führt abhängig von dem Token eine entsprechende Operation auf
 * dem Stack aus.  Wenn es sich bei dem Token um
 *  -> eine Zahl handelt, dann konvertiere die Zahl mithilfe von
 *     atof() zu einem float und lege sie auf den Stack.
 *  -> einen Operator handelt, dann nehme zwei Zahlen vom Stack,
 *     führe die Operation aus und lege das Resultat auf den Stack.
 *  -> eine nichterkennbare Zeichenkette handelt, dann tue nichts.
 *
 * stack*  - Ein Pointer auf den Stack
 * char*  - Eine Zeichenkette
 */
void process(stack* astack, char* token)
{
    /* HIER implementieren */
    if (is_number(token)) {
        float value = atof(token);
        stack_push(astack, value);

    } else if (is_add(token) || is_sub(token) || is_mult(token)) {
        float zahl2 = stack_pop(astack);
        float zahl1 = stack_pop(astack);

        if (zahl1 != NAN && zahl2 != NAN) {
            float ergebnis = 0.0;

            if (is_add(token)) {
                ergebnis = zahl1 + zahl2;

            } else if (is_sub(token)) {
                ergebnis = zahl1 - zahl2;

            } else if (is_mult(token)) {
                ergebnis = zahl1 * zahl2;

            }

            stack_push(astack, ergebnis);

        } else {
            stack_push(astack, NAN);
        }
    }
    return;
    /* Du kannst zur Erkennung der Token folgende Hilfsfunktionen
     * benutzen:
     *
     * Funktion          Rückgabewert von 1 bedeutet
     * ---------------------------------------------
     * is_add(token)     Token ist ein Pluszeichen
     * is_sub(token)     Token ist ein Minuszeichen
     * is_mult(token)    Token ist ein Multiplikationszeichen
     * is_number(token)  Token ist eine Zahl
     */
}

/* 
 * Erstelle einen Stack mit dynamischem Speicher.
 * Initialisiere die enthaltenen Variablen.
 *
 * Gebe einen Pointer auf den Stack zurück.
 */
stack* stack_erstellen() {
    /* HIER implementieren */
    stack* new_stack = (stack*)malloc(sizeof(stack));
    new_stack->top = NULL;
    return new_stack;
}