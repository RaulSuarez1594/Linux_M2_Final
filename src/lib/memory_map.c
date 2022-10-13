/*
    The program should cause a stack overflow.
*/
#include <stdio.h>
#include <stdlib.h>

int var3 = 0;

void foo2(void) {
    printf("I've just printfed \n");
}

void foo(int var4) {

    static int var1 = 0;
    int var2 = 0;
    int* var5;
    //The variable var6 is declared as a function pointer of function foo2
    void (*var6)(void) = &foo2;
    //Variable Increment ++
    var1++;
    var2++;
    var3++;
    var4++;
    
    //A memory space is assigned to the pointer variable var5
    var5 = (int*)malloc(sizeof(int));
    
    (*var5)++;
    //Variables and memory address are printed
    printf("var1: %d at %p\n",var1, &var1);
    printf("var2: %d at %p\n",var2, &var2);
    printf("var3: %d at %p\n",var3, &var3);
    printf("var4: %d at %p\n",var4, &var4);
    printf("var5: %d at %p\n",*var5, var5);
    printf("var6: - at %p\n", var6);

    /*The function foo calls itself this causes it to 
    encounter a segmentation error*/
    foo(var4);
    
}


