#include <stdio.h>
#include <string.h>


//some command line arguments
int main(int argc, char* argv[]) {
    for(int i = argc; i >= 0; i--) {
        printf("%s\n", argv[i]);
    }
    return 0;
}