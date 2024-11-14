#include "classes/server/Server.hpp"

int main(){
    Std_Return status_value = Std_Return::STD_R_NOK;
    Server D1;

    status_value = D1.server_Init(8888);
    if(status_value == Std_Return::STD_R_OK)
    {
        status_value = D1.server_Accept();
        if(status_value == Std_Return::STD_R_OK)
        {
            D1.server_Recv_Command();
        }
    }

    return 0;
}