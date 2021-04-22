//FINAL_PROJECT_MAIN
#include "Data_Management.cpp"
#include "Command_Line_UI.cpp"
#include "Runtime_Sort_Configuration.cpp"

int main(){

    bool continue_sorting = true;
    char quit = 'c';

    std::pair<int,char> sortingPreferences;

    while(continue_sorting){
        sortingPreferences = mainScreen();
        if( sortingPreferences.first == -1){
            continue_sorting = false;
        } else{
            clearScreen();
            sortingSplashScreen();

            if(sortingPreferences.second == 'b' || sortingPreferences.second == 'B'){
                sort_data(sortingPreferences.first, DESCENDING);
            }else{
                if(sortingPreferences.second == 'a' || sortingPreferences.second == 'A')
                    sort_data(sortingPreferences.first, ASCENDING);
            }

            quit = closingScreen();
            clearScreen();
            if(quit == 'n' || quit == 'N'){
                continue_sorting = false;
            }

        }
    }
}