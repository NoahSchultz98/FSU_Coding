#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{

   double projects = 0.35;
   double quiz = .4;
   double final = .2;
   double participation = .05;
   double result = 0;
   double input = 0;
   
   cout << "Enter Projects grade:" << endl;
   cin >> input;
   
   result += projects * (input/100);
   
   cout << "Enter Quiz grade:" << endl;
   cin >> input;
   
   result += quiz * (input/100);
   
   cout << "Enter Final Exam grade:" << endl;
   cin >> input;
   
   result += final * (input/100);
   
   cout << "Enter Participation grade:" << endl;
   cin >> input;
   
   result += participation * (input/100);
   
   cout << endl << "Your Grade is:" 
   << endl << (result * 100) << "%";
   
   //cout

}