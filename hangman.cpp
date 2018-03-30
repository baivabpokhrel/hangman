//============================================================================
// Name        : BPokhrel2.cpp
// Author      : Baivab Pokhrel
// Version     :
// Copyright   : Your copyright notice
// Description : Hangman
//============================================================================

#include <iostream>
#include<cstdlib>
#include<ctime>
#include <vector>
#include <string>
using namespace std;

string getSecretWord(const vector<string>&); //initializing the function which calls for secret word

int main()
{
    cout<<"You are about to play Hangman\n";
    cout<<"You will see an underscore in place of every letter within the word\n";
	cout<<"You win if you guess the word, within\n";
	cout<<"maximum guesses equal to 2 times the letters within the word or a minimum of ten, which ever is larger \n";
    cout<<"and a time limit of 7 seconds times the letters within the word or a minimum of 40 seconds, which ever is";
    cout<< "larger\n\n";//description of the game
	vector<string> wlist ={"variable",
                           "function","object","expression","plus","pattern","module",
					       "debug","integrated","development","environment","virtual","input",
					       "shift","constructor","destructor","syntax","iterate","procedure",
                           "compiler" };// vector that stores all the secret words
    
	string answer;//initializing string to store answer yes or no at the end
    
	do//first do-while loop that goes aroud the whole program and runs again if answer is yes
        
		{
		int tries=1;//to keep track of number of entries
	    
        char input_char=' ';//char to store the character that is inputted
            
	    string char_record="";//string to add all the inputts charcter and show if re-entered
            
        string new_char="";//string to store new char after the input replaces the underscore
            
		string underscores="";//to print the underscores as same length of the secret word
            
		int time1=0; // int to keep track of the time elapsed
            
		string SecretWord= getSecretWord(wlist);//to call the fuction and get the secrte word
            
		for(int i=0; i<(SecretWord.length());i++)// loop to display underscores, length same as secret word
					{
					  underscores = underscores + "_ ";
					}
       cout<<underscores<<endl;//to display number of underscores same as the number of characters in a secret word

        for(int j=0;;j++)//infinite loop for the input with brek statement below
		{
             int  timer1=time(0);//timer number 1 which starts at the beginning of loop
            cout<<"Enter a letter: ";
            cin>>input_char; //to store the input character
            
			
            for(int i=0; i<char_record.length();i++)// to check if the inputted word was already previously inputted
			{
				if(input_char==char_record[i])
                { cout<<input_char<<" is one of previously guessed letters:"<<char_record<<endl;
                  tries--;
                  break;
                }
                
                
            }
			
            for(int j=0;j<SecretWord.length();j++)// to replace the underscore with the input if it matches
            {
              
                if (input_char==SecretWord[j])
                    
                   underscores[2*j]=input_char;
                   new_char=underscores;
                
            }
            
            cout<<new_char<<endl;
			int t=0;
			for(int i=0;i<underscores.length()/2;i++)//to see if all the characters are matched
			{
				if(underscores.length()==2*SecretWord.length() && underscores[2*i]==SecretWord[i])
					{t=t+1;}
			}
			   if(t==SecretWord.length())
               {
                   cout<<"Congratulations! You guessed the word in "<< tries <<" tries\n"<<endl;//if they win the round displaying this message
                   break;
               }
            
               if( 2*SecretWord.length()<=10 && tries>=10)//to see if tries exceed 10
                  {
                      cout<<"You exceeded "<<tries<<" tries"<<endl;
                      cout<<"The word was "<<SecretWord<<"\n"<<endl;
                      break;
                  }
            else  if(2*SecretWord.length()>10 && tries>=2*SecretWord.length())// to see if tries exceeds 2 times the word length
                   {
                       cout<<"You exceeded "<<2*SecretWord.length()<<" tries"<<endl;
                       cout<<"The word was "<<SecretWord<<"\n"<<endl;
                      break;
                                                                  
                   }
			    
				
                int  timer2=time(0);
				int seconds=difftime(timer2,timer1);//to find the diffrence in time
				time1=time1+seconds;//total time elapsed
                if( time1 > 40 && 7*SecretWord.length()<40 )// to see is time exceeds 40
					{
						cout<<"You exceeded 40 seconds to guess the word\n";
						cout<<"The word was "<<SecretWord<<endl;
                        break;

					}
                else if(time1>7*SecretWord.length() &&7*SecretWord.length()>40 )//to see if timer exceeds 7 times the word length
					{
						cout<<"You exceeded "<<7*SecretWord.length() <<" seconds to guess the word\n";
					    cout<<"The word was "<<SecretWord<<endl;
                         break;
					 }
            char_record = char_record+input_char;// to add a word to a empty string which is displayed when a character is repeated
            
            tries++;
					   
           

        }
            
         

	       cout<<"Do you want to play again(y/n)? ";// to ask if they want to  play again
			cin>>answer;
				while(answer !="y" && answer!="n")//if the answer is anything except y or n
					{
					   cout<<"Do you want to play again(y/n)? ";
                       cin>>answer;

		             }
		}
	while(answer=="y");// if the answer is y loop it again else it comes out of the loop




	return 0;
}
string getSecretWord(const vector<string>& wlist)// function for getting the secret word
  {
	srand (time(NULL));//to get different words for different trials
	int a = (rand() % wlist.size());//to call a random number between the numbers of words in that vector
	string word= wlist[a];//to get a random string from the vector of strings
	return word;
  }




