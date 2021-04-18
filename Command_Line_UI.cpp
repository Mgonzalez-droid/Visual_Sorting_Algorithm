
std::pair<int,char> mainScreen();
//TODO: Implement or delete this
void clearScreen();
void sortingSplashScreen();
char closingScreen();

std::pair<int,char> mainScreen(){
    std::pair<int,char> choices;
    int dataSelection = 0; // User_id, ..., 5 total
    char sortingFormat = 'c'; //ascending(A) or descending(B)
    bool invalid = false;

    std::cout<<"WELCOME, PLEASE SELECT DATA TO BE SORTED"<<std::endl;
    std::cout<<"----------------------------------------"<<std::endl;
    std::cout<<std::endl<<"1) User ID\n2) Item ID\n3) Movie Title\n4) Rating\n5) Time Stamp\nTo quit \"-1\""<<std::endl;
    std::cout<<std::endl<<"Choice (Type an integer 1-5, or -1): ";
    std::cin>> dataSelection;

    if(dataSelection < -1 || dataSelection > 5 || dataSelection == 0){
        invalid = true;
        while(invalid){
            std::cout<<"ERROR TRY AGAIN: Choice (Type an integer 1-5, or -1): ";
            std::cin>> dataSelection;
            if(dataSelection == -1 || (dataSelection > 0 && dataSelection <= 5)){
                invalid = false;
            }
        }
    }

    if(dataSelection != -1){
        std::cout<<"DATA SELECTED, PLEASE SELECT SORTING FORMAT"<<std::endl;
        std::cout<<"-------------------------------------------"<<std::endl;
        std::cout<<"A) Ascending (Max)\nB) Descending (Min)"<<std::endl;
        std::cout<<std::endl<<"Choice (Type a char: A a B b): ";
        std::cin>>sortingFormat;

        if(sortingFormat == 'A' || sortingFormat == 'a' || sortingFormat == 'B' || sortingFormat == 'b'){
            invalid = false;
        }else{
            invalid = true;
            while(invalid){
                std::cout<<"ERROR TRY AGAIN: Choice (Type a char: A a B b): ";
                std::cin>>sortingFormat;
                if(sortingFormat == 'A' || sortingFormat == 'a' || sortingFormat == 'B' || sortingFormat == 'b'){
                    invalid = false;
                }
            }
        }
    }

    choices.first = dataSelection;
    choices.second = sortingFormat;

    return choices;
}
//TODO:implement or delete this
void clearScreen(){
    system("clear");
}

void sortingSplashScreen(){
    std::cout<<"Please wait currently sorting";
}

char closingScreen(){
    char choice = 'c';
    bool invalid = false;
    std::cout<<"Would you like to sort again? (y or Y for Yes, n or N for No): ";
    std::cin>>choice;

    if(choice == 'Y' || choice == 'y' || choice == 'N' || choice == 'n'){
        invalid = false;
    } else{
        invalid = true;
        while(invalid){
            std::cout<<"ERROR TRY AGAIN: Would you like to sort again? (y or Y for Yes, n or N for No): ";
            std::cin>>choice;
            if(choice == 'Y' || choice == 'y' || choice == 'N' || choice == 'n'){
                invalid = false;
            }
        }
    }
    return choice;
}