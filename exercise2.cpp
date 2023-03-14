/**
 * @file exercise2.cpp
 * @author Patrik Dominik Pördi (ppordi@umd.edu)
 * @brief 
 * I created a vector called Numbers initialized with all of the places.
 * I substract the correct(still available, distinct and in range 1-9) user inputs from it.
 * I observe it to determine whether there are still available places.
 * When numbers get substract from it, the letters r,g,b will be put to their right place.
 * 
 * 
 * @version 0.1
 * @date 2022-09-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <iterator>
#include <sstream>
#include <algorithm>

/**
 * @brief Conversion from 1-9 to 2D array
 * 
 * @param Input 
 * @param Places 
 * @param Colors 
 */
/**
 * @brief Conversion from 1-9 to 2D array
 * 
 * @param Input 
 * @param Places 
 * @param Colors 
 */
void refresh(std::vector<int> Input, std::array<std::array<std::string, 3>, 3> &Places,std::array <std::string, 2> Colors);

/**
 * @brief Show the current setup on the table
 * 
 * @param Places 
 */
void showplaces(std::array<std::array<std::string, 3>, 3> &Places);

/**
 * @brief The game
 * 
 * @param Input 
 * @param Places 
 * @param Numbers 
 * @param Color 
 */
void play( std::array<std::array<std::string, 3>, 3> &Places
    ,std::vector<int> &Numbers,std::string Color );

void refresh(std::vector<int> Input, std::array<std::array<std::string, 3>, 3> &Places,std::array <std::string, 2> Colors) {
    for(int i :Input)
    switch (i) {
    case 1:
        Places.at(0).at(0) = Colors.at(1);
        break;
    case 2:
        Places.at(0).at(1) = Colors.at(1);
        break;
    case 3:
        Places.at(0).at(2) = Colors.at(1);
        break;
    case 4:
        Places.at(1).at(0) = Colors.at(1);
        break;
    case 5:
        Places.at(1).at(1) = Colors.at(1);
        break;
    case 6:
        Places.at(1).at(2) = Colors.at(1);
        break;
    case 7:
        Places.at(2).at(0) = Colors.at(1);
        break;
    case 8:
        Places.at(2).at(1) = Colors.at(1);
        break;
    case 9:
        Places.at(2).at(2) = Colors.at(1);
        break;
    }
    
}

/**
 * @brief Show the current setup on the table
 * 
 * @param Places 
 */
void showplaces(std::array<std::array<std::string, 3>, 3> &Places){
    std::cout<<"-------------"<<'\n';
    for (auto &row : Places)
    {
        for (auto &column : row)
        {
            std::cout << column << " ";
        }
        std::cout << '\n';
    }
}

/**
 * @brief The game
 * 
 * @param Input 
 * @param Places 
 * @param Numbers 
 * @param Color 
 */
void play( std::array<std::array<std::string, 3>, 3> &Places
    ,std::vector<int> &Numbers,std::string Color ){

    //Set the color
    std::array <std::string, 2> colors;
    if(Color=="r"){
        colors.at(0)="red";
        colors.at(1)="r";
    }
    else if(Color=="g"){
        colors.at(0)="green";
        colors.at(1)="g";
    }
    else{
        colors.at(0)="blue";
        colors.at(1)="b";

    }
    std::vector<int> Input {}; //Variable to store the user input
    //Show the current setup
    showplaces(Places);

    bool StopCycle{false}; //Variable to stop the cycle

    //Ask for user input until it will be y or n
    std::string answer;
    do{    
        std::cout<< "Do you want to place " << colors.at(0)<<" pegs (y,n)?";
        std::getline(std::cin >> std::ws, answer);      
    }
    while(!(answer == "y" || answer == "n" ));
   
    //The user wants to put the given color
    while ( answer=="y"&& StopCycle==false) 
    {
        
        //Asking about the place, the place selection is dinamic based on the current setup
        std::cout<< "Where do you want to place "<< colors.at(0)<<" pegs";
        if(Numbers.size()==9){
            std::cout<<"(1-9)?";
        }
        else{
            std::cout<<"("; 
            for (auto i : Numbers){
                std::cout << ' '<< i ;
            }
            std::cout<<")?";    
        }

        
        std::string line; //To store the user input
        //Reading the user input
        std::getline(std::cin >> std::ws, line);

        int number; //For parsing

        //Checking whether it contains anything else besides digits and " "
        std::size_t found = line.find_first_not_of("0123456789 ");

        //If just numbers and " " are on the user input, Input variable will be filled up
        if (found==std::string::npos)
        {
            std::istringstream stream(line);
            while (stream >> number){
            Input.push_back(number);
            }
        }

        bool Distinct{false}; //Distinct values on user input
        bool FreePlace{true}; //Free place on the table for the current selection

        std::vector<int>::iterator it; //Iterator to check whether the values are distinct
        
        //If the values are distinct, Distinct variable will be set to True
        if(Input.size()!=0){
            it = std::unique(Input.begin(), Input.end());
            if(it == Input.end()){
                Distinct=true;
            }   
        }
        
        //Checking that the givin distinct values are still available or not
        if(Distinct){
            for (auto &i : Input)
            {
                it=std::find(Numbers.begin(), Numbers.end(),i);                
                if (it == Numbers.end())
                {
                    FreePlace=false; //if any of the Input is already in use FreePlace will be set to false
                }
            }

            //If the selection is available the pegs will be put to their place
            if(FreePlace)
            {
                //Deleting the freshly put pegs from the Numbers(Available Slots)
                for (auto &i : Input)
                {
                    it=std::find(Numbers.begin(), Numbers.end(),i);
                    Numbers.erase(it);
                }
                
                //Printing the current setup
                refresh(Input,Places,colors);
                //Setting the StopGame variable to true to end the cycle
                StopCycle=true;
                
            }
        }
        //Making the user Input variable free for the next cycle  
        Input.clear();
    }
}

/**
 * @brief This is a main funtion
 * 
 * @return int Returned type of the main
 */
int main(){
    
    std::string Answer{}; // The users decision about running the game again
    while(Answer!="n")
    {
        std::cout<<"-------------"<<'\n'<<"EXERCISE2 2"<<'\n';
        //Initializing the starting slot selection
        std::array<std::array<std::string, 3>, 3> Places{{
            {"1","2","3"},
            {"4","5","6"},
            {"7","8","9"}
        }};

        //Variable to store the currently available slots
        std::vector<int> Numbers {1,2,3,4,5,6,7,8,9}; 
        
        std::array<std::string, 3> color {"r" ,"g" ,"b"}; //Variable to store the color

        //Calling the play funtion with each color
        for (auto &i : color)
        {
            play( Places,Numbers,i);

            //If the slots are full, meaning Numbers are empty we break out of the loop
            if(Numbers.empty()){
                break;
            }
        }
        
        //Printing the current setup
        showplaces(Places);

    //User input about playing again with checking the answer type
    do{
            std::cout<<"-------------"<<'\n';
            std::cout<< "Try again (y, n)? ";
            
            std::getline(std::cin >> std::ws, Answer);      
        }
        while(!(Answer == "y" || Answer == "n" ));
    } 
}