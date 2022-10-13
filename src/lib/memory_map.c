#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

#include <stdio.h>
#include <stdlib.h>
#define MAX 1024

int var3 = 0;

void foo2(void) {
    printf("I've just printfed \n");
}

void foo(int var4) {
    // Declaring big arrays so that it takes fewer function calls to overflown the stack.
    size_t buffer_1[1024] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    size_t buffer_2[1024] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    size_t buffer_3[1024] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    size_t buffer_4[1024] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    static int var1 = 0;
    int var2 = 0;
    int* var5;
    void (*var6)(void) = &foo2;
    var1++;
    var2++;
    var3++;
    var4++;
    
    var5 = (int*)malloc(sizeof(int));
    
    (*var5)++;
    
    printf("=============================\n");
    printf("var1: %3d at %15p\n",var1, &var1);
    printf("var2: %3d at %15p\n",var2, &var2);
    printf("var3: %3d at %15p\n",var3, &var3);
    printf("var4: %3d at %15p\n",var4, &var4);
    printf("var5: %3d at %15p\n",*var5, var5);
    printf("var6:  -  at %15p\n", var6);
    printf("This function has called itself %d times\n", var4);
    // This function calls itself every time.
    foo(var4);

}