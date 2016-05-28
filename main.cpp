#include<iostream>
#include"trie.cpp"
using namespace std; 

int main()

{


	node* myRoot=generateTrie("test.txt");

	string str ;
	while(strcmp(str.c_str(),"QUIT"))
	{
		cout<<"Enter the word to search : ";
		getline(cin,str);	
		autocomplete(str,myRoot);	
	}
	

	return 0 ; 

}