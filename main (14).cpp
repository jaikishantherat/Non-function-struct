/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


#include <iostream>

using namespace std;
const int SIZE=12;

//structure
struct yearly 
{
    string month;
    int rainfall_total;
    int low_temp;
    int high_temp;
    int avg_temp;
    
};


int main()
{
    
    yearly weatherinfo[SIZE];
    for (int i=0;i<SIZE;i++)
    {   //collects the input to populate the array.
        cout<<"What month is it?\n";
        cin>>weatherinfo[i].month;
        
        cout<<"How much rain fall did you have?\n";
        cin>>weatherinfo[i].rainfall_total;
        
        cout<<"what was the highest temp for the month?\n";
        cin>>weatherinfo[i].high_temp;
        //input validation
        while (weatherinfo[i].high_temp<-100 || weatherinfo[i].high_temp>140 )
            {
                cout<<"invalid input!!! please enter a valid input ranging from -100 to 140 degrees Fahrenheit";
                cin>>weatherinfo[i].high_temp;
            }
        
        
        cout<<"what was the lowest temp for the month?\n";
        cin>>weatherinfo[i].low_temp;
        //input validation
        while (weatherinfo[i].low_temp<-100 || weatherinfo[i].low_temp>140 )
            {
                cout<<"invalid input!!! please enter a valid input ranging from -100 to 140 degrees Fahrenheit";
                cin>>weatherinfo[i].low_temp;
            }

    }
    
    int totalRainPerYear=0;
    double avgrainfall=0;
    double yearlyAve = 0;
     for (int x=0;x<SIZE;x++) 
       {
         
         //Calculates the monthly avg tempratures.
         weatherinfo[x].avg_temp=(weatherinfo[x].low_temp+weatherinfo[x].high_temp)/2;
         
         yearlyAve = yearlyAve + weatherinfo[x].avg_temp;
         
         //adds up the total amount of inches the rain had every month
         totalRainPerYear= totalRainPerYear + weatherinfo[x].rainfall_total;
      
        cout<<"the avg temp for "<<weatherinfo[x].month<<" is " <<weatherinfo[x].avg_temp<<"\n";
       }
    
    //this displays the highest temp of the month along with what month it occured in 
    int tempHighest=0;
    int index;
    
     for(int a=0;a<SIZE;a++)
     {
         if(a == 0) 
         {
           tempHighest = weatherinfo[a].high_temp;
           index=a;
         }
         else if((a != 0) && (tempHighest < weatherinfo[a].high_temp))
        {
            tempHighest = weatherinfo[a].high_temp;
            index=a;
        }
     }
     //this displays the lowest temp of the month along with what month it occured in 
    int templowest=0;
    int index_1;
    
     for(int a=0;a<SIZE;a++)
     {
         if(a == 0) 
         {
           templowest = weatherinfo[a].low_temp;
           index_1 = a;
         }
         else if((a != 0) && (templowest > weatherinfo[a].low_temp))
        {
            templowest = weatherinfo[a].low_temp;
            index_1 = a;
        }
    }
     
    
      //yearly avg calculations
      yearlyAve = yearlyAve / SIZE;
      avgrainfall= totalRainPerYear / SIZE;
      

     
      
      //displays the outputs
      cout<<"the yearly avg temprature is "<<yearlyAve<<"\n";
      cout<<"the highest temprature of the year  "<<weatherinfo[index].high_temp<<" from the month "<<weatherinfo[index].month<<"\n";
      cout<<"the lowest temprature of the year " <<weatherinfo[index_1].low_temp<< " from the month " <<weatherinfo[index_1].month<< "\n";
      cout<<"the total rainfall this year is "<<totalRainPerYear<<"\n";
      cout<<"the avg rainfall this year was " <<avgrainfall<< "\n";
      
    return 0;


}
