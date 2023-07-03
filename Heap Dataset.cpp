#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;


struct MinHeap{
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
    
    
};
int root = -1;
int last = -1;
int size = 200;
MinHeap *heap [200];
void insert(string iso,string country, double economicIndex, int rank, int quartile, double sizeGov, double legalRights, double soundMoney, double trade, double regulation)
    {
    	MinHeap *newNode = new MinHeap();
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
    	
        int temp,parent;
        if (last == size - 1)
        {
            cout << "Heap is full" << endl;
            return;
        }
        else if (last == -1)
        {
            last = 0;
            root = last;
            heap[last] = newNode;
        }
        else
        {
            last++;
            heap[last] = newNode;
            temp = last;
           parent=(temp-1)/2;
           while(temp !=0 && heap[temp]->rank <= heap[parent]->rank){
    		MinHeap *sw = heap[temp];
    		heap[temp] = heap[parent];
    		heap[parent] = sw;
    		temp = parent;
    		parent=(temp-1)/2;
         	
		   }
           
        }
    }
    void deletion_heap(int nodeIndex){
			int left,right,min;
			MinHeap *temp;
			left=(2*nodeIndex)+1;
			right=(2*nodeIndex)+2;
			if(right>last){
				if(left>last){
					return;
				}
				else{
					min=left;
				}
			}
			else{
				int temp = heap[left]->rank;
				int temp1 = heap[right]->rank;
				if(temp<temp1){
					min=left;
				}
				else{
					min=right;
				}
			}
			if(heap[nodeIndex]->rank>heap[min]->rank){
				temp=heap[min];
				heap[min]=heap[nodeIndex];
				heap[nodeIndex]=temp;
				deletion_heap(min);
				
			}
		
	}
	void deletion_heap_final(){
		if(last==-1){
			cout<<"No element in heap to be deleted"<<endl;
		}
		else{
			heap[root]=heap[last];
			heap[last]=NULL;
			last=last-1;;
			if(last>0){
				deletion_heap(root);
			}
		}
	}
    void print(){
    	cout << "IS0_Code"
             << "\t"
             << "Economic_Index"
             << "\t"
             << "Rank"
             << "\t"
             << "Quartile"
             << "\t"
             << "Size_of_Gov"
             << "\t"
             << "Legal_Rights"
             << "\t"
             << "Sound_Money"
             << "\t"
             << "Trade_Freedom"
             << "\t"
             << "Regulation" << endl;
        for (int i = 0; i <= last; i++)
        {
            cout << heap[i]->iso << "\t        " << heap[i]->economicIndex << "\t        " << heap[i]->rank << "\t" << heap[i]->quartile << "\t        " << heap[i]->sizeGov << "\t        " << heap[i]->legalRights << "\t        " << heap[i]->soundMoney << "\t        " << heap[i]->trade << "\t        " << heap[i]->regulation << endl;
        }
        cout << endl;
    
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

        // adding data to linked list
        if (lines != 0)
        {
            insert(lineData[0], lineData[1], economicIndex, rank, quartile, sizeGov, legalRights, soundMoney, trade, regulation);
        }
        // clearing vector
        lineData.clear();
        lines++;
    }
    int opt;
    do{
    	cout<<"Press 1 to print the heap"<<endl;
    	cout<<"Press 2 to delete element"<<endl;
    	cout<<"Press 0 to exit"<<endl;
    	cout<<"Enter option: "<<endl;
    	cin>>opt;
    	switch(opt){
    		case 1:
    			print();
    			break;
    		case 2:
				deletion_heap_final();
				break;	
		}
	}while(opt!=0);

    return 0;

}


