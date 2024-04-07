#!/bin/bash

#fun display welcome to help development

display(){
    echo "welcome to the development help select witch language you want"
    echo "1. c++ hello world example"
    echo "2. python hello world example"
    echo "3. linux hello world example"
    echo "4. bash hello world example"
    echo "5. exit"

}

#fun to display c++ hello example

hello_c++(){
    echo "fun to display c++ hello example"
    echo "#include<iostream>"
    echo "int main() {"
    echo "std::cout<<"hello world"<<std::endl;"
    echo "return 0;"
    echo "}"
}

# Function to display the Python Hello example
python_hello_world() {
    echo "fun to display python hello example"
    echo "print('Hello world!')"
}

# Function to display the bash Hello example

bash_hello(){
    echo "fun to display the bash Hello example"
    echo "echo "hello world""
}

# Function to display the Linux Commands example
linux_commands_() {
    echo "fun to display the linux Hello example"
    echo "ls - list directory contents"
    echo "pwd - print name of current/working directory"
    echo "mkdir - make directories"
    echo "cd - change directory"
}

#main

while true; do
    #display_menu
    read -rp "enter your choice: " choice

    case $choice in 
        1) hello_c++ ;;
        2) python_hello_world ;;
        3) linux_commands_ ;;
        4) bash_hello ;;
        5) echo "exit.. "; exit ;;
        *) echo "invalidate choice. please try again. ";;
    esac

done
