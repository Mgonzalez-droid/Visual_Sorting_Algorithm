//FINAL_PROJECT_MAIN
#include<iostream>
#include"Data_Management.cpp"
#include"Review.cpp"
#include"Merge_Sort_Descending.cpp"//min
#include"Merge_Sort_Ascending.cpp"//max
#include"Quick_Sort_Descending.cpp"//min
#include"Quick_Sort_Ascending.cpp"//max
#include"Bucket_Sort_Ascending.cpp"
#include"Bucket_Sort_Descending.cpp"
#include<map>
#include<vector>
#include<cstdio>
#include<fstream>
#include<ctime>
//create a map of key string, val vector<int or string> therefore template needed

const int QUIT = -1;
const int USER_ID = 1;
const int ITEM_ID = 2;
const int RATING = 3;
const int TIME_STAMP = 4;
const int MOVIE_TITLE = 5;
const int QUICK_SORT = 6;
const int MERGE_SORT = 7;
const int BUCKET_SORT = 8;
const int DESCENDING = 9;
const int ASCENDING = 10;

//For Debugging purposes
template<class t>
void print_results(std::vector<t>);

//Sorting helper methods
//TODO:condense with templates, move into seperate class: Runtime_Sort_Configuration.cpp (all static)
void sort_data(int,int);
void mergeSort(std::vector<int>, int);
void mergeSort(std::vector<std::string>, int);
void quickSort(std::vector<int>, int);
void quickSort(std::vector<std::string>, int);
void bucketSort(std::vector<int>, int);
void bucketSort(std::vector<std::string>, int);

//Screens
//TODO: move into seperate class: Command_Line_UI.cpp (all static)
std::pair<int,char> mainScreen();
void clearScreen();
void sortingSplashScreen();
char closingScreen();

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

//For debugging
template<class t>
void print_results(std::vector<t> my_data){
    for(int i = 0; i < my_data.size(); i++)
        std::cout<<my_data[i]<<std::endl;
}

//For file creation and deletion

template<class t>
void createReport(std::vector<t> results,int sortingMethod, int sort_property){
    switch(sortingMethod){
        case QUICK_SORT:{

            if(sort_property == ASCENDING){
                char reportName[] = "Results/quick_sort_ascending_results.txt";

                //Deletes the file if already exists
                if (remove(reportName) != 0)
                    perror("File deletion failed");
                else{
                    //create file
                    std::ofstream MyFile(reportName);
                    //write data to file
                    for(int i = 0; i < results.size(); i++){
                        MyFile << results[i] << std::endl;
                    }
                }
            }

            if(sort_property == DESCENDING){
                char reportName[] = "Results/quick_sort_descending_results.txt";

                //Deletes the file if already exists
                if (remove(reportName) != 0)
                    perror("File deletion failed");
                else{
                    //create file
                    std::ofstream MyFile(reportName);
                    //write data to file
                    for(int i = 0; i < results.size(); i++){
                        MyFile << results[i] << std::endl;
                    }
                }
            }
        }break;

        case MERGE_SORT:{
            if(sort_property == ASCENDING){
                char reportName[] = "Results/merge_sort_ascending_results.txt";

                //Deletes the file if already exists
                if (remove(reportName) != 0)
                    perror("File deletion failed");
                else{
                    //create file
                    std::ofstream MyFile(reportName);
                    //write data to file
                    for(int i = 0; i < results.size(); i++){
                        MyFile << results[i] << std::endl;
                    }
                }
            }

            if(sort_property == DESCENDING){
                char reportName[] = "Results/merge_sort_descending_results.txt";

                //Deletes the file if already exists
                if (remove(reportName) != 0)
                    perror("File deletion failed");
                else{
                    //create file
                    std::ofstream MyFile(reportName);
                    //write data to file
                    for(int i = 0; i < results.size(); i++){
                        MyFile << results[i] << std::endl;
                    }
                }
            }
        }break;
        case BUCKET_SORT:{
            if(sort_property == ASCENDING){
                char reportName[] = "Results/bucket_sort_ascending_results.txt";

                //Deletes the file if already exists
                if (remove(reportName) != 0)
                    perror("File deletion failed");
                else{
                    //create file
                    std::ofstream MyFile(reportName);
                    //write data to file
                    for(int i = 0; i < results.size(); i++){
                        MyFile << results[i] << std::endl;
                    }
                }
            }

            if(sort_property == DESCENDING){
                char reportName[] = "Results/bucket_sort_descending_results.txt";

                //Deletes the file if already exists
                if (remove(reportName) != 0)
                    perror("File deletion failed");
                else{
                    //create file
                    std::ofstream MyFile(reportName);
                    //write data to file
                    for(int i = 0; i < results.size(); i++){
                        MyFile << results[i] << std::endl;
                    }
                }
            }
        }break;
    }
}

//Sorting and sorting helper methods

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

void mergeSort(std::vector<int> my_data, int sort_property){
    //start time
    time_t t_start = time(nullptr);

    int start = 0;
    int end = my_data.size() - 1;
    if(sort_property == ASCENDING){
        Merge_Sort_Ascending merge(my_data, start, end);
        //print_results(my_data);
    }else if(sort_property == DESCENDING){
        Merge_Sort_Descending merge(my_data, start, end);
        //print_results(my_data);
    }

    //end time
    time_t t_end = time(nullptr);
    //output time difference
    std::cout<<std::endl<<"Merge Sort took "<< t_end - t_start <<" second(s)."<<std::endl;
    //print results to text file
    createReport(my_data,MERGE_SORT,sort_property);
}

void mergeSort(std::vector<std::string> my_data, int sort_property){
    //start time
    time_t t_start = time(nullptr);

    int start = 0;
    int end = my_data.size() - 1;
    if(sort_property == ASCENDING){
        Merge_Sort_Ascending merge(my_data, start, end);
        //print_results(my_data);
    }else if(sort_property == DESCENDING){
        Merge_Sort_Descending merge(my_data, start, end);
        //print_results(my_data);
    }

    //end time
    time_t t_end = time(nullptr);
    //output time difference
    std::cout<<std::endl<<"Merge Sort took "<< t_end - t_start << " second(s)."<<std::endl;
    //print to text file
    createReport(my_data,MERGE_SORT,sort_property);
}

void quickSort(std::vector<int> my_data, int sort_property){
    //start time
    time_t t_start = time(nullptr);

    int low = 0;
    int high = my_data.size() / sizeof(my_data[0]);
    if(sort_property == ASCENDING){
        Quick_Sort_Ascending quick(my_data,low, high);
        //print_results(my_data);
    }else if(sort_property == DESCENDING){
        Quick_Sort_Descending quick(my_data,low, high);
        //print_results(my_data);
    }

    //end time
    time_t t_end = time(nullptr);
    //output time difference
    std::cout<<std::endl<< "Quick Sort took " << t_end - t_start << " second(s)." <<std::endl;
    //print results to text file
    createReport(my_data,QUICK_SORT,sort_property);
}

void quickSort(std::vector<std::string> my_data, int sort_property){
    //start time
    time_t t_start = time(nullptr);

    int low = 0;
    int high = my_data.size() / sizeof(my_data[0]);
    if(sort_property == ASCENDING){
        Quick_Sort_Ascending quick(my_data,low, high);
        //print_results(my_data);
    }else if(sort_property == DESCENDING){
        Quick_Sort_Descending quick(my_data,low, high);
        //print_results(my_data);
    }

    //end time
    time_t t_end = time(nullptr);
    //output time difference
    std::cout<<std::endl<<"Quick Sort took "<<t_end - t_start<<" second(s)."<<std::endl;
    //print results to text file
    createReport(my_data,QUICK_SORT,sort_property);
}

void bucketSort(std::vector<int> my_data, int sort_property){
    //start time
    time_t t_start = time(nullptr);

    if(sort_property == ASCENDING){
        Bucket_Sort_Ascending sort(my_data);
    }

    if(sort_property == DESCENDING){
        Bucket_Sort_Descending sort(my_data);
    }

    //end time
    time_t t_end = time(nullptr);
    //output time difference
    std::cout<<std::endl<<"Bucket Sort took "<< t_end - t_start <<" second(s)."<<std::endl;
    //print results to text file
    createReport(my_data,BUCKET_SORT,sort_property);
}

void bucketSort(std::vector<std::string> my_data, int sort_property){
    //start time
    time_t t_start = time(nullptr);

    if(sort_property == ASCENDING){
        Bucket_Sort_Ascending sort(my_data);
    }

    if(sort_property == DESCENDING){
        Bucket_Sort_Descending sort(my_data);
    }

    //end time
    time_t t_end = time(nullptr);
    //output time difference
    std::cout<<std::endl<<"Bucket Sort took "<< t_end - t_start <<" second(s)."<<std::endl;
    //print results to text file
    createReport(my_data,BUCKET_SORT,sort_property);
}

//UI screen refresh

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
