#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int menu();
void executeChoice(int choice,vector<string>& o,vector<string>& encRot,vector<string>& encCrypto);
void convert(string& s);
void printEncryptRot(vector<string>& o);
void printDecryptRot(vector<string>& o);
vector<string> setFile();//Places encryptedCrypto file into a vector
vector<string> getInfo();//Places orignal text into a vector
vector<string> setInfo();//places encryptedRot file into vector
void rotEncrypt(int key,vector<string>& o);//Encrypts using rot method
void rotDecrypt(int key,vector<string>& o);//Decrypts using rot method

int main()
{
  vector<string> original;
  vector<string> encRot;
  vector<string> encCrypt;
  original = getInfo();//Original.txt
  encCrypt = setFile(); //EncryptCrypto.txt
  encRot = setInfo();
  int choice = menu();
  executeChoice(choice,original,encRot,encCrypt);
  
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

void executeChoice(int choice,vector<string>& o,vector<string>& encRot,vector<string>& encCrypto)
{
  int key;
  string file;
  string crypto;
  switch(choice)
    {
    case 0:
      cout<<"Please enter a key for your rotation: ";
      cin>>key;
      rotEncrypt(key,o);
      cout<<"Your file has been encrypted"<<endl;
      break;
    case 1:
      cout<<"Please enter a key for your decryption: ";
      cin>>key;
      rotDecrypt(key,encRot);
      cout<<"Your file has been decrypted"<<endl;
      break;
    }
}

vector<string> setFile()
{
   string s;
  vector<string> d;
  ifstream fin;
  fin.open("EncryptCrypto.txt");
  fin>>s;
  while(fin)
    {
      d.push_back(s);
      fin>>s;
    }
  fin.close();
  
  return d;
}

vector<string> getInfo()
{
  string s,file;
  vector<string> o;
  ifstream fin;
  cout<<"Enter the file to be encrypted(Format: Test.txt): ";
  cin>>file;
  fin.open(file);
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

vector<string> setInfo()
{
  string s;
  vector<string> o;
  ifstream fin;
  fin.open("EncryptRot.txt");
  fin>>s;
  while(fin)
    {
      convert(s);
      o.push_back(s);
      fin>>s;
      }
  return o;
}

void convert(string& s)
{
  
  for(int i = 0; i < s.size();i++)
      s[i] = tolower(s[i]);
     
}

void printDecryptRot(vector<string>& o)
{
  ofstream fout;
  fout.open("DecryptRot.txt");
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
	  s[j] += key;
	  if(s[j] > 'z')
	    s[j] -= 26;
	}
      o[i] = s;
    }  
  printEncryptRot(o);
 
}

void rotDecrypt(int key,vector<string>& o)
{
  string s;
  int newchar;
  for(int i = 0;i < o.size();i++)
    {
      s = o[i];
      for(int j = 0;j < s.size();j++)
	{
	   s[j] -= key;
	   if(s[j] < 'a')
	     s[j] += 26; 
	}
      o[i] = s; 
    }
  printDecryptRot(o);
 
}

void printEncryptRot(vector<string>& o)
{
   
  ofstream fout;
  fout.open("EncryptRot.txt");
  for(int i = 0;i < o.size();i++)
    {
      fout<<o[i]<<" ";
    }
  fout.close();
 
}
