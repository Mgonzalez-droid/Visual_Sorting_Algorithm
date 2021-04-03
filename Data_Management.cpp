//FINAL_PROJECT_DATA_MANAGEMENT
#include<fstream>
#include<iostream>
#include"Review.cpp"

//const std::string FILE_ONE = "file_one";
//only need to load u.data and u.item, we dont need to specify, that is all the data we need

class Data_Management{
	std::string read_data(std::ifstream file){
		std::string line = "";
		if(std::getline(file, line) == false){

		}else{
			line
		}
	}
	//user_id (integer), item_id(integer), rating(integer), time_stamp(integer), title(string).
	//return array of data
	Review* deserialize_data(){
		std::ifstream file;
		try{
		file.open(file_name);
		}catch(std::string e){
			std::cout<<e<<std::endl;
			return;
		}
		read_data(file);
	}
	
	
}