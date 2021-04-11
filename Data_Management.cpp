//FINAL_PROJECT_DATA_MANAGEMENT
#include<fstream>
#include<iostream>
#include<sstream>
#include<vector>
#include<map>
#include"Review.cpp"

//const std::string FILE_ONE = "file_one";
//only need to load u.data and u.item, we dont need to specify, that is all the data we need

class Data_Management{
private:

    std::map<std::string, std::vector<std::string> > data;
    std::map<int, std::string> movies;

    void Deserialize(){
        //read review data
        std::ifstream fileOne("/Users/michel/CLionProjects/file_testing/Data/u.data");
        std::string line;
        //bool isOpen = fileOne.is_open();
        while(!fileOne.eof() && line != " "){
            std::getline(fileOne, line, '\t');
            if(line != " " && line != ""){
                data["userId"].push_back(line);
                std::cout<<"Successfully added review: " << line;
            }

            std::getline(fileOne, line, '\t');
            if(line != " " && line != ""){
                data["movieId"].push_back(line);
                std::cout<< " " << line;
            }

            std::getline(fileOne, line, '\t');
            if(line != " " && line != ""){
                data["rating"].push_back(line);
                std::cout<< " " << line;
            }

            std::getline(fileOne, line, '\n');
            if(line != " " && line != ""){
                data["time_stamp"].push_back(line);
                std::cout<< " " << line <<std::endl;
            }
        }

        std::ifstream fileTwo("/Users/michel/CLionProjects/file_testing/Data/u.item");
        line = "";
        int itemId;
        while(!fileTwo.eof() && line != " "){
            std::getline(fileTwo,line,'|');
            if(line != " " && line != ""){
                itemId = std::stoi(line);
                std::cout<<"Successfully added movie: " << " " << itemId;
            }

            std::getline(fileTwo,line,'|');
            if(line != " " && line != ""){
                movies[itemId] = line;
                std::cout<< " " << line << std::endl;
            }

            std::getline(fileTwo,line,'\n');
        }
    }
public:
	Data_Management(){
		Deserialize();
	}

	Review get_a_review(int index){

	}

	std::vector<Review> get_reviews(){

	}

	//user_id (integer), item_id(integer), rating(integer), time_stamp(integer), movie_title(string).
	std::vector<int> getUserIdVec(){

	}

	std::vector<int> getItemIdVec(){

	}

	std::vector<int> getRatingVec(){

	}

	std::vector<int> getTimeStampVec(){

	}

	std::vector<std::string> getMovieTitleVec(){

	}
};
