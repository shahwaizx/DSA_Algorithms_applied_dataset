#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;


struct Hash{
	string iso;
    string country;
    double economicIndex;
    int rank;
    int quartile;
    double sizeGov;
    double legalRights;
    double soundMoney;
    double trade;
    double regulation;
    Hash *next = NULL;
    
    
};
int root = -1;
int last = -1;
int size = 200;
Hash *hash [200];
//Chaining Method
void insertHash(string iso,string country, double economicIndex, int rank, int quartile, double sizeGov, double legalRights, double soundMoney, double trade, double regulation)
    {
    	Hash *newNode = new Hash();
	newNode->iso = iso;
    newNode->country=country;
    newNode->economicIndex = economicIndex;
    newNode->rank = rank;
    newNode->quartile = quartile;
    newNode->sizeGov = sizeGov;
    newNode->legalRights = legalRights;
    newNode->soundMoney = soundMoney;
    newNode->trade = trade;
    newNode->regulation = regulation;
    //Calculating hashkey
    int hashkey=rank%size;
    //Checking if the index is null
	if(hash[hashkey]==NULL){
		hash[hashkey]=newNode;
	}
	//Collision confirmed
	else{
		Hash *temp = hash[hashkey];
		while(temp->next!=NULL){
			temp=temp->next;
			
		}
		temp->next=newNode;
	}
		
    }
    void printHash(){
		for(int i=0;i<size;i++){
			Hash *temp =hash[i];
			cout<<"Index--> "<<i<<"  ";
			while(temp!=NULL){
				cout<<temp->iso<<" "<<temp->country<<" "<<temp->rank<<" ";
				temp=temp->next;
			}
			cout<<endl;
		}
    
	}
	void searching(int r){
		int hashkey =r%size;
		if(hash[hashkey]==NULL){
			cout<<"No element"<<endl;
		}
		else{
			if(hash[hashkey]->rank==r){
				cout<<hash[hashkey]->iso<<" "<<hash[hashkey]->country<<" "<<hash[hashkey]->rank<<endl;
			}
			else{
				Hash *temp = hash[hashkey];
				while(temp!=NULL && temp->rank!=r){
					temp = temp->next;
				}
				if(temp==NULL){
					cout<<"Not Found"<<endl;
				}
				else{
					cout<<temp->iso<<" "<<temp->country<<" "<<temp->rank<<endl;
				}
			}
		}
	}




int main()
{
    ifstream fin;
    fin.open("economicdata2020-2020.csv");
    string line, word;
    vector<string> lineData;
    int lines = 0;
    while (!fin.eof())
    {
        // reading data and adding to vector
        getline(fin, line);
        stringstream s(line);
        while (getline(s, word, ','))
        {
            lineData.push_back(word);
        }
        // type casting duration from string to int
        stringstream s2(lineData[2]);
        double economicIndex;
        s2 >> economicIndex;

        stringstream s3(lineData[3]);
        int rank;
        s3 >> rank;

        stringstream s4(lineData[4]);
        int quartile;
        s4 >> quartile;

        stringstream s5(lineData[5]);
        double sizeGov;
        s5 >> sizeGov;

        stringstream s6(lineData[6]);
        double legalRights;
        s6 >> legalRights;

        stringstream s7(lineData[7]);
        double soundMoney;
        s7 >> soundMoney;

        stringstream s8(lineData[8]);
        double trade;
        s8 >> trade;

        stringstream s9(lineData[9]);
        double regulation;
        s9 >> regulation;

        if (lines != 0)
        {
            insertHash(lineData[0], lineData[1], economicIndex, rank, quartile, sizeGov, legalRights, soundMoney, trade, regulation);
        }
        // clearing vector
        lineData.clear();
        lines++;
    }
    int opt;
    do{
    	cout<<"Press 1 for printing hash table: "<<endl;
    	cout<<"Press 2 for searching: "<<endl;
    	cout<<"Press 0 to exit"<<endl;
    	cin>>opt;
    	switch(opt){
    		case 1:
    			printHash();
    			break;
    		case 2:
				cout<<"Enter the rank to search: "<<endl;
				int ra;
				cin>>ra;
				searching(ra);
				break;	
		}
	}while(opt!=0);

    return 0;

}


