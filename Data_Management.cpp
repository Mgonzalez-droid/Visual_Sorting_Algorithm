//FINAL_PROJECT_DATA_MANAGEMENT
#include<fstream>
#include<iostream>
#include<vector>
#include<map>

//const std::string FILE_ONE = "file_one";
//only need to load u.data and u.item, we dont need to specify, that is all the data we need

class Data_Management{
private:

    std::map<std::string, std::vector<int> > data;
    std::map<int, std::string> movies;

    void Deserialize(){
        //read review data
        std::ifstream fileOne("/Users/michel/CLionProjects/Visual_Sorting_Algorithm/Data/u.data");
        std::string line;
        //bool isOpen = fileOne.is_open();
        while(!fileOne.eof() && line != " "){
            std::getline(fileOne, line, '\t');
            if(line != " " && line != ""){
                data["userId"].push_back(std::stoi(line));
                //For Debugging:
                //std::cout<<"Successfully added review: " << line;
            }

            std::getline(fileOne, line, '\t');
            if(line != " " && line != ""){
                data["itemId"].push_back(std::stoi(line));
                //For Debugging:
                //std::cout<< " " << line;
            }

            std::getline(fileOne, line, '\t');
            if(line != " " && line != ""){
                data["rating"].push_back(std::stoi(line));
                //For Debugging:
                //std::cout<< " " << line;
            }

            std::getline(fileOne, line, '\n');
            if(line != " " && line != ""){
                data["time_stamp"].push_back(std::stoi(line));
                //For Debugging:
                //std::cout<< " " << line <<std::endl;
            }
        }

        std::ifstream fileTwo("/Users/michel/CLionProjects/Visual_Sorting_Algorithm/Data/u.item");
        line = "";
        int itemId;
        while(!fileTwo.eof() && line != " "){
            std::getline(fileTwo,line,'|');
            if(line != " " && line != ""){
                itemId = std::stoi(line);
                //For Debugging:
                //std::cout<<"Successfully added movie: " << " " << itemId;
            }

            std::getline(fileTwo,line,'|');
            if(line != " " && line != ""){
                movies[itemId] = line;
                //For Debugging:
                //std::cout<< " " << line << std::endl;
            }

            std::getline(fileTwo,line,'\n');
        }
    }
public:
	Data_Management(){
		Deserialize();
	}

	/*
	Review get_a_review(int index){

	}

	std::vector<Review> get_reviews(){

	}
    */
	//user_id (integer), item_id(integer), rating(integer), time_stamp(integer), movie_title(string).
	std::vector<int> getUserIdVec(){
        auto it = data.find("userId");
	    return it->second;
	}

	std::vector<int> getItemIdVec(){
        auto it = data.find("itemId");
        return it->second;
	}

	std::vector<int> getRatingVec(){
        auto it = data.find("rating");
        return it->second;
	}

	std::vector<int> getTimeStampVec(){
        auto it = data.find("time_stamp");
        return it->second;
	}

	// need to decide what to do here, maybe change movieTitles to a vector containing just movie titles
	std::vector<std::string> getMovieTitleVec(){
        std::vector<std::string> result;
	    for(auto movies : movies){
            result.push_back(movies.second);
        }
	    return result;
	}
};
