#include <iostream>
#include <vector>
#include "class_back.hpp"
int main() {
    TRACE_FUNCTION();

    fun3();

    Backtrace::printBacktrace();

    return 0;
}
