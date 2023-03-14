/**
 * @file exercise1.cpp
 * @author Patrik Dominik Pördi (ppordi@umd.edu)
 * @brief 
 * I ask for parts and grippers first, if they match then question regarding to the table appears,
 * if it also match( Three occasions ) Succes! Other cases Failure.
 * @version 0.1
 * @date 2022-09-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string>
/**
 * @brief This is a main funtion
 * 
 * @return int Returned type of the main
 */
int main(){

    std::string Answer{}; // The users decision about running the game again

    // Outer do while loop to ask for part and gripper
    do
    {
        std::cout<<"-------------"<<'\n'<<"EXERCISE 1"<<'\n'<<"-------------"<<'\n';
        //Asking for the part until it will be entered correctly
        std::string QuestionPart{};
        do{
            std::cout<< "Which part to pick up (c, b, p)? ";
            std::getline(std::cin >> std::ws, QuestionPart);        
        }
        while(!(QuestionPart == "c" || QuestionPart== "b" || QuestionPart== "p"));

        std::cout<<"-------------"<<'\n';

        // Set part variable based on the user input
        std::string Part{};

        if (QuestionPart=="c")
        {
            Part="Cube";
        }
        else if (QuestionPart=="b")
        {
            Part="Ball";
        }
        else
        {
            Part="Peg";
        }
        
        //Asking for the gripper until it will be entered correctly
        std::string QuestionGripper{};
        do{
            std::cout<< "Which gripper to use (s, f)? ";
            std::getline(std::cin >> std::ws, QuestionGripper);      
        }
        while(!(QuestionGripper == "s" || QuestionGripper == "f" ));

        std::cout<<"-------------"<<'\n';

        // Set gripper variable based on the user input
        std::string Gripper{};
        (QuestionGripper=="s") ? Gripper="Suction gripper" : Gripper="Finger gripper";

        // Checking the part and gripper combinations
        if ((QuestionPart=="b" && QuestionGripper=="s")
        || ((QuestionPart=="c" || QuestionPart=="p") && QuestionGripper=="f"))
        // If the part and gripper match user will be asked about the table
        {
            // Do while loop to get the user input about the table until it will be entered correctly
            std::string QuestionTable{};
            do
            {
                std::cout<< "Which table to put on (r, g, b)? ";
                std::getline(std::cin >> std::ws, QuestionTable);      
            }
            while(!(QuestionTable== "r" || QuestionTable == "g" || QuestionTable== "b")); 

            std::cout<<"-------------"<<'\n';

            // Set table variable based on the user input
            std::string Table{};
            if (QuestionTable=="r")
            {
                Table="red table.";
            }
            else if (QuestionTable=="g")
            {
                Table="green table.";
            }
            else
            {
                Table="blue table.";
            }

            /* To find the right Combinations: 
            Ball & Sunction & Green, 
            Cube & Finger & Red, 
            Peg & Finger & Blue 
            */
            if (
            (QuestionPart=="b" && QuestionGripper=="s" && QuestionTable=="g") ||
            (QuestionPart=="c" && QuestionGripper=="f" && QuestionTable=="r") ||
            (QuestionPart=="p" && QuestionGripper=="f" && QuestionTable=="b")
            )
            {
                std::cout << "Success: The "<< Part <<" was placed on the " << Table << '\n';
            }
            else 
            // If the combination is not right the failure message will be placed
            {
                std::cout << "Failure: Cannot place the "<< Part << " on the " << Table << '\n';
            }

            std::cout<<"-------------"<<'\n';
        }
        else 
        // If the part and gripper do not match failure message will be placed
        {
            std::cout<<"Failure: Cannot pick up the "<< Part<< " with the "<< Gripper<< '\n';
        }

        std::cout<<"-------------"<<'\n';

        // User input about running again until it will be entered correctly
        do{
            
            std::cout<< "Try again (y, n)? ";
            std::getline(std::cin >> std::ws, Answer);      
        }
        while(!(Answer == "y" || Answer == "n" ));

    } 
    while (Answer!="n");
}