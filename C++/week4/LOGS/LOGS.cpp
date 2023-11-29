#include <fstream>
#include <iostream>
#include <string>
#include <system_error>

class logger{
    public:
        enum loglevel{
            INFO,
            WARN,
            ERROR
        };
        logger(const std::string& filename):filename(filename){}
        void log(loglevel level,const std::string& massage){
            std::ofstream file(filename,std::ios::app);
            if(file.is_open()){
                file<<loglevelstring(level)<<" : "<<massage<<std::endl;

            }
            file.close();
        }

        void dump(){
            std::ifstream file(filename);
            if(file.is_open()){
                std::string line;
                while (std::getline(file,line)) {
                    std::cout<<line<<std::endl;
                
                }
            }
            file.close();
        }
        void clear(){
            std::ofstream file(filename,std::ios::trunc);
            file.close();
        }
    private:
        std::string filename;
        
        std::string loglevelstring(loglevel level){
            switch (level) {
                case INFO:
                    return "INFO";
                case WARN:
                    return "WARN";
                case ERROR:
                    return "ERROR";
                default:
                    return "unknown";
            
            }
        }

};
int main(){
    logger log("file.txt");
    std::string userinput;
    std::cout<<" enter a message : ";
    std::getline(std::cin,userinput);

    if((userinput.find("warning" )) != std::string::npos){
        log.log(logger::WARN,userinput);
    } 
    else if(userinput.find("INFO")  != std::string::npos) {
      log.log(logger::INFO, userinput);
    }
    else {
        log.log(logger::ERROR, userinput);
        // log.clear();
    }
    log.dump();
    // log.clear();

    return 0;
}