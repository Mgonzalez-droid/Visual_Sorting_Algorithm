//FINAL_PROJECT_DATA_MANAGEMENT
# include<fstream>

const std::string FILE_ONE = "file_one";

class Data_Management{
	void read_data(std::ifstream file){
		if(
	}
	//user_id (integer), item_id(integer), rating(integer), time_stamp(integer), title(string).
	void static deserialize_data(bool user_id, bool item_id, bool rating, bool time_stamp, bool title){
		try{
		//could do with for loop but it'd be fun to use a recursive function...
		std::ifstream file;
		//do this same process for each file for appropriate data
		file.open(FILE_ONE);
		//ifstream myfile (FILE_ONE, ios::binary);
		read_data(file);
		
		}catch(std::string e){
			std::cout<<e<<std::endl;
		}
	}
	
	
}