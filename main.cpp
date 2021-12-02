#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

class Password {
	public:
		string content;
		int count;
};

vector<Password> sortPasswords(vector<Password> vec){
	for(int a=0; a<vec.size()-1; a++){
		for(int b=0; b<vec.size()-1-a; b++){
			if((int)vec[b].content[0] > (int)vec[b+1].content[0]){
				iter_swap(vec.begin() + b, vec.begin() + b+1);
			}
		}
    }	
	return vec;
}

int main(){
	ifstream dane("hasla.txt");
	string password;
	int passOnlyFromNum = 0;
	vector<Password> allPass;
	while(dane >> password){
		//74.1
		bool allAreNumbers = true;
		for(int a=0; a<password.size(); a++){
			if((int)password[a] < (int)'0' || (int)password[a] > (int)'9'){
				allAreNumbers = false;
				break;
			}
		}
		if(allAreNumbers){
		    passOnlyFromNum++;
		}
		//74.2
		bool found = false;
		for(int a=0; a<allPass.size(); a++){
			if(allPass[a].content == password){
				allPass[a].count++;
				found = true;
			}
		}
		if(!found){
			Password h;
			h.content = password;
			h.count = 1;
			allPass.push_back(h);
		}
	}
	
	cout << "74.1: " << endl << passOnlyFromNum << endl;
	cout << "74.2: " << endl;
	vector<Password> sorted = sortPasswords(allPass);
	for(int a=0; a<sorted.size(); a++){
		if(sorted[a].count > 1){
			cout << sorted[a].content << endl;
		}
	}
}
