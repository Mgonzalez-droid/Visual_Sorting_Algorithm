#include<vector>
#include<iostream>
struct Quick_Sort_Ascending{

    int* arr;
    std::string* arrs;
    std::vector<std::string> vec_s;

    std::vector<int> ret_data_i(){
        std::vector<int> vec(arr + 0, arr + 100000);
        return vec;
    }

    std::vector<std::string> ret_data_s(){
        return vec_s;
    }

    Quick_Sort_Ascending(std::vector<int> data, int low, int high){
        this -> arr = &data[0];
        sort_i(arr, low, high);
    }

    Quick_Sort_Ascending(std::vector<std::string> data, int low, int high){
        this -> arrs = &data[0];
        sort_s(arrs, low, high);
        std::vector<std::string> vec(arrs + 0, arrs + 1682);
        this -> vec_s = vec;
    }

    //FROM NOTES

    //____________INTEGERS_____________
    void sort_i(int data[], int low, int high) {
        if (low < high){
            int pivot = partition(data, low, high);
            sort_i(data, low, pivot - 1);
            sort_i(data, pivot + 1, high);
        }
    }

    void swap(int *a, int *b) {
        int t = *a;
        *a = *b;
        *b = t;
    }

    int partition(int data[], int low, int high){
        // Select the pivot element
        int pivot = data[low];
        int up=low, down=high;
        while(up<down){
            for (int j = up; j < high; j++){
                if(data[up]>pivot)
                    break;
            up++;
            }
            for (int j = high; j > low; j--){
                if(data[down]<pivot)
                    break;
                down--;
            }
            if(up<down)
                swap(&data[up], &data[down]);
        }
        swap(&data[low], &data[down]);
        return down;
    }

    //___________STRINGS__________

    bool compareString(std::string one, std::string two, char operation){

        //correct issue comparing upper an lower case characters
        if(islower(one[0]) && isalpha(one[0]))
            one[0] = toupper(one[0]);

        if(islower(two[0]) && isalpha(two[0]))
            two[0] = toupper(two[0]);


        int res;
        bool isTrue = false;

        if(operation == '>'){
            res = one.compare(two);

            if(res != 0){
                if(res > 0){
                    //one is greater than two
                    isTrue = true;
                }else{
                    //one is less than two
                    isTrue = false;
                }
            }else{
                //one is equal too two
                //isTrue = true;
                isTrue = false;
            }
        }

        if(operation == '<'){
            res = two.compare(one);

            if(res != 0){
                if(res > 0){
                    //two is greater than one
                    isTrue = true;
                }else{
                    //two is less than one
                    isTrue = false;
                }
            }else{
                //two is equal too one
                //isTrue = true;
                isTrue = false;
            }
        }

        return isTrue;
    }

    void sort_s(std::string data[], int low, int high) {
        if (low < high){
            int pivot = partition(data, low, high);
            sort_s(data, low, pivot - 1);
            sort_s(data, pivot + 1, high);
        }
    }

    void swap(std::string *a, std::string *b) {
        std::string t = *a;
        *a = *b;
        *b = t;
    }

    int partition(std::string data[], int low, int high){
        // Select the pivot element
        std::string pivot = data[low];
        int up=low, down=high;
        while(up<down){
            for (int j = up; j < high; j++){
                //if(data[up]>pivot)//Original line...
                if(compareString(data[up], pivot, '>'))
                    break;
            up++;
            }
            for (int j = high; j > low; j--){
                //if(data[down]<pivot)Original line...
                if(compareString(data[down], pivot, '<'))
                    break;
                down--;
            }
            if(up<down)//index comparison integers
                swap(&data[up], &data[down]);//taken care of
        }
        swap(&data[low], &data[down]);//taken care of
        return down;
    }
};
