//////////////////////////////////////////////////////////////////////////////////
// Author:   R. Erdem Uysal
// Company:   Atılım University
// 
// Create Date:   21:16:00 10/28/2015 
// Project Name:   IP Parsing from Log Data	
// Additional Comments: 
// This project have done for CS101- Introduction to Programming course.
// You can download log file that I used in this project from this link;
// http://ita.ee.lbl.gov/html/contrib/NASA-HTTP.html
//////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

int main(){

	string data;
	int last_site, fetch_url, last_url;
	
	ifstream readFile("C:\Users\ASUS\Desktop\IP Parsing from Log Data\NASA_access_log_Jul95", ios::in);					// Reading from text file
	ofstream writeFile("C:\Users\ASUS\Desktop\output.txt", ios::app); 													// Parsing string and write into the text file
	ofstream cleanFile("C:\Users\ASUS\Desktop\output.txt");
	
	cleanFile<<endl;																									// Cleaning file
	
																														// First index of site's adress that taken line by line from file is '0'
	
	while (readFile){
	
		getline(readFile, data, '\n');
	
		for(int i=0; i<data.size(); i++)
		{		
			if(data[i] == '[')																							// 
			last_site = i;	
	
			if(data[i] == ']')																							//
			fetch_url = i;
		}
	
		fetch_url+=6;																									//
	
		for(int j = fetch_url; j<data.size(); j++)																		//
	
			if(data[j] == '\"')							
				last_url = j;
		
		for(int j = 0; j<last_site; j++)																				//
			writeFile<<" ";	
		
		for(int j = fetch_url; j<last_url; j++)																			//
		
			writeFile<<data[j];
			writeFile<<endl;
	
	}
	
	cout<<"Process completed.";
	return 0;
	
	}