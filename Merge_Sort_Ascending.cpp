#include<vector>
#include<iostream>
//Sort values in Ascending order
struct Merge_Sort_Ascending{
    int* arr;
    std::string* arrs;

    std::vector<int> ret_data_i(){
        std::vector<int> vec(arr + 0, arr + 100000);
        return vec;
    }

    std::vector<std::string> ret_data_s(){
        std::vector<std::string> vec(arrs + 0, arrs + 100000);
        return vec;
    }

    Merge_Sort_Ascending(std::vector<int> data, int low, int high){
        this -> arr = &data[0];
        sort_i(arr, low, high);

    }

    Merge_Sort_Ascending(std::vector<std::string> data, int low, int high){
        this -> arrs = &data[0];
        sort_s(arrs, low, high);
    }

//__________STRING______________

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

//From Notes....
    // Merge two subarrays from arr
void merge(std::string data[], int left, int mid, int right)
{
  // Create X ← arr[left..mid] & Y ← arr[mid+1..right]
  int n1 = mid - left + 1;
  int n2 = right - mid;

  std::string X[n1], Y[n2];

  for (int i = 0; i < n1; i++)
    X[i] = data[left + i];
  for (int j = 0; j < n2; j++)
    Y[j] = data[mid + 1 + j];

  // Merge the arrays X and Y into arr
  int i, j, k;
  i = 0;
  j = 0;
  k = left;
  while (i < n1 && j < n2) 
  {
    //if (X[i] <= Y[j]) //changed, ORiginal line
    if(compareString(X[i], Y[j], '<'))
    {
      data[k] = X[i];
      i++;
    } 
    else 
    {
      data[k] = Y[j];
      j++;
    }
    k++;
  }
 // When we run out of elements in either X or Y append the remaining elements
  while (i < n1) 
  {
    data[k] = X[i];
    i++;
    k++;
  }

  while (j < n2) 
  {
    data[k] = Y[j];
    j++;
    k++;
  }
}


void sort_s(std::string data[], int left, int right)
{
  if (left < right) 
  {
    // m is the point where the array is divided into two subarrays
    int mid = left + (right - left) / 2;

    sort_s(data, left, mid);
    sort_s(data, mid + 1, right);

    // Merge the sorted subarrays
    merge(data, left, mid, right);
  }
}


//___________INTEGER____________

//From Notes....
    // Merge two subarrays from arr
void merge(int data[], int left, int mid, int right)
{
  // Create X ← arr[left..mid] & Y ← arr[mid+1..right]
  int n1 = mid - left + 1;
  int n2 = right - mid;

  int X[n1], Y[n2];

  for (int i = 0; i < n1; i++)
    X[i] = data[left + i];
  for (int j = 0; j < n2; j++)
    Y[j] = data[mid + 1 + j];

  // Merge the arrays X and Y into arr
  int i, j, k;
  i = 0;
  j = 0;
  k = left;
  while (i < n1 && j < n2) 
  {
    if (X[i] <= Y[j]) //changed
    {
      data[k] = X[i];
      i++;
    } 
    else 
    {
      data[k] = Y[j];
      j++;
    }
    k++;
  }
 // When we run out of elements in either X or Y append the remaining elements
  while (i < n1) 
  {
    data[k] = X[i];
    i++;
    k++;
  }

  while (j < n2) 
  {
    data[k] = Y[j];
    j++;
    k++;
  }
}


void sort_i(int data[], int left, int right)
{
  if (left < right) 
  {
    // m is the point where the array is divided into two subarrays
    int mid = left + (right - left) / 2;

    sort_i(data, left, mid);
    sort_i(data, mid + 1, right);

    // Merge the sorted subarrays
    merge(data, left, mid, right);
  }
}
};
