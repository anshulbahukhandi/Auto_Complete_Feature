#include<iostream>
#include<cstring>
#include<map>
#include<fstream>
#include<stack>
using namespace std; 

struct node
{
	map<char , node*> myMap;	
	bool flag=false; 
} ;
typedef struct node node;

 node* generateTrie(const string filename)
 {
 	node* root=new node();
 	int count = 0 ; 
 	ifstream fin ; 
 	fin.open(filename.c_str());
 	while(!fin.eof())
 	{
 		string str; 
 		getline( fin , str , ' ' );
 		node* temp = root;
 		map<char , node* > :: iterator it ;
 		for( int i = 0 ; i<str.length()  ; i++)
 		{
 			char ch= str[i]; 
 			it=temp->myMap.find(ch);
 			if(it==temp->myMap.end())
 			{
 				node* newnode=new node();
 				temp->myMap[ch]=newnode;
 			}
 			temp=temp->myMap[ch];
 			if(i==str.length()-1)
 			{
 				temp->flag=true;
 			}
 		}

 		count++;
 	}
 	fin.close();
 	cout<<"Total words in dictionary : "<<count<<endl;
 	return root;
 }


 void print( node* newroot , string str )
 {
 	if(newroot->flag==true)
 		cout<<str<<endl;
 	for( map<char , node* > :: iterator it=newroot->myMap.begin() ; it!=newroot->myMap.end() ; it++)
 	{
 		print(it->second , str+it->first);
 	}
 }

 void autocomplete(string str , node* root)
 {

 	int indexcount=0;
 	node* temp = root ; 
 	map<char , node* > :: iterator it; 
 	for( int i = 0 ; i<str.length() ; i++ )
 	{
 		it=temp->myMap.find(str[i]);
		if(it!=temp->myMap.end())
 			{
 				indexcount++;
 				temp=temp->myMap[str[i]];	
 			}
 	}
 	if(indexcount>0)
 	print(temp , str.substr(0,indexcount) );
 	else
 		cout<<"NO MATCH FOUND!!"<<endl;
 }

 






