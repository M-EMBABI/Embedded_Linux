#ifndef DFB3D859_32A8_40F3_B7CE_D5546FEF0E33
#define DFB3D859_32A8_40F3_B7CE_D5546FEF0E33
#include <iostream>
#include <vector>
class Backtrace {
public:
    std::string name;
    Backtrace(std::string name) : name(name) {
        std::cout << "Enter to [" << name << "]" << std::endl;
        backtrace.push_back(name);
    }

    ~Backtrace() {
        std::cout << "Exit from [" << name << "]" << std::endl;
    }

    static void printBacktrace() {
        std::cout << "Backtrace as follows:" << std::endl;
        for (size_t i = 0; i < backtrace.size(); ++i) {
            std::cout << i << "- " << backtrace[i] << std::endl;
        }
        std::cout << "Back Trace is Finished" << std::endl;
    }

private:
    static std::vector<std::string> backtrace;
};

std::vector<std::string> Backtrace::backtrace;

#define TRACE_FUNCTION() \
    Backtrace b(__PRETTY_FUNCTION__);

void fun1() {
    TRACE_FUNCTION();
}

void fun2() {
    TRACE_FUNCTION();
    fun1();
}

void fun3() {
    TRACE_FUNCTION();
    fun2();
}


#endif /* DFB3D859_32A8_40F3_B7CE_D5546FEF0E33 */
