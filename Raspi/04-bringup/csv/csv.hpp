#ifndef D5103694_D163_4EEC_BAAF_B64DBD9E9E03
#define D5103694_D163_4EEC_BAAF_B64DBD9E9E03

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
class write{
    public:
        write()=default;
        bool write_csv(const std::string &filename,const std::vector<std::string> &data);
};
#endif /* D5103694_D163_4EEC_BAAF_B64DBD9E9E03 */
