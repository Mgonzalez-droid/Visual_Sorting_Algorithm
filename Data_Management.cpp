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
	std::vector<Review> reviews;
	std::map<int,std::string> movieKeys;

	void splitReviews(const std::string &s, char delim) {
    	std::stringstream ss;
    	ss.str(s);
    	std::string item;
		Review review;
		int temp = 0;

		std::getline(ss,item,delim);
		temp = std::stoi(item);
		review.set_userId(temp);

		std::getline(ss,item,delim);
		temp = std::stoi(item);
		review.set_movieId(temp);

		std::getline(ss,item,delim);
		temp = std::stoi(item);
		review.set_rating(temp);

		std::getline(ss,item,delim);
		temp = std::stoi(item);
		review.set_time_stamp(temp);

		reviews.push_back(review);
	}

	void splitMovies(const std::string &s){
		std::stringstream ss;
    	ss.str(s);
		std::string item;

		std::getline(ss,item,'\t');
		if(movieKeys.find(std::stoi(item)) == movieKeys.end()){
			int itemId = std::stoi(item);

			std::getline(ss,item,'\t');

			movieKeys[itemId] = item;
		}
	}

	//user_id (integer), item_id(integer), rating(integer), time_stamp(integer), movie_title(string).
	//return array of data
	void deserialize_data(){
		std::ifstream file;
		try{
		file.open("Data/u.data");
		
		std::string line;
		while(std::getline(file,line)){
			splitReviews(line, '\t');
		}

		}catch(std::string e){
			std::cout<<e<<std::endl;
			return;
		}

		try{
		file.open("Data/u.item");
		
		std::string line;
		while(std::getline(file, line)){
			splitMovies(line);
		}

		}catch(std::string e){
			std::cout<<e<<std::endl;
			return;
		}
		
		//assign movie titles to the reviews
		for(int i = 0; i < reviews.size(); i++){
			auto it = movieKeys.find(reviews[i].get_movieId());
			reviews[i].set_movieTitle(it -> second);
		}
	}
public:
	Data_Management(){
		deserialize_data();
	}

	Review get_a_review(int index){
		return reviews[index];
	}

	std::vector<Review> get_reviews(){
		return reviews;
	}

	//user_id (integer), item_id(integer), rating(integer), time_stamp(integer), movie_title(string).
	std::vector<int> getUserIdVec(){
		std::vector<int> userIds;
		for(int i = 0; i < reviews.size(); i++){
			userIds.push_back(reviews[i].get_userId());
		}
		return userIds;
	}

	std::vector<int> getItemIdVec(){
		std::vector<int> itemIds;
		for(int i = 0; i < reviews.size(); i++){
			itemIds.push_back(reviews[i].get_movieId());
		}
		return itemIds;
	}

	std::vector<int> getRatingVec(){
		std::vector<int> ratings;
		for(int i = 0; i < reviews.size(); i++){
			ratings.push_back(reviews[i].get_rating());
		}
		return ratings;
	}

	std::vector<int> getTimeStampVec(){
		std::vector<int> timeStamps;
		for(int i = 0; i < reviews.size(); i++){
			timeStamps.push_back(reviews[i].get_timeStamp());
		}
		return timeStamps;
	}

	std::vector<std::string> getMovieTitleVec(){
		std::vector<std::string> movieTitles;
		for(int i = 0; i < reviews.size(); i++){
			movieTitles.push_back(reviews[i].get_movieTitle());
		}
		return movieTitles;
	}
};
