//FINAL_PROJECT_MAIN
#include"Data_Management.cpp"
#include "Command_Line_UI.cpp"
#include "Runtime_Sort_Configuration.cpp"

/*
 * TODO:Fix and Test
 *      - Merge sort Ascending (FIX and TEST)
 *      - Merge sort Descending (FIX and TEST)
 *      - Fix string processing for all algorithms
 *      - Fix Descending bucket
 *      - Fix UI
 *          - clear screen (optional)
 *          - spacing
 *      - eliminate extraneous comments
 *      - timing on some function, could be due to i.e. Merge sort not working
 *
 */

int main(){

    bool continue_sorting = true;
    char quit = 'c';

    std::pair<int,char> sortingPreferences;

    while(continue_sorting){
        sortingPreferences = mainScreen();
        //clearScreen(); need to troubleshoot
        if( sortingPreferences.first == -1){
            continue_sorting = false;
        } else{

            sortingSplashScreen();

            if(sortingPreferences.second == 'b' || sortingPreferences.second == 'B'){
                sort_data(sortingPreferences.first, DESCENDING);
            }else{
                if(sortingPreferences.second == 'a' || sortingPreferences.second == 'A')
                    sort_data(sortingPreferences.first, ASCENDING);
            }

        }
        quit = closingScreen();
        if(quit == 'n' || quit == 'N'){
            continue_sorting = false;

        }
    }
}