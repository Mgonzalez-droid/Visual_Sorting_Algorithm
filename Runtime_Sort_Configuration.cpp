#include"Merge_Sort_Descending.cpp"//min
#include"Merge_Sort_Ascending.cpp"//max
#include"Quick_Sort_Descending.cpp"//min
#include"Quick_Sort_Ascending.cpp"//max
#include"Bucket_Sort_Ascending.cpp"//max
#include"Bucket_Sort_Descending.cpp"//min

const int USER_ID = 1;
const int ITEM_ID = 2;
const int MOVIE_TITLE = 3;
const int RATING = 4;
const int TIME_STAMP = 5;
const int QUICK_SORT = 6;
const int MERGE_SORT = 7;
const int BUCKET_SORT = 8;
const int DESCENDING = 9;
const int ASCENDING = 10;

void sort_data(int,int);

void mergeSort(std::vector<int>, int);
void mergeSort(std::vector<std::string>, int);
void quickSort(std::vector<int>, int);
void quickSort(std::vector<std::string>, int);
void bucketSort(std::vector<int>, int);
void bucketSort(std::vector<std::string>, int);

//For debugging
template<class t>
void print_results(std::vector<t> my_data){
    for(int i = 0; i < my_data.size(); i++)
        std::cout<<my_data[i]<<std::endl;
}
template<class t>
void test(std::vector<t> my_data, int sort_property){
    if(sort_property == ASCENDING){
        //Bucket_Sort_Ascending sort(my_data);
        //print_results(sort.ret_data_i);

        //int low = 0;
        //int high = my_data.size()-1;
        //Quick_Sort_Ascending sort(my_data, low, high);
        //print_results(sort.ret_data_s());

        int start = 0;
        int end = my_data.size() - 1;
        Merge_Sort_Ascending sort(my_data,start,end);
        print_results(sort.ret_data_s());

    }

    if(sort_property == DESCENDING){
        //Bucket_Sort_Descending sort(my_data);
        //print_results(sort.ret_data_i);

        //int low = 0;
        //int high = my_data.size()-1;
        //Quick_Sort_Descending sort(my_data, low, high);
        //print_results(sort.ret_data_s());

        int start = 0;
        int end = my_data.size() - 1;
        Merge_Sort_Descending sort(my_data,start,end);
        print_results(sort.ret_data_s());

    }

}

//For file creation and deletion

template<class t>
void createReport(std::vector<t> results,int sortingMethod, int sort_property){
    switch(sortingMethod){
        case QUICK_SORT:{

            if(sort_property == ASCENDING){
                //char reportName[] = "/Users/michel/CLionProjects/Visual_Sorting_Algorithm/Results/quick_sort_ascending_results.txt";
                char reportName[] = "Results/quick_sort_ascending_results.txt";
                //remove old report if applicable
                remove(reportName);
                //create new report
                std::ofstream MyFile(reportName);

                //write data to file
                for(int i = 0; i < results.size(); i++){
                    MyFile << results[i] << "\n";
                }
                //close file
                MyFile.close();
            }

            if(sort_property == DESCENDING){
                //char reportName[] = "/Users/michel/CLionProjects/Visual_Sorting_Algorithm/Results/quick_sort_descending_results.txt";
                char reportName[] = "Results/quick_sort_descending_results.txt";
                //remove old report if applicable
                remove(reportName);
                //create new report
                std::ofstream MyFile(reportName);

                //write data to file
                for(int i = 0; i < results.size(); i++){
                    MyFile << results[i] << "\n";
                }
                //close file
                MyFile.close();
            }
        }break;

        case MERGE_SORT:{
            if(sort_property == ASCENDING){
                //char reportName[] = "/Users/michel/CLionProjects/Visual_Sorting_Algorithm/Results/merge_sort_ascending_results.txt";
                char reportName[] = "Results/merge_sort_ascending_results.txt";
                //remove old report if applicable
                remove(reportName);
                //create new report
                std::ofstream MyFile(reportName);

                //write data to file
                for(int i = 0; i < results.size(); i++){
                    MyFile << results[i] << "\n";
                }
                //close file
                MyFile.close();
            }

            if(sort_property == DESCENDING){
                //char reportName[] = "/Users/michel/CLionProjects/Visual_Sorting_Algorithm/Results/merge_sort_descending_results.txt";
                char reportName[] = "Results/merge_sort_descending_results.txt";
                //remove old report if applicable
                remove(reportName);
                //create new report
                std::ofstream MyFile(reportName);

                //write data to file
                for(int i = 0; i < results.size(); i++){
                    MyFile << results[i] << "\n";
                }
                //close file
                MyFile.close();
            }
        }break;
        case BUCKET_SORT:{
            if(sort_property == ASCENDING){
                //char reportName[] = "/Users/michel/CLionProjects/Visual_Sorting_Algorithm/Results/bucket_sort_ascending_results.txt";
                char reportName[] = "Results/bucket_sort_ascending_results.txt";
                //remove old report if applicable
                remove(reportName);
                //create new report
                std::ofstream MyFile(reportName);

                //write data to file
                for(int i = 0; i < results.size(); i++){
                    MyFile << results[i] << "\n";
                }
                //close file
                MyFile.close();
            }

            if(sort_property == DESCENDING){
                //char reportName[] = "/Users/michel/CLionProjects/Visual_Sorting_Algorithm/Results/bucket_sort_descending_results.txt";
                char reportName[] = "Results/bucket_sort_descending_results.txt";
                //remove old report if applicable
                remove(reportName);
                //create new report
                std::ofstream MyFile(reportName);

                //write data to file
                for(int i = 0; i < results.size(); i++){
                    MyFile << results[i] << "\n";
                }
                //close file
                MyFile.close();
            }
        }break;
    }
}

//Sorting and sorting helper methods

void sort_data(int choice, int sort_property){
    Data_Management data;
    switch(choice){
        case USER_ID :{
            std::vector<int> my_data = data.getUserIdVec();
            //test(my_data,sort_property);
            mergeSort(my_data,sort_property);
            quickSort(my_data,sort_property);
            bucketSort(my_data,sort_property);
        };
            break;

        case ITEM_ID :{
            std::vector<int> my_data = data.getItemIdVec();
            //test(my_data,sort_property);
            mergeSort(my_data,sort_property);
            quickSort(my_data,sort_property);
            bucketSort(my_data,sort_property);
        };
            break;

        case RATING :{
            std::vector<int> my_data = data.getRatingVec();
            //test(my_data,sort_property);
            mergeSort(my_data,sort_property);
            quickSort(my_data,sort_property);
            bucketSort(my_data,sort_property);
        };
            break;

        case TIME_STAMP :{
            std::vector<int> my_data = data.getTimeStampVec();
            //test(my_data,sort_property);
            mergeSort(my_data,sort_property);
            quickSort(my_data,sort_property);
            bucketSort(my_data,sort_property);
        };
            break;

        case MOVIE_TITLE :{
            std::vector<std::string> my_data = data.getMovieTitleVec();
            //test(my_data,sort_property);
            mergeSort(my_data,sort_property);
            quickSort(my_data,sort_property);
            bucketSort(my_data,sort_property);
        };
            break;
    }
}

void mergeSort(std::vector<int> my_data, int sort_property){
    //start time
    time_t t_start = time(nullptr);
    time_t t_end;

    int start = 0;
    int end = my_data.size() - 1;
    if(sort_property == ASCENDING){
        Merge_Sort_Ascending merge(my_data, start, end);

        //end time
        t_end = time(nullptr);

        my_data = merge.ret_data_i();

    }else if(sort_property == DESCENDING){
        Merge_Sort_Descending merge(my_data, start, end);

        //end time
        t_end = time(nullptr);

        my_data = merge.ret_data_i();
    }


    //output time difference
    std::cout<<std::endl<<"Merge Sort took "<< t_end - t_start <<" second(s)."<<std::endl;
    //print results to text file
    createReport(my_data,MERGE_SORT,sort_property);
}

void mergeSort(std::vector<std::string> my_data, int sort_property){
    //start time
    time_t t_start = time(nullptr);
    time_t t_end;

    int start = 0;
    int end = my_data.size() - 1;
    if(sort_property == ASCENDING){
        Merge_Sort_Ascending merge(my_data, start, end);

        //end time
        t_end = time(nullptr);

        my_data = merge.ret_data_s();

    }else if(sort_property == DESCENDING){
        Merge_Sort_Descending merge(my_data, start, end);

        //end time
        t_end = time(nullptr);

        my_data = merge.ret_data_s();
    }


    //output time difference
    std::cout<<std::endl<<"Merge Sort took "<< t_end - t_start <<" second(s)."<<std::endl;
    //print results to text file
    createReport(my_data,MERGE_SORT,sort_property);
}

void quickSort(std::vector<int> my_data, int sort_property){
    //start time
    time_t t_start = time(nullptr);
    time_t t_end;
    int low = 0;
    int high = my_data.size()-1;
    if(sort_property == ASCENDING){
        Quick_Sort_Ascending quick(my_data,low, high);

        //end time
        t_end = time(nullptr);

        my_data = quick.ret_data_i();

    }else if(sort_property == DESCENDING){
        Quick_Sort_Descending quick(my_data,low, high);

        //end time
        t_end = time(nullptr);

        my_data = quick.ret_data_i();

    }


    //output time difference
    std::cout<< "Quick Sort took " << t_end - t_start << " second(s)." <<std::endl;
    //print results to text file
    createReport(my_data,QUICK_SORT,sort_property);
}

void quickSort(std::vector<std::string> my_data, int sort_property){
    //start time
    time_t t_start = time(nullptr);
    time_t t_end;
    int low = 0;
    int high = my_data.size()-1;
    if(sort_property == ASCENDING){
        Quick_Sort_Ascending quick(my_data,low, high);

        //end time
        t_end = time(nullptr);

        my_data = quick.ret_data_s();

    }else if(sort_property == DESCENDING){
        Quick_Sort_Descending quick(my_data,low, high);

        //end time
        t_end = time(nullptr);

        my_data = quick.ret_data_s();

    }


    //output time difference
    std::cout<< "Quick Sort took " << t_end - t_start << " second(s)." <<std::endl;
    //print results to text file
    createReport(my_data,QUICK_SORT,sort_property);
}

void bucketSort(std::vector<int> my_data, int sort_property){
    //start time
    time_t t_start = time(nullptr);
    time_t t_end;
    if(sort_property == ASCENDING){
        Bucket_Sort_Ascending sort(my_data);

        t_end = time(nullptr);

        my_data = sort.ret_data_i;

    }

    if(sort_property == DESCENDING){
        Bucket_Sort_Descending sort(my_data);

        t_end = time(nullptr);

        my_data = sort.ret_data_i;
    }

    //output time difference
    std::cout<<"Bucket Sort took "<< t_end - t_start <<" second(s)."<<std::endl;
    //print results to text file
    createReport(my_data,BUCKET_SORT,sort_property);
}

void bucketSort(std::vector<std::string> my_data, int sort_property){
    //start time
    time_t t_start = time(nullptr);
    time_t t_end;
    if(sort_property == ASCENDING){
        Bucket_Sort_Ascending sort(my_data);

        t_end = time(nullptr);

        my_data = sort.ret_data_s;

    }

    if(sort_property == DESCENDING){
        Bucket_Sort_Descending sort(my_data);

        t_end = time(nullptr);

        my_data = sort.ret_data_s;
    }

    //output time difference
    std::cout<<"Bucket Sort took "<< t_end - t_start <<" second(s)."<<std::endl;
    //print results to text file
    createReport(my_data,BUCKET_SORT,sort_property);
}