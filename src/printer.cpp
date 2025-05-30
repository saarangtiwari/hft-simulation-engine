#include "./printer.h"
#include <stdio.h>

void print(std::string message)
{
    std::printf("%s\n", message.c_str());
}