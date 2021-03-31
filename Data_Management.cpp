//FINAL_PROJECT_DATA_MANAGEMENT
# include<fstream>
#include<iostream>

//const std::string FILE_ONE = "file_one";

class Data_Management{
	std::string read_data(std::ifstream file){
		std::string line = "";
		if(std::getline(file, line) == false){

		}else{
			line
		}
	}
	//user_id (integer), item_id(integer), rating(integer), time_stamp(integer), title(string).
	std::string deserialize_data(std::string file_name){
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