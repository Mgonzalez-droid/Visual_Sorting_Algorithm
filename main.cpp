//FINAL_PROJECT_MAIN
#include<iostream>
#include"Data_Management.cpp"
#include"Review.cpp"
#include"Merge_Sort_Descending.cpp"//min
#include"Merge_Sort_Ascending.cpp"//max
#include"Quick_Sort_Descending.cpp"//min
#include"Quick_Sort_Ascending.cpp"//max
#include<map>
#include<vector>
#include<cstdio>
//create a map of key string, val vector<int or string> therefore template needed

const int QUIT = -1;
const int USER_ID = 1;
const int ITEM_ID = 2;
const int RATING = 3;
const int TIME_STAMP = 4;
const int MOVIE_TITLE = 5;
//const int QUICK_SORT = 6;
//const int MERGE_SORT = 7;
//const int BUCKET_SORT = 8;
const int DESCENDING = 9;
const int ASCENDING = 10;

template<class t>
void print_results(std::vector<t> my_data){
    for(int i = 0; i < my_data.size(); i++)
        std::cout<<my_data[i]<<std::endl;
}

void mergeSort(std::vector<int> my_data, int sort_property){
    //start time

    int start = 0;
    int end = my_data.size() - 1;
    if(sort_property == ASCENDING){
        Merge_Sort_Ascending merge(my_data, start, end);
        print_results(my_data);
    }else if(sort_property == DESCENDING){
        Merge_Sort_Descending merge(my_data, start, end);
        print_results(my_data);
    }

    //end time
    //print results to text file
    //return time difference
}

void mergeSort(std::vector<std::string> my_data, int sort_property){
    //start time

    int start = 0;
    int end = my_data.size() - 1;
    if(sort_property == ASCENDING){
        Merge_Sort_Ascending merge(my_data, start, end);
        print_results(my_data);
    }else if(sort_property == DESCENDING){
        Merge_Sort_Descending merge(my_data, start, end);
        print_results(my_data);
    }

    //end time
    //print to text file
    //return time difference
}

void quickSort(std::vector<int> my_data, int sort_property){
    //start time

    int low = 0;
    int high = my_data.size() / sizeof(my_data[0]);
    if(sort_property == ASCENDING){
        Quick_Sort_Ascending quick(my_data,low, high);
        print_results(my_data);
    }else if(sort_property == DESCENDING){
        Quick_Sort_Descending quick(my_data,low, high);
        print_results(my_data);
    }

    //end time
    //print results to text file
    //return time difference
}

void quickSort(std::vector<std::string> my_data, int sort_property){
    //start time

    int low = 0;
    int high = my_data.size() / sizeof(my_data[0]);
    if(sort_property == ASCENDING){
        Quick_Sort_Ascending quick(my_data,low, high);
        print_results(my_data);
    }else if(sort_property == DESCENDING){
        Quick_Sort_Descending quick(my_data,low, high);
        print_results(my_data);
    }

    //end time
    //print results to text file
    //return time difference
}

void bucketSort(std::vector<int> my_data, int sort_property){
    //start time

    //end time
    //print results to text file
    //return time difference
}

void bucketSort(std::vector<std::string> my_data, int sort_property){
    //start time

    //end time
    //print results to text file
    //return time difference
}

//user_id (integer), item_id(integer), rating(integer), time_stamp(integer), movie_title(string).
void sort_data(int choice, int sort_property){
    Data_Management data;
    switch(choice){
        case USER_ID :{
            std::vector<int> my_data = data.getUserIdVec();
            mergeSort(my_data,sort_property);
            quickSort(my_data,sort_property);
            bucketSort(my_data,sort_property);
        };
        break;

        case ITEM_ID :{
            std::vector<int> my_data = data.getItemIdVec();
            mergeSort(my_data,sort_property);
            quickSort(my_data,sort_property);
            bucketSort(my_data,sort_property);
        };
        break;

        case RATING :{
            std::vector<int> my_data = data.getRatingVec();
            mergeSort(my_data,sort_property);
            quickSort(my_data,sort_property);
            bucketSort(my_data,sort_property);
        };
        break;

        case TIME_STAMP :{
            std::vector<int> my_data = data.getTimeStampVec();
            mergeSort(my_data,sort_property);
            quickSort(my_data,sort_property);
            bucketSort(my_data,sort_property);
        };
        break;

        case MOVIE_TITLE :{
            std::vector<std::string> my_data = data.getMovieTitleVec();
            mergeSort(my_data,sort_property);
            quickSort(my_data,sort_property);
            bucketSort(my_data,sort_property);
        };
        break;
    }
}


std::pair<int,char> mainScreen(){
    std::pair<int,char> choices;
    int dataSelection = 0; // User_id, ..., 5 total
    //int sortingMethod = 0; //quick sort, merge sort, bucket sort
    char sortingFormat = 'c'; //ascending(A) or descending(B)
    bool invalid = false;
    bool notInt = false;
    bool notChar = false;

    std::cout<<"WELCOME, PLEASE SELECT DATA TO BE SORTED"<<std::endl;
    std::cout<<"----------------------------------------"<<std::endl;
    std::cout<<std::endl<<"1) User ID\n2) Item ID\n3) Movie Title\n4) Rating\n5)Time Stamp\nTo quit \"-1\""<<std::endl;
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

void clearScreen(){
    system("clear");
}

void sortingSplashScreen(){
    std::cout<<"Please wait currently sorting";
}

void closingScreen(){
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
}


int main(){

    bool continue_sorting = true;

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
        closingScreen();
    }
}
