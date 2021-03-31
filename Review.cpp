class Review{
private:
	//user_id (integer), item_id(integer), rating(integer), time_stamp(integer), title(string).
	int user_id = 0;
	int item_id = 0;
	float rating = 0.0;//should it really be int?
	int time_stamp = 0;
	int movie_id = 0;
	std::string movie_title ="";

public:
	int* get_userId(){ //pass by pointer for speed boost!
		return this-> user_id;
	}
	get_itemId(){
		
	}
	
};