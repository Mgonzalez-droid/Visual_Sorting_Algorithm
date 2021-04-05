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
//create a map of key string, val vector<int or string> therefore template needed

const int USER_ID = 1;
const int ITEM_ID = 2;
const int RATING = 3;
const int TIME_STAMP = 4;
const int MOVIE_TITLE = 5;
const int QUICK_SORT = 6;
const int MERGE_SORT = 7;
const int DESCENDING = 8;
const int ASCENDING = 9;

template<class t>
void print_results(std::vector<t> my_data){
    for(int i = 0; i < my_data.size(); i++)
        std::cout<<my_data[i]<<std::endl;
}

//user_id (integer), item_id(integer), rating(integer), time_stamp(integer), movie_title(string).
void sort_data(int choice, int sort_method, int sort_property){
    Data_Management data;
    switch(choice){
        case USER_ID :{
            std::vector<int> my_data = data.getUserIdVec();
            if(sort_method == MERGE_SORT){
                int start = 0;
                int end = my_data.size() - 1;
                if(sort_property == ASCENDING){
                    Merge_Sort_Ascending merge(my_data, start, end);
                    print_results(my_data);
                }else if(sort_property == DESCENDING){
                    Merge_Sort_Descending merge(my_data, start, end);
                    print_results(my_data);
                }
            } else if(sort_method == QUICK_SORT){
                int low = 0;
                int high = my_data.size() / sizeof(my_data[0]);
                if(sort_property == ASCENDING){
                    Quick_Sort_Ascending quick(my_data,low, high);
                    print_results(my_data);
                }else if(sort_property == DESCENDING){
                    Quick_Sort_Descending quick(my_data,low, high);
                    print_results(my_data);
                }
            }
        };
        break;

        case ITEM_ID :{
            std::vector<int> my_data = data.getItemIdVec();
            if(sort_method == MERGE_SORT){
                int start = 0;
                int end = my_data.size() - 1;
                if(sort_property == ASCENDING){
                    Merge_Sort_Ascending merge(my_data, start, end);
                    print_results(my_data);
                }else if(sort_property == DESCENDING){
                    Merge_Sort_Descending merge(my_data, start, end);
                    print_results(my_data);
                }
            } else if(sort_method == QUICK_SORT){
                int low = 0;
                int high = my_data.size() / sizeof(my_data[0]);
                if(sort_property == ASCENDING){
                    Quick_Sort_Ascending quick(my_data,low, high);
                    print_results(my_data);
                }else if(sort_property == DESCENDING){
                    Quick_Sort_Descending quick(my_data,low, high);
                    print_results(my_data);
                }
            }
        };
        break;

        case RATING :{
            std::vector<int> my_data = data.getRatingVec();
            if(sort_method == MERGE_SORT){
                int start = 0;
                int end = my_data.size() - 1;
                if(sort_property == ASCENDING){
                    Merge_Sort_Ascending merge(my_data, start, end);
                    print_results(my_data);
                }else if(sort_property == DESCENDING){
                    Merge_Sort_Descending merge(my_data, start, end);
                    print_results(my_data);
                }
            } else if(sort_method == QUICK_SORT){
                int low = 0;
                int high = my_data.size() / sizeof(my_data[0]);
                if(sort_property == ASCENDING){
                    Quick_Sort_Ascending quick(my_data,low, high);
                    print_results(my_data);
                }else if(sort_property == DESCENDING){
                    Quick_Sort_Descending quick(my_data,low, high);
                    print_results(my_data);
                }
            }
        };
        break;

        case TIME_STAMP :{
            std::vector<int> my_data = data.getTimeStampVec();
             if(sort_method == MERGE_SORT){
                int start = 0;
                int end = my_data.size() - 1;
                if(sort_property == ASCENDING){
                    Merge_Sort_Ascending merge(my_data, start, end);
                    print_results(my_data);
                }else if(sort_property == DESCENDING){
                    Merge_Sort_Descending merge(my_data, start, end);
                    print_results(my_data);
                }
            } else if(sort_method == QUICK_SORT){
                int low = 0;
                int high = my_data.size() / sizeof(my_data[0]);
                if(sort_property == ASCENDING){
                    Quick_Sort_Ascending quick(my_data,low, high);
                    print_results(my_data);
                }else if(sort_property == DESCENDING){
                    Quick_Sort_Descending quick(my_data,low, high);
                    print_results(my_data);
                }
            }
        };
        break;

        case MOVIE_TITLE :{
            std::vector<std::string> my_data = data.getMovieTitleVec();
            if(sort_method == MERGE_SORT){
                int start = 0;
                int end = my_data.size() - 1;
                if(sort_property == ASCENDING){
                    Merge_Sort_Ascending merge(my_data, start, end);
                    print_results(my_data);
                }else if(sort_property == DESCENDING){
                    Merge_Sort_Descending merge(my_data, start, end);
                    print_results(my_data);
                }
            } else if(sort_method == QUICK_SORT){
                int low = 0;
                int high = my_data.size() / sizeof(my_data[0]);
                if(sort_property == ASCENDING){
                    Quick_Sort_Ascending quick(my_data,low, high);
                    print_results(my_data);
                }else if(sort_property == DESCENDING){
                    Quick_Sort_Descending quick(my_data,low, high);
                    print_results(my_data);
                }
            }
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
   int choice = 0;//whatever is taken in by the UI
   int sort_method = QUICK_SORT;
   int sort_property = DESCENDING;

   //sort_data(choice, true);

    //TODO: define variables for UI
    //quick sort min
    sort_data(choice, QUICK_SORT, DESCENDING);

    //quick sort max
    sort_data(choice, QUICK_SORT, ASCENDING);

    //merge sort min
    sort_data(choice, MERGE_SORT, DESCENDING);

    //merge sort max
    sort_data(choice, MERGE_SORT, ASCENDING);
    
}
