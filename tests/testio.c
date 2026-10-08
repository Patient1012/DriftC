
#include <driftc/io.h>

int main(void)
{
    println("Hello, %s!", "Drift");
    println("Integer: %i", 42);
    println("Float: %f", 3.14);
    println("Character: %c", 'A');
    println("100%% complete");

    char name[64];

    print("Enter your name: ");

    if (readln(name, sizeof name)) {
        println("Hello, %s!", name);
    }

    return 0;
}
