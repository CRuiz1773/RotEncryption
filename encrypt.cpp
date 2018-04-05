#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int menu();
void executeChoice(int choice,vector<string>& o,string file);
void convert(string& s);
void printEncryptRot(vector<string>& o, string file);
void printDecryptRot(vector<string>& o, string file);
string getFile(); //Takes in the file name from the user
vector<string> getInfo(string file);//Places orignal text into a vector
void rotEncrypt(int key,vector<string>& o);//Encrypts using rot method
void rotDecrypt(int key,vector<string>& o);//Decrypts using rot method

int main()
{
  vector<string> original;
  vector<string> encRot;
  vector<string> encCrypt;
  string file = getFile(); //File the user wants to be encrypted or decrypted
  original = getInfo(file);//Original.txt
  int choice = menu();
  executeChoice(choice,original,file);
  
  return 0;
}

int menu()
{
  int choice;
  cout<<"Enter 0 for rot encryption"<<endl
      <<"Enter 1 for rot decryption"<<endl
      <<"Your choice: ";
  cin>>choice;
  return choice;
}

void executeChoice(int choice,vector<string>& o,string file)
{
  int key;
  string crypto;
  switch(choice)
    {
    case 0:
      cout<<"Please enter a key for your rotation: ";
      cin>>key;
      rotEncrypt(key,o);
      printEncryptRot(o, file);
      cout<<"Your file has been encrypted"<<endl;
      break;
    case 1:
      cout<<"Please enter a key for your decryption: ";
      cin>>key;
      rotDecrypt(key,o);
      printDecryptRot(o,file);
      cout<<"Your file has been decrypted"<<endl;
      break;
    }
}

string getFile()
{
  string file;
  cout<<"Enter the file to be encrypted (Format: file.txt): ";
  cin>>file;
  return file;
}

vector<string> getInfo(string file)
{
  string s;
  vector<string> o;
  ifstream fin;
  fin.open(file, ios::in);
  if(!fin)
    cout<<"There was an error opening the file"<<endl
	<<"Make sure the file is in the same folder as the program"<<endl;
  fin>>s;
  while(fin)
    {
      convert(s);
      o.push_back(s);
      fin>>s;
    }
  fin.close();
  
  return o;
}

void convert(string& s)
{
  
  for(int i = 0; i < s.size();i++)
      s[i] = tolower(s[i]);
     
}

void printDecryptRot(vector<string>& o, string file)
{
  ofstream fout;
  fout.open(file);
  for(int i = 0;i < o.size();i++)
    {
      fout<<o[i]<<" ";
    }
  fout.close();
 
}


void rotEncrypt(int key,vector<string>& o)
{
  string s;
  int newchar;
  for(int i = 0;i < o.size(); i++) 
    {
      s = o[i];
      for(int j = 0;j < s.size();j++)
	{
	  if(s[j] == '?' || s[j] == '.' || s[j] == ',' || s[j] == '!' || s[j] == ';' || s[j] == ':')
	    break;
	  s[j] += key;
	  if(s[j] > 'z')
	    s[j] -= 26;
	}
      o[i] = s;
    }
}

void rotDecrypt(int key,vector<string>& o)
{
  string s;
  int newchar;
  char x;
  for(int i = 0;i < o.size();i++)
    {
      s = o[i];
      for(int j = 0;j < s.size();j++)
	{
	  x = s[j];
	  if(s[j] == '?' || s[j] == '.' || s[j] == ',' || s[j] == '!' || s[j] == ';' || s[j] == ':')
	      break;
	  s[j] -= key;
	  if(s[j] < 'a')
	    s[j] += 26;
	}
      o[i] = s; 
    }

}

void printEncryptRot(vector<string>& o, string file)
{
   
  ofstream fout;
  fout.open(file);
  for(int i = 0;i < o.size();i++)
    {
      fout<<o[i]<<" ";
    }
  fout.close();
}
