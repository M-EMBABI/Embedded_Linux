#include "csv.hpp"


bool write::write_csv(const std::string &filename,const std::vector<std::string> &data){
    std::ofstream file(filename);

    for (const auto &row : data)
    {
        for(size_t i = 0 ; i<row.size();i++){
            file<<row[i];
            if(i != row.size() -1 ){
                file << ",";
            }
        }
        file <<std::endl;
        /* code */
    }
    return true;
    
}
