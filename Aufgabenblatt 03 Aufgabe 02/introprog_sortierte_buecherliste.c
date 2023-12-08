#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "introprog_sortierte_buecherliste.h"
#include "introprog_buecherliste.h"
#include "introprog_structs_lists_input.h"

/* Fuege ein Element in die Liste ein, sodass die Liste aufsteigend
 * nach ISBN sortiert ist.  Dafür muss das erste Element ermittelt
 * werden, das in der bisher sortierten Liste eine ISBN besitzt,
 * die größer ist als die des neuen Elements.  Wenn die Liste leer
 * ist, soll das Element direkt an den Anfang platziert werden.
 *
 * first    - Pointer auf das erste Element (bzw. Anfang) der Liste
 * new_elem - Pointer auf das neues Element das in die Liste
 * eingefuegt werden soll
 *
 * Gib einen Pointer auf den neuen oder alten Anfang der Liste
 * zurueck.
 */
element* insert_sorted(element* first, element* new_elem) {
    /* HIER implementieren. */
    if (first == NULL || new_elem->isbn < first->isbn) {
        new_elem->next = first;
        return new_elem;
    }

    element* current = first;
    while (current->next != NULL && current->next->isbn < new_elem->isbn) {
        current = current->next;
    }

    new_elem->next = current->next;
    current->next = new_elem;

    return first;
}

/* Lese die Datei ein und fuege neue Elemente in die Liste ein 
 * _Soll nicht angepasst werden_
 */
void read_list_sorted(char* filename, list *alist) {
    element* new_elem;
    char* new_title;
    char* new_author;
    uint32_t new_year;
    uint64_t new_isbn;
    read_line_context ctx;
    open_file(&ctx, filename);
    while(read_line(&ctx, &new_title, &new_author, &new_year, &new_isbn) == 0) {
        new_elem = construct_element(new_title, new_author, new_year, new_isbn);
        alist->first = insert_sorted(alist->first, new_elem);
        alist->count++;
    }
}