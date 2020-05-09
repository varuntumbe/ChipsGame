#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<iomanip>
#define ll long long
using namespace std;
class chipsGame
{
	ll r,c;
	vector< vector<char> > dp;
public :
	
	chipsGame()
	{
		r=10;
		c=10;
		dp.resize(r);
		for(ll i=0;i<r;i++)
		{
			dp[i].resize(c);
		}
		precomputeBoard();
	}
	// precomputing all the possibility and storing in matrix
	void precomputeBoard()
	{
		for(ll i=0;i<r;i++)
		{
			if(i%2==1)
			{
				dp[i][0]='w';
				dp[0][i]='w';
			}
			else
			{
				dp[i][0]='l';
				dp[0][i]='l';
			}
		}
	
		for(ll i=1;i<c;i++)
		{
			for(ll j=1;j<r;j++)
			{
				if(dp[j][i-1]=='l'||dp[j-1][i]=='l'||dp[j-1][i-1]=='l')
				{
					dp[j][i]='w';
				}
				else
					dp[j][i]='l';
			}
		}
	}
	// printing the board;
	void printBoard()
	{
		cout<<endl;
		for(ll i=0;i<r;i++)
		{
			for(ll j=0;j<c;j++)
			{
				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	
	
	pair<ll,ll> computerLogic(ll r,ll c)
	{
		pair<ll,ll> result;
		if((c-1)>=0&&dp[r][c-1]=='l')
		{
			cout<<"Computer has chosen one from right"<<endl;
			result=make_pair(r,c-1);
		}
		else
		if((r-1)>=0&&dp[r-1][c]=='l')
		{
			cout<<"Computer has chosen one from left"<<endl;
			result=make_pair(r-1,c);
		}
		else
		if((r-1)>=0&&(c-1)>=0&&dp[r-1][c-1]=='l')
		{
			cout<<"Computer has chosen from both"<<endl;
			result=make_pair(r-1,c-1);
		}
		return result;
	}
	
	void chipsGraphic(ll left,ll right)
	{
		cout<<"Quantity of chips in containers "<<endl;
		cout<<"Left : ";
		for(ll i=0;i<left;i++)
		{
			cout<<setw(2)<<"0  ";
		}
		cout<<"   Right : ";
		for(ll i=0;i<right;i++)
		{
			cout<<setw(2)<<"0  ";
		}
		cout<<"\n \n";
	}
	
	void gameutil(ll row,ll col,string c)
	{
		ll nrow,ncol;
		string choice;
		pair<ll,ll> temp;
		if(row==0&&col==0)
		{
			//base case
			if(c=="player")
			{
				cout<<"Computer wins the game"<<endl;
			}
			else
			{
				cout<<"Player wins the game"<<endl;
			}
			return;
		}
		
		cout<<"Current Status of chips in piles"<<endl;
		cout<<"Chips left in left pile : "<<row<<"  chips left in right pile : "<<col<<endl;
		chipsGraphic(row,col);
		cout<<"\n \n \n";
		
		if(c=="computer")
		{
			temp=computerLogic(row,col);
			nrow=temp.first;
			ncol=temp.second;
			gameutil(nrow,ncol,"player");
		}
		
		if(c=="player")
		{
			cout<<" You have three options : "<<endl;
			cout<<" 1. To Take one from left pile enter 'left' "<<endl;
			cout<<" 2. To Take one from right pile enter 'right' "<<endl;
			cout<<" 3. To Take one from both pile enter 'both' "<<endl;
			
			//screening
			while(1)
			{
				cout<<" Enter your choice here : "<<endl;
				cout<<"\t";
				cin>>choice;
				cout<<"\n\n";
				if(choice=="left")
				{
					if(row-1>=0)
					{
						break;
					}
					else
					{
						cout<<"You cant choose this option :( Choose again"<<endl;
					}
				}
				else
				if(choice=="right")
				{
					if(col-1>=0)
					{
						break;
					}
					else
					{
						cout<<"You cant choose this option :( choose again"<<endl;
					}
				}
				else
				if(choice=="both")
				{
					if((row-1)>=0&&(col-1)>=0)
					{
						break;
					}
					else
					{
						cout<<"You cant choose this option :( Choose again"<<endl;
					}
				}
				else
				cout<<"Invalid input Enter again"<<endl;
			}
			
			
			if(choice=="left")
			{
			    gameutil(row-1,col,"computer");
			}
			
			if(choice=="right") 
			{
			    gameutil(row,col-1,"computer");
					
			}
			if(choice=="both")
			{
				gameutil(row-1,col-1,"computer");
			}
			
		}
	}
    
    void game()
    {
    	cout<<"Welcome to the chipsGame!!"<<endl;
    	cout<<"Short description about game "<<endl;
    	cout<<"(1) There will be two container each having 9 chips"<<endl;
    	cout<<"(2) The game will be played between Grandmaster computer and you"<<endl;
    	cout<<"(3) In each turn you can choose 1 chips from left or one from right or one from both"<<endl;
    	cout<<"(4) Contestant who takes last chips from container wins the game"<<endl;
    	cout<<"(5) There is no turn back, prepare and play!!"<<endl;
    	cout<<"(6) Computer starts the game with its 1st turn"<<endl;
    	cout<<"\n \n \n";
    	gameutil(r-1,c-1,"computer");
	}
};
int main()
{
    chipsGame g;
    g.game();
	return 0;
}
