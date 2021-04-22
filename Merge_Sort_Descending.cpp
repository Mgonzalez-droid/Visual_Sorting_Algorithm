#include<vector>
#include<iostream>
//Sort Values in Descending order
struct Merge_Sort_Descending{

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

    Merge_Sort_Descending(std::vector<int> data, int low, int high){
        this -> arr = &data[0];
        sort_i(arr, low, high);

    }

    Merge_Sort_Descending(std::vector<std::string> data, int low, int high){
        this -> arrs = &data[0];
        sort_s(arrs, low, high);
        std::vector<std::string> vec(arrs + 0, arrs + 1682);
        this -> vec_s = vec;
    }

//__________STRING______________

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
                    //isTrue = !true;
                    isTrue = true;
                    std::cout<<one[0]<<" is greater than " << two[0] << " because " << res << " > 0" << std::endl;
                }else{
                    //one is less than two
                    //isTrue = !false;
                    isTrue = false;
                    std::cout<<one[0]<<" is less than " << two[0] << " because " << res << " < 0" << std::endl;
                }
            }else{
                //one is equal too two
                isTrue = true;
                //isTrue = false;
                std::cout<<one[0]<<" is equal to " << two[0] << " because " << res << " == 0" << std::endl;
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
                isTrue = true;
                //isTrue = false;
            }
        }

        return isTrue;
    }

    // Merge two subarrays from arr
    void merge(std::string arr[], int left, int mid, int right)
    {
        // Create X ← arr[left..mid] & Y ← arr[mid+1..right]
        int n1 = mid - left + 1;
        int n2 = right - mid;

        std::string X[n1], Y[n2];

        for (int i = 0; i < n1; i++)
            X[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            Y[j] = arr[mid + 1 + j];

        // Merge the arrays X and Y into arr
        int i, j, k;
        i = 0;
        j = 0;
        k = left;
        while (i < n1 && j < n2)
        {
            if (X[i] >= Y[j])
            {
                arr[k] = X[i];
                i++;
            }
            else
            {
                arr[k] = Y[j];
                j++;
            }
            k++;
        }
        // When we run out of elements in either X or Y append the remaining elements
        while (i < n1)
        {
            arr[k] = X[i];
            i++;
            k++;
        }

        while (j < n2)
        {
            arr[k] = Y[j];
            j++;
            k++;
        }
    }

    void sort_s(std::string arr[], int left, int right)
    {
        if (left < right)
        {
            // m is the point where the array is divided into two subarrays
            int mid = left + (right - left) / 2;

            sort_s(arr, left, mid);
            sort_s(arr, mid + 1, right);

            // Merge the sorted subarrays
            merge(arr, left, mid, right);
        }
    }


//___________INTEGER____________

//From Notes....
    // Merge two subarrays from arr
    void merge(int arr[], int left, int mid, int right)
    {
        // Create X ← arr[left..mid] & Y ← arr[mid+1..right]
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int X[n1], Y[n2];

        for (int i = 0; i < n1; i++)
            X[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            Y[j] = arr[mid + 1 + j];

        // Merge the arrays X and Y into arr
        int i, j, k;
        i = 0;
        j = 0;
        k = left;
        while (i < n1 && j < n2)
        {
            if (X[i] >= Y[j]) //changed
            {
                arr[k] = X[i];
                i++;
            }
            else
            {
                arr[k] = Y[j];
                j++;
            }
            k++;
        }
        // When we run out of elements in either X or Y append the remaining elements
        while (i < n1)
        {
            arr[k] = X[i];
            i++;
            k++;
        }

        while (j < n2)
        {
            arr[k] = Y[j];
            j++;
            k++;
        }
    }


    void sort_i(int arr[], int left, int right)
    {
        if (left < right)
        {
            // m is the point where the array is divided into two subarrays
            int mid = left + (right - left) / 2;

            sort_i(arr, left, mid);
            sort_i(arr, mid + 1, right);

            // Merge the sorted subarrays
            merge(arr, left, mid, right);
        }
    }
};
