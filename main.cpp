//FINAL_PROJECT_MAIN
#include"Data_Management.cpp"
#include "Command_Line_UI.cpp"
#include "Runtime_Sort_Configuration.cpp"

/*
 * TODO:Fix and Test
 *      - Merge sort Ascending (FIX and TEST)
 *      - Merge sort Descending (FIX and TEST)
 *      - Quick Sort Ascending (TEST)
 *      - Quick Sort Descending (TEST)
 *      - Bucket Sort Ascending (TEST)
 *      - Bucket Sort Descending (TEST)
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

            sort_data(sortingPreferences.first, ASCENDING);
            sort_data(sortingPreferences.first, DESCENDING);

        }
        quit = closingScreen();
        if(quit == 'n' || quit == 'N'){
            continue_sorting = false;

        }
    }
}