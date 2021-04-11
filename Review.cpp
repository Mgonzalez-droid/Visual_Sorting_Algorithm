#ifndef HEADER_H
#define HEADER_H

#include<iostream>

class Review{
private:
	//user_id (integer), item_id(integer), rating(integer), time_stamp(integer), title(string).
	int user_id = 0;
	int rating = 0;
	int time_stamp = 0;
	int movie_id = 0;
	std::string movie_title ="";

public:
	Review(){

	}

	void set_userId(int& user_id){
		this -> user_id = user_id;
	}

	void set_rating(int& rating){
		this -> rating = rating;
	}

	void set_time_stamp(int& time_stamp){
		this -> time_stamp = time_stamp;
	}

	void set_movieId(int& movie_id){
		this -> movie_id = movie_id;
	}

	void set_movieTitle(std::string& movie_title){
		this -> movie_title = movie_title;
	}

	int get_userId(){ //pass by pointer for speed boost!
		return this-> user_id;
	}
	
	int  get_movieId(){
		return this -> movie_id;
	}

	int get_rating(){
		return this -> rating;
	}

	int get_timeStamp(){
		return this -> time_stamp;
	}
	std::string get_movieTitle(){
		return this -> movie_title;
	}
};
#endif