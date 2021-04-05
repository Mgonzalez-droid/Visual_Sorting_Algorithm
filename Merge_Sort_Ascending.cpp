#include<vector>
//Sort values in Ascending order
struct Merge_Sort_Ascending{
    Merge_Sort_Ascending(std::vector<int>& data, int low, int high){
        sort_i(data, low, high);
    }

    Merge_Sort_Ascending(std::vector<std::string>& data, int low, int high){
        sort_s(data, low, high);
    }

    void sort_s(std::vector<std::string>& data, int low, int high){

    }

    void sort_i(std::vector<int>& data, int low, int high){
        
    }
};