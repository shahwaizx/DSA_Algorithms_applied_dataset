#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <istream>
#include <fstream>
using namespace std;

struct Eco
{
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
Eco *arr[165];
void display(int length)
{
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
    for (int i = 1; i <= length; i++)
    {
        cout << arr[i]->iso << "\t        " << arr[i]->economicIndex << "\t        " << arr[i]->rank << "\t" << arr[i]->quartile << "\t        " << arr[i]->sizeGov << "\t        " << arr[i]->legalRights << "\t        " << arr[i]->soundMoney << "\t        " << arr[i]->trade << "\t        " << arr[i]->regulation << endl;
    }
    cout << endl;
}
void merging( int start, int end, int mid)
{
    int firstA = start;
    int lastA = mid;
    int firstB = mid + 1;
    int lastB = end;
    int index = firstA;
    Eco *temp[165];
    while (firstA <= lastA && firstB <= lastB)
    {
        if (arr[firstA]->rank < arr[firstB]->rank)
        {
            temp[index] = arr[firstA];
            firstA++;
        }
        else
        {
            temp[index] = arr[firstB];
            firstB++;
        }
        index++;
    }
    while (firstA <= lastA)
    {
        temp[index] = arr[firstA];
        firstA++;
        index++;
    }
    while (firstB <= lastB)
    {
        temp[index] = arr[firstB];
        firstB++;
        index++;
    }
    int index1 = start;
    while (index1 <= end)
    {
        arr[index1] = temp[index1];
        index1++;
    }
}
void merge_sort(int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        merge_sort(start, mid);
        merge_sort(mid + 1, end);
        merging(start, end, mid);
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

        // adding data to array
        if (lines != 0)
        {
        	arr[lines] = new Eco();
            arr[lines]->iso = lineData[0];
			arr[lines]->country = lineData[1];
			arr[lines]->economicIndex = economicIndex;
			arr[lines]->rank = rank;
			arr[lines]->quartile = quartile;
			arr[lines]->sizeGov = sizeGov;
			arr[lines]->legalRights = legalRights;
			arr[lines]->soundMoney = soundMoney;
			arr[lines]->trade = trade;
			arr[lines]->regulation = regulation;
        }
        // clearing vector
        lineData.clear();
        lines++;
    }
    int length = sizeof(arr) / sizeof(arr[0]);
         int opt;
    do{
    	cout<<"Press 1 to print the unsorted data"<<endl;
    	cout<<"Press 2 to print the sorted data"<<endl;
    	cout<<"Press 0 to exit"<<endl;
    	cout<<"Enter option: "<<endl;
    	cin>>opt;
    	switch(opt){
    		case 1:
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
   			 display(length);
    			
    			break;
    		case 2:
    			merge_sort(1,length-1);
    			display(length);
				break;
					
		}
	}while(opt!=0);

    return 0;
}
