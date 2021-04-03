class Review{
private:
	//user_id (integer), item_id(integer), rating(integer), time_stamp(integer), title(string).
	int user_id = 0;
	int rating = 0;
	int time_stamp = 0;
	int movie_id = 0;
	std::string movie_title ="";

public:
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

	}
	std::string get_movieTitle(){
		return this -> movie_title;
	}
};