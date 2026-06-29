
class logs{
    private:
        std::string filename;     

    public:
        
        enum class loglevel{
            INFO,
            WARN,
            ERROR
    
        };
        
        std::string loglevelstring(loglevel level){
            switch(level){
                case loglevel::INFO:
                    return "INFO";
                case loglevel::WARN:
                    return "WARN";
                case loglevel::ERROR:
                    return "ERROR";
                default:
                    return "unknown";
            }
        }

        logs(const std::string &filename):filename(filename){}
        void log(loglevel level , const std::string &massage);
        void dump();
        void clear();

};

void logs::log(loglevel level , const std::string &massage){
    std::ofstream file(filename,std::ios::app);
    if(file.is_open()){
        file<<loglevelstring(level)<<" : "<<massage<<std::endl;
    }
    file.close();
}
void logs::dump(){
    std::ifstream file(filename);
    if(file.is_open()){
        std::string line;
        while(std::getline(file,line)){
            std::cout<<line<<std::endl;
        }
    }
    file.close();
}
void logs::clear(){
                std::ofstream file(filename,std::ios::trunc);
            file.close();
}
