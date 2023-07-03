#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;


struct AVL{
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
    AVL *left=NULL;
    AVL *right=NULL;
    int height;
};
AVL *root=NULL;
int maxi(int x1, int x2)
{
    if (x1 > x2)
    {
        return x1;
    }
    else if (x1 < x2)
    {
        return x2;
    }
    return x1;
}
int AVLHeight(AVL *p)
{
    if (p == NULL)
    {
        return 0;
    }
    int left = AVLHeight(p->left);
    int right = AVLHeight(p->right);
    return maxi(left, right) + 1;
}
int BalanceFactor(AVL *p)
{
    return AVLHeight(p->left) - AVLHeight(p->right);
}
AVL *leftRotate(AVL *x)
{
    AVL *y = x->right;
    x->right = y->left;
    y->left = x;
    x->height = maxi(AVLHeight(x->left), AVLHeight(x->right)) + 1;
    y->height = maxi(AVLHeight(y->left), AVLHeight(y->right)) + 1;
    return y;
}
AVL *rightRotate(AVL *x)
{
    AVL *y = x->left;
    x->left = y->right;
    y->right = x;
    x->height = maxi(AVLHeight(x->left), AVLHeight(x->right)) + 1;
    y->height = maxi(AVLHeight(y->left), AVLHeight(y->right)) + 1;
    return y;
}
AVL *newNode(string iso,string country, double economicIndex, int rank, int quartile, double sizeGov, double legalRights, double soundMoney, double trade, double regulation)

{
    AVL *newNode = new AVL();
    
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
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
AVL *insert(AVL *p, string iso,string country, double economicIndex, int rank, int quartile, double sizeGov, double legalRights, double soundMoney, double trade, double regulation)

{
    if (p == NULL)
    {
        return newNode(iso, country,  economicIndex, rank, quartile, sizeGov, legalRights, soundMoney, trade, regulation);
        
    }
    if (rank < p->rank)
    {
        p->left = insert(p->left, iso, country, economicIndex, rank, quartile, sizeGov, legalRights, soundMoney, trade, regulation);
        
    }
    else
    {
        p->right = insert(p->right, iso, country, economicIndex, rank, quartile, sizeGov, legalRights, soundMoney, trade, regulation);
        
    }
    p->height = maxi(AVLHeight(p->left), AVLHeight(p->right)) + 1;
    int balance = BalanceFactor(p);
    if (balance > 1 && rank < p->left->rank)
    {
        return rightRotate(p);
    }
    if (balance < -1 && rank > p->right->rank)
    {
        return leftRotate(p);
    }
    if (balance > 1 && rank > p->left->rank)
    {
        p->left = leftRotate(p->left);
        return rightRotate(p);
    }
    if (balance < -1 && rank < p->right->rank)
    {
        p->right = rightRotate(p->right);
        return leftRotate(p);
    }

    return p;
}
void inorder(AVL *p)
{
    if (p != NULL)
    {
        
        inorder(p->left);
		cout << p->iso << "\t        " << p->economicIndex << "\t        " << p->rank << "\t" << p->quartile << "\t        " << p->sizeGov << "\t        " << p->legalRights << "\t        " << p->soundMoney << "\t        " << p->trade << "\t        " << p->regulation << endl;
		inorder(p->right);
    }
}
bool search(AVL *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->rank == data)
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
    	cout << root->iso << "\t        " << root->economicIndex << "\t        " << root->rank << "\t" << root->quartile << "\t        " << root->sizeGov << "\t        " << root->legalRights << "\t        " << root->soundMoney << "\t        " << root->trade << "\t        " << root->regulation << endl;
        return true;
    }
    if (data > root->rank)
    {
        return search(root->right, data);
    }
    else
    {
        return search(root->left, data);
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

        // adding data to linked list
        if (lines != 0)
        {
            root = insert(root,lineData[0], lineData[1], economicIndex, rank, quartile, sizeGov, legalRights, soundMoney, trade, regulation);
        }
        // clearing vector
        lineData.clear();
        lines++;
    }
   
    
     int opt;
    do{
    	cout<<"Press 1 to print the AVL"<<endl;
    	cout<<"Press 2 to search country(rank)"<<endl;
    	cout << "Press 3 to get height of tree" << endl;
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
   			 inorder(root);
    			
    			break;
    		case 2:
    			int data;
				cout << "Enter rank: " << endl;
				cin >> data;
				search(root,data);

				break;
			case 3:
			int heightTotal=AVLHeight(root);
    		cout<<"The height is: "<<heightTotal<<endl;
    break;
					
		}
	}while(opt!=0);
    return 0;

}


