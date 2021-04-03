//FINAL_PROJECT_MAIN
#include<iostream>
#include"Data_Management.cpp"
#include"Review.cpp"
#include"Merge_Sort.cpp"
#include"Quick_Sort.cpp"
#include<map>
//create a map of key string, val vector<int or string>


//user_id (integer), item_id(integer), rating(integer), time_stamp(integer), title(string).
Review* createMyData(bool user_id, bool item_id, bool rating, bool time_stamp, bool title){
    t* reviews = new Review[100000];
    Data_Management d;
    reviews = d.deserialize_data();
    splitData(reviews);
    return reviews;
}

Review* sortMyData(Review* reviews,bool quicksort, bool max){
    
    if(!quicksort){
        Merge_Sort::sort(reviews, max);
    }else{
        Quick_Sort::sort(reviews, max);
    }
}

template<class t>
 void printMydata(t* reviews){
     std::cout<<*reviews<<std::endl;
 }

//user_id (integer), item_id(integer), rating(integer), time_stamp(integer), title(string).
int main(){
    //TODO: To be done with UI
    bool user_id = true;
    bool item_id = true;
    bool rating = true;
    bool time_stamp = true;
    bool title = true;

    t* reviews = createMyData(user_id,item_id,rating,time_stamp,title);

    //TODO: define variables for UI
    //quick sort min
    reviews = sortMyData(reviews, true, false);

    //quick sort max
    reviews = sortMyData(reviews, true, true);

    //merge sort min
    reviews = sortMyData(reviews, false, false);

    //merge sort max
    reviews = sortMyData(reviews, false, true);
    
}
