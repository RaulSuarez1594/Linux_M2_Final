#include <stdio.h>
#include "./src/include/memory_leaks.h"
#include "./src/include/memory_map.h"

int main(int argc, char const *argv[])
{
    memory_leaks();
    memory_map(0);

    return 0;
}
