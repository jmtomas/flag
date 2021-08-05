#include <stdio.h>
#include "../flag.h"

int main() {
        int test1 = flag_int("-j", 69, "<number of cores> Specifies the number of cores to be used.");
        printf("This is the first test argument: %d\n", test1);
        return 0;
}
