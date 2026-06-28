#include <iostream>
#include <vector>
#include "backtrace.hpp"
int main() {
    TRACE_FUNCTION();

    fun3();

    Backtrace::printBacktrace();

    return 0;
}
