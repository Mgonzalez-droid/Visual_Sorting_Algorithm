#include<vector>
//Sort values in Descending order
struct Quick_Sort_Descending{
    Quick_Sort_Descending(std::vector<int>& data, int low, int high){
        //this -> low_i = low;
        //this -> high_i = high;
        sort_i(data, low, high);
    }

    Quick_Sort_Descending(std::vector<std::string>& data, int low, int high){
        //this ->low_s = low;
        //this ->high_s = high;
        sort_s(data, low, high);
    }

    void sort_s(std::vector<std::string>& data, int low, int high){

    }

    void sort_i(std::vector<int>& data, int low, int high){
        
    }
};