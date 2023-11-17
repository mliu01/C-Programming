#include <stdio.h>
#include <string.h>
#include "introprog_countsort.h"
#include "arrayio.h"

/* Ab hier Funktion count_sort_calculate_counts implementieren */
void count_sort_calculate_counts(int arr_in[], int len, int c_arr[]) {
    for (int i = 0; i < MAX_VALUE; i++) {
        c_arr[i] = 0;
    }

    for (int j = 0; j < len; j++) {
        c_arr[arr_in[j]]++;
    }
}

/* Ab hier Funktion count_sort_write_output_array implementieren */
void count_sort_write_output_array(int arr_out[], int c_arr[], SortDirection order) {
    int k = 0;

    for (int j = 0; j < MAX_VALUE; j++) {
        for (int i = 0; i < c_arr[j]; i++) {
            if (order == ASCENDING) {
                arr_out[k] = j;
            } else if (order == DESCENDING) {
                arr_out[k] = MAX_VALUE - j;
            }
            k++;
        }
    }
}

/* Ab hier Funktion extract_order_direction implementieren */
SortDirection extract_order_direction(char *order) {
    if (strcmp(order, "asc") == 0) {
        return ASCENDING;
    } else if (strcmp(order, "desc") == 0) {
        return DESCENDING;
    } else {
        return NOTDEFINED;
    }
}

/* Ab hier Funktion count_sort implementieren und entsprechende Funktionsaufrufe einfügen */
void count_sort(int arr_in[], int len, int arr_out[], SortDirection order) {
    int c_arr[MAX_VALUE];
    count_sort_calculate_counts(arr_in, len, c_arr);
    count_sort_write_output_array(arr_out, c_arr, order);
}


int main(int argc, char *argv[]) {
    if (argc < 3){
        printf("Aufruf: %s <Dateiname> asc|desc\n", argv[0]);
        printf("Beispiel: %s zahlen.txt asc\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];

    /*
     * Hier die Sortierrichtung einlesen und einer Variablen
     * des Datentypes SortDirection (siehe h-Datei) verwenden.
     * Beenden des Programmes mit derselben Ausgabe der Hilfe (siehe Anfang main-Funktion).
     * implementieren Sie zur Umwandlung die Funktion extract_order_direction
     */
    char *sort_direction = argv[2];
    SortDirection direction = extract_order_direction(sort_direction);
    if (direction == NOTDEFINED) {
        printf("Ungültige Sortierrichtung: %s\n", sort_direction);
        printf("Gülltige Sortierrichtungen sind: asc ODER desc \n");
        return 1;
    }


    int input_array[MAX_LAENGE];
    int len = read_array_from_file(input_array, MAX_LAENGE, filename);

    printf("Unsortiertes Array:");
    print_array(input_array, len);

    /*
     * Hier count_sort aufrufen und alle nötigen Deklarationen einfügen!
     */
    int output_array[MAX_LAENGE];

    count_sort(input_array, len, output_array, direction);

    printf("Sortiertes Array:");

    /* Folgende Zeile einkommentieren, um das Array auszugeben! */
    print_array(output_array, len);

    return 0;
}
