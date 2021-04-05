#include<vector>
//Sort values in Descending order
struct Quick_Sort_Descending{
    Quick_Sort_Descending(std::vector<int>& data, int low, int high){
        sort_i(data, low, high);
    }

    Quick_Sort_Descending(std::vector<std::string>& data, int low, int high){
        sort_s(data, low, high);
    }

    void sort_s(std::vector<std::string>& data, int low, int high){

    }

    void sort_i(std::vector<int>& data, int low, int high){
        
    }
};