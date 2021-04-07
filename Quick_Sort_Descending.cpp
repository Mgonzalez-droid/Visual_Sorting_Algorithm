#include<vector>
#include<iostream>
//Sort values in Descending order
struct Quick_Sort_Descending{
    Quick_Sort_Descending(std::vector<int>& data, int low, int high){
        sort_i(data, low, high);
    }

    Quick_Sort_Descending(std::vector<std::string>& data, int low, int high){
        sort_s(data, low, high);
    }
    //FROM NOTES: CITE?

    //____________INTEGERS_____________
    void sort_i(std::vector<int>& data, int low, int high) {
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

    int partition(std::vector<int> data, int low, int high){
        // Select the pivot element
        int pivot = data[low];
        int up=low, down=high;
        while(up<down){
            for (int j = up; j < high; j++){
                if(data[up]<pivot)//what is changed
                    break;
            up++;
            }
            for (int j = high; j > low; j--){
                if(data[down]>pivot)//what is changed
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
    //Helper function to compare strings, compares first string length. If they are the same
    //length and word it returns false. If the strings differ in length it does a comparison
    //of length using the operation passed i.e "Rocky" < "Star Wars" is true (1)
    bool compareString(std::string one, std::string two, char operation){
        bool result = false;
        if(operation == '>'){
            //are they the same length?
            if(one.length() == two.length()){
                //are they the same title?
                if(one.compare(two) == 0){
                    result = false; // is "Star Wars" > "Star Wars"; false!
                }else{
                    bool resolution = false;
                    int index = 0;
                    std::string choice;
                    while(resolution != true){
                        if(one[index] != two[index]){
                            if(one[index] > two[index]){ //this part decides ascending descending
                                resolution = true;
                                choice = "one";
                            } else{
                                resolution = true;
                                choice = "two";
                            }
                        }
                        index += 1;
                    }
                        if(choice == "one"){
                            result = true;
                        }
                    }
            }else{
                result = one.length() > two.length();
            }
        }

        if(operation == '<'){
            //are they the same length?
            if(one.length() == two.length()){
                //are they the same title?
                if(one.compare(two) == 0){
                    result = false; // is "Star Wars" < "Star Wars"; false!
                }else{
                    bool resolution = false;
                    int index = 0;
                    std::string choice;
                    while(resolution != true){
                        if(one[index] != two[index]){
                            if(one[index] < two[index]){ //this part decides ascending descending
                                resolution = true;
                                choice = "one";
                            } else{
                                resolution = true;
                                choice = "two";
                            }
                        }
                        index += 1;
                    }
                        if(choice == "one"){
                            result = true;
                        }
                    }
            }else{
                result = one.length() < two.length();
            }
        }
        return result;
    }

    void sort_s(std::vector<std::string>& data, int low, int high) {
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

    int partition(std::vector<std::string> data, int low, int high){
        // Select the pivot element
        std::string pivot = data[low];
        int up=low, down=high;
        while(up<down){
            for (int j = up; j < high; j++){
                //if(data[up]<pivot)//Original line...
                if(compareString(data[up], pivot, '<'))
                    break;
            up++;
            }
            for (int j = high; j > low; j--){
                //if(data[down]>pivot)Original line...
                if(compareString(data[down], pivot, '>'))
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
