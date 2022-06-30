#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//shuffles the array values in random order
void shuffle(int *array, size_t n) {

    if (n > 1) 
    {
        size_t i;
        for (i = 0; i < n - 1; i++) 
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}

//creates an array of a given dimension, shuffles it and finds the loop with
//the higher value
int maxLoop(int dim) {
    //filling the array
    int array[dim];
    for (int i = 0; i < dim; i++) {
        array[i] = i;
    }

    //shuffling the array
    shuffle(array, dim);
    int max = 0;
    for (int i = 0; i < dim; i++) {
        int lunghezzaLoop = 1;
        int j = i;
        while (array[j] != i) {
            lunghezzaLoop++;
            j = array[j];
        }
        if (lunghezzaLoop > max) {
            max = lunghezzaLoop;
        }
    }
    return max;
}



int main() {
    srand(time(NULL));
    int count = 0;
    for (int i = 0; i < 1000; i++) {
        if(maxLoop(100) < 50) {
            count++;
        }
    } 
    printf("%f\n", (float)count/1000);
    
}
