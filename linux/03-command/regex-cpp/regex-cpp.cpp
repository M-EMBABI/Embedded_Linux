#include <iostream>
#include <regex>
#include <string>

bool validateBranchName(const std::string& branchname){
        std::regex pattern(R"(^feature/TN-\d+/[a-zA-Z0-9_-]+$)");
        return std::regex_match(branchname,pattern);

}

int main(){
        std::string branch1 = "feature/TN-123/branchname";
        std::string branch2 = "feature/TN-456/another-branch";
        std::string branch3 = "feature/TN-789/invalid branch";

        std::cout << branch1 << ": " << (validateBranchName(branch1) ? "valid" : "invalid") << std::endl;
        std::cout << branch2 << ": " << (validateBranchName(branch2) ? "valid" : "invalid") << std::endl;
        std::cout << branch3 << ": " << (validateBranchName(branch3) ? "valid" : "invalid") << std::endl;

    return 0;
}


