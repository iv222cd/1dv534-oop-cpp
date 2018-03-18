// miserable.cpp

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
int i, a=1;
double t, s, m;
char b;

cout << "\n\nTemperature Statistics\n----------------------\n\nReading logged values for processing and presentation...\n\nPress Enter for menu: ";
cin.get();

while(a)
{
system("cls");
cout<<"\n\nMENU\n----\n\n1. Display temperature values\n2. View maximum and minimum temperatures\n3. View average temperature\n4. Quit\n\nMake your choice: ";
cin.get(b);
cin.get();

if(b=='1')
{
cout<<"\nDisplaying the latest 24 temperature values:\n\n";
ifstream fil("templog.txt"); 	
for(i=0;i<24;i++)
{
if(i%6==0)
	cout<<endl;
fil>>t;
cout<<fixed<<setprecision(2)<<setw(8)<<t;
}
fil.close();
}

else if(b=='2')
{
cout<<"\nCalculating the maximum and minimum temperature...\n";
double max=0, min=0;
ifstream fil("templog.txt");	
fil>>t;
max=min=t;
for(i=1;i<24;i++)
{
fil>>t;
if(t>max)
	max=t;
if(t<min)
	min=t;
}
fil.close();
cout<<"\nMaximum temperature: "<<fixed<<setprecision(2)<<max<<" degrees Celcius\n";
cout<<"\nMinimum temperature: "<<min<<" degrees Celcius\n";
}

else if(b=='3')
{
cout<<"\nCalculating average temperature...\n";
s=0.0;
ifstream fil("templog.txt");
for(i=0;i<24;i++)
{
fil>>t;
s+=t;
}
fil.close();
m=s/24;
cout<<"\nAverage temperature: ";
cout<<fixed<<setprecision(2)<<m<<" degrees Celcius\n";
}

else
{
a=0;
cout << "\n\nTerminating the program.";
}
cout<<"\n\nPress Enter to continue:";
cin.get();
}
return 0;
}

