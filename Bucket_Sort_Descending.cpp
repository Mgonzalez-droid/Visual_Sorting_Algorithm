struct Bucket_Sort_Descending{
    std::vector<int> org_data_i;
    std::vector<int> ret_data_i;

    std::vector<std::string> org_data_s;
    std::vector<std::string> ret_data_s;

    int bucket_size = 0;

    Bucket_Sort_Descending(std::vector<int>& passedData){
        this -> bucket_size = passedData.size();
        this -> org_data_i = passedData;
        sort_i();
    }

    Bucket_Sort_Descending(std::vector<std::string>& passedData){
        this -> bucket_size = passedData.size();
        this -> org_data_s = passedData;
        sort_s();
    }

    int addTrailingZeros(int num, int trailingZeros){
        if(trailingZeros == 0){
            return num;
        }else{
            num = num * 10;
            trailingZeros = trailingZeros - 1;
            addTrailingZeros(num, trailingZeros);
        }
    }

    int determineIndex(int element){
        //convert passed integer to string
        std::string str;
        std::stringstream ss;

        ss << element;
        ss >> str;

        int length = str.length();

        if(length > 5) //removes elements larger than 100000
            length = 5;

        int trailingZeros = length - 1;
        char c = str[0];
        int num = c - '0';
        int index = addTrailingZeros(num,trailingZeros);

        return index;
    }

    void sort_i(){
        std::vector<int> bucket[bucket_size];

        for(int i = 0; i < bucket_size; i++){
            int index = determineIndex(org_data_i[i]);
            bucket[index].push_back(org_data_i[i]);
        }

        // FOR DESCENDING ORDER: sort(arr, arr + n, greater<int>());
        //sorts individual buckets
        for(int i = 0; i < bucket_size; i++){
            std::sort(bucket[i].begin(), bucket[i].end(), std::greater<int>()); //what is changed
        }

        for(int i = bucket_size - 1; i > 0; i--){
            for(int j = 0; j < bucket[i].size(); j++){
                ret_data_i.push_back(bucket[i][j]);
            }
        }
    }



    void sort_s(){

        std::map<char, std::vector<std::string>> bucket;

        for(int i = 0; i < bucket_size; i++){
            std::string str = org_data_s[i];
            if(bucket.find(str[0]) != bucket.end()){
                auto it = bucket.find(str[0]);
                it -> second.push_back(str);
            } else{
                bucket[str[0]].push_back(str);
            }
        }

        for(auto it : bucket)
            std::sort(it.second.begin(), it.second.end(), std::greater<std::string>());

        for(int i = bucket_size - 1; i > 0; i--){
            for(int j = 0; j < bucket[i].size(); j++){
                ret_data_s.push_back(bucket[i][j]);
            }
        }
    }

};