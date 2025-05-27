#include "./printer.h"
#include <stdio.h>

void print(std::string message)
{
    std::printf("%s", message.c_str());
}