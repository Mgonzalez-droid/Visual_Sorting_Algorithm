//FINAL_PROJECT_MAIN
#include<iostream>
#include"Data_Management.cpp"
#include"Review.cpp"
#include"Merge_Sort.cpp"
#include"Quick_Sort.cpp"
#include<map>
#include<vector>
//create a map of key string, val vector<int or string> therefore template needed

const int USER_ID = 1;
const int ITEM_ID = 2;
const int RATING = 3;
const int TIME_STAMP = 4;
const int MOVIE_TITLE = 5;
const int QUICK_SORT = 6;
const int MERGE_SORT = 7;
const int MIN = 8;
const int MAX = 9;

template<class t>
 void printMydata(t* reviews){
     std::cout<<*reviews<<std::endl;
 }

//user_id (integer), item_id(integer), rating(integer), time_stamp(integer), movie_title(string).
void sort_data(int& choice, int& sort_method, int sort_property){
    Data_Management data;
    switch(choice){
        case USER_ID :{
            std::vector<int> my_data = data.getUserIdVec();
            if()
        };
        break;

        case ITEM_ID :{
            std::vector<int> my_data = data.getItemIdVec();
        };
        break;

        case RATING :{
            std::vector<int> my_data = data.getRatingVec();
        };
        break;

        case TIME_STAMP :{
            std::vector<int> my_data = data.getTimeStampVec();
        };
        break;

        case MOVIE_TITLE :{
            std::vector<int> my_data = data.getMovieTitleVec();
        };
        break;
    }
}

int main(){
    //TODO: To be done with UI
    /*
    bool user_id = true;
    bool item_id = true;
    bool rating = true;
    bool time_stamp = true;
    bool title = true;
    */
   int choice = 0//whatever is taken in by the UI
   int sort_method = QUICK_SORT;
   int sort_property = MIN;

   sort_data(choice, true);

    //TODO: define variables for UI
    //quick sort min
    sort_data(choice, QUICK_SORT, MIN);

    //quick sort max
    sort_data(choice, QUICK_SORT, MAX);

    //merge sort min
    sort_data(choice, MERGE_SORT, MIN);

    //merge sort max
    sort_data(choice, MERGE_SORT, MAX);
    
}
