// wrapper.c
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <string.h>
#include <time.h>

typedef void (*sort_fn)(int *, int);

void genera_random(int *arr, int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 10000;
}

int main(int argc, char *argv[]) {
    float med=0;
    srand(time(NULL));
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <file.c>\n", argv[0]);
        return 1;
    }

    // 1. Compila il file in input come shared library
    char cmd[512];
    snprintf(cmd, sizeof(cmd),
        "gcc -O0 -shared -fPIC -o /tmp/libsort.so %s", argv[1]);
    system(cmd);

    // 2. Carica la libreria
    void *handle = dlopen("/tmp/libsort.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "dlopen: %s\n", dlerror());
        return 1;
    }

    sort_fn sort       = dlsym(handle, "sort");
    long long *conf    = dlsym(handle, "confronti");
    long long *scambi  = dlsym(handle, "scambi");

    // 3. Testa su n crescenti e stampa rapporti
    int sizes[] = {100, 200, 400, 800, 1600, 3200};
    int m = sizeof(sizes) / sizeof(sizes[0]);

    printf("%-8s %-12s %-10s\n", "n", "confronti", "rapporto");
    long long prev = 0;

    for (int i = 0; i < m; i++) {
        int n = sizes[i];
        int *arr = malloc(n * sizeof(int));
        genera_random(arr, n);

        sort(arr, n);

        double rapporto = (prev > 0) ? (double)(*conf) / prev : 0;
        printf("%-8d %-12lld %-10.2f\n", n, *conf, rapporto);
        med+=rapporto;
        prev = *conf;

        free(arr);
    }
    med/=(m-1);
    if (med > 1.9 && med < 2.1)
    printf("Complessità: O(n)\n");
    else if (med >= 2.1 && med < 3.0)
    printf("Complessità: O(nlog(n))\n");
    else if (med >= 3.5 && med < 4.5)
    printf("Complessità: O(n^2)\n");
    else
    printf("Complessità: non classificabile\n");

    dlclose(handle);
    return 0;
}