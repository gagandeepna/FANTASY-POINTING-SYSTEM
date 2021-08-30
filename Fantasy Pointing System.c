//C Program for calculating Fantasy Points for a Cricketer for a T20 Tournament//

#include<stdio.h>
int main()
{   
    //Display Fantasy Pointing Rules//
	printf("T20 Cricket Fantasy Points Calculating System for a Player");
    printf("\n__________________________________________");
    printf("\nFantasy Pointing System for an individual player");
    printf("\n\nIf the Cricketer is playing the match:\n\tPlaying Bonus = +4 points");
    printf("\n\n Batting:\n\tRuns = +1 points\n\tFour Bonus = +1 points\n\tSix Bonus = +2 points\n\tHalf Century Bonus = +8 points\n\tCentury Bonus = +16 points\n\tOut for a duck(Except Bowlers) = -4 points");
    printf("\n\n Bowling:\n\tWickets = +25 ponts\n\tBowled/LBW Bonus = +12 points\n\tLBW Bonus = +12 points\n\tMaiden Over Bonus = +8 points\n\t3 Wicket Haul Bonus = +6 ponts\n\t4 Wicket Haul Bonus = +8 points\n\t5 Wicket Haul Bonus = +12 ponits\n\t5+ Wicket Haul Bonus = +16 points");
    printf("\n\n Fielding:\n\tCatch = +12 ponits\n\tStumping = +12 ponts\n\tDirct Hit Runout = +15 points\n\tAssist for Runout = +10 points\n\tCompleting a Runout = +5 points");
    printf("\n\n Strike Rate (Except Bowlers and Minimum of 10 balls to be played):\n\t<=50.00 = -6 points\n\t50.01 - 60.00 = -4 points\n\t60.01 - 70.00 = -2 points");
    printf("\n\n Economy Rate (Minimum of 2 overs to be bowled):\n\t<=3.00 = +8 points\n\t3.01 - 4.00 = +6 points\n\t4.01 - 5.00 = +4 points\n\t5.01 - 6.00 = +2 points\n\t9.00 - 9.99 = -2 points\n\t10.00 - 10.99 = -4 points\n\t11.00 - 11.99 = -6 points\n\t>=12.00 = -8 points");
    printf("\n__________________________________________");
    
	 
    char name[50],Tournament[50];
    printf("\n\nEnter the T20 Tournament name:");
    scanf("%s",&Tournament);
    printf("\n\nEnter the Cricket's name: ");
    scanf("%s",&name);
    
    
	int i,n,role,Tournament_points=0;
    printf("\nEnter '1' if %s is a 'batsman', Enter '2' if %s is an 'all-ronder' or Enter '3' if %s is a 'bowler':",name,name,name);
    scanf("%d",&role);
    printf("\nEnter the number of matches in the tournament: ");
    scanf("%d",&n);
    
    
	//File Appending//
	FILE *fptr;
    fptr=(fopen("fantasy_points.txt","a"));
    fprintf(fptr,"\n\%s\n\n\tCrickter's Name: %s",Tournament,name);
    
    switch (role)
    {
    	case 1: fprintf(fptr,"(Batsman)");
    	break;
    	case 2: fprintf(fptr,"(All-rounder)");
    	break;
    	case 3: fprintf(fptr,"(Bowler)");
    	break;
	}
	
	fprintf(fptr,"\n\tFantasy Points:");
	
	
	//Running the for loop for n = no. of matches//
	for(i=1;i<=n;++i)
	{  
    	int playing_or_not,Final_total;
    	Final_total=0;
    	printf("\n\nEnter '1' if %s is playing or Enter '0' if %s is not playing in the match number %d: ", name, name,i);
    	scanf("%d",&playing_or_not);
    
    	if(playing_or_not == 1)
		{	
        
        	if(role==1 || role == 2 || role == 3)
        	{   
            	int batted;
            	printf("\nEnter '1' if %s got a chance to bat or enter '0' if %s did not get any chance to bat in match number %d: ",name,name,i);
            	scanf("%d",&batted);
         
		    	if(batted==1 || batted==0)
            	{  
					int  fours, sixes, total, Grand_total, Batting_total, wickets, bowled_and_LBW, maidens, Bowling_total, catches, 
					     stumpings, direct_hit_runouts, assists, completions;
            		float runs, balls, overs, runs_given, strike_rate, economy;
                    
                    //Input Batting Stats//
					printf("\n\nEnter the number of runs scored by %s in match number %d: ",name,i); 
        	    	scanf("%f",&runs);
           
			    	printf("\n Enter the number of balls faced by %s in match number %d: ",name,i);
        	    	scanf("%f",&balls);
           
		    		printf("\n Enter the number of fours hit by %s in match number %d: ",name,i);
            		scanf("%d",&fours);
           
		    		printf("\n Enter the number of sixes hit by %s in match number %d: ",name,i);
            		scanf("%d",&sixes);
        
                    //Input Bowling Stats//
		    		printf("\n Enter the number of overs bowled by %s in match number %d: ",name,i);
            		scanf("%f",&overs);
            
					printf("\n Enter the number of runs given by %s in match number %d: ",name,i);
            		scanf("%f",&runs_given);
            
					printf("\n Enter the number of wickets taken by %s in match number %d: ",name,i);
        	    	scanf("%d",&wickets);
           
		    		printf("\n Enter the number of wickets taken by %s by bowleding and LBW combined in match number %d: ",name,i);
            		scanf("%d",&bowled_and_LBW);
          
		    		printf("\n Enter the number of maiden overs bowled by %s in match number %d: ",name,i);
            		scanf("%d",&maidens);
       				
       				//Input Fielding Stats//
		    		printf("\n Enter the number of catches taken by %s in match number %d: ",name,i);
            		scanf("%d",&catches);
           
		    		printf("\n Enter the number of stumpings done by %s in match number %d: ",name,i);
            		scanf("%d",&stumpings);
          
		    		printf("\n Enter the number of direct hit run-outs effected by %s in match number %d: ",name,i);
            		scanf("%d",&direct_hit_runouts);
          
		    		printf("\n Enter the number of assists by %s for runouts in match number %d: ",name,i);
            		scanf("%d",&assists);
           
		    		printf("\n Enter the number of runouts completed by %s after assist from other players in match number %d: ",name,i);
            		scanf("%d",&completions);
                    
                    //Checking if the Inputs are as per ICC T20I Rules//
                	if(runs>=0 && balls>=0 && fours>=0 && sixes>=0 && overs>=0 && runs_given>=0 && wickets>=0 && bowled_and_LBW>=0 && maidens>=0
                     	&& catches>=0 && stumpings>=0 && direct_hit_runouts>=0 && assists>=0 && completions>=0 && (runs>=((4*fours)+(6*sixes)))
                   		&& (balls>=(fours)+(sixes)) && overs<=4 && wickets<=10 && bowled_and_LBW<=wickets && maidens<=overs && ((wickets)+(catches)+
				  		(stumpings)+(direct_hit_runouts)+(assists)+(completions))<=10 && (((stumpings)+(direct_hit_runouts)+(assists)+
						(completions))<=(10-wickets)))
                    
                	{
                		//Strike Rate Calculation//
                  	    if(balls==0)
                  	    { 
                      		strike_rate = 0;
                	    } 
                	    else
                	    {
               	            strike_rate = (runs/balls)*100;
                	    } 
                        
                        //Economy Rate Calculation//
                	    if(overs==0)
                	    { 
                	        economy = 0;
                	    }
                	    else
                	    {
                	        economy = runs_given/overs;
                	    } 
              
              
                        //Fantasy Points Calculation for this match//
                		total = 4+runs+fours+(2*sixes)+(25*wickets)+(12*bowled_and_LBW)+(8*maidens)+(12*catches)
					    	    +(12*stumpings)+(15*direct_hit_runouts)+(10*assists)+(5*completions);
                
               
                    	if(role==1||role==2)
                    	{
                    	   switch (batted)
                    	    { 
                    	        case 0: Grand_total = total - runs - fours - (2*sixes);
                   	        	break;
                    	        case 1: if(balls>=10 && strike_rate<=50)
                                    	{  
                                    	    Grand_total = total-6;
                                    	}
                                    	else if(balls>=10 && strike_rate<=60)
                                    	{   
                                    	    Grand_total = total-4;
                                    	}
                                    	else if(balls>=10 && strike_rate<=70)
                                    	{  
                                    	    Grand_total = total-2;
                                    	}
                                    	else
                                    	{
                                    	    Grand_total = total;
                                    	}
                            	break;
                            	default: printf("Error"); 
                            	break;
                        	}
                    	}
                    	else if(role==3)
                    	{
                    	    Grand_total = total;
                    	}

                        if(batted==1 &&(role==1||role==2) && runs==0)
                        {
                        	Grand_total = total - 4;
						}
						else
						{
							Grand_total = total;
						}
						
            
                    	if (runs>=50 && runs<100)
                    	{   
                    	    Batting_total = Grand_total+8;
                    	} 
                    	else if(runs>=100)
                    	{    
                    	    Batting_total = Grand_total+16;
                    	}
                    	else
                    	{   
                    	    Batting_total = Grand_total;
                    	}
                    	if(overs>=2 && economy>0 && economy<=3)
                    	{
                    	    Bowling_total = Batting_total+8;
                    	} 
                    	else if(overs>=2 && economy<=4)
                    	{  
                    	    Bowling_total = Batting_total+6;
                    	} 
                    	else if(overs>=2 && economy<=5)
                    	{
                    	    Bowling_total = Batting_total+4;
                    	}
                    	else if(overs>=2 && economy<=6)
                    	{
                    	    Bowling_total = Batting_total+2;
                    	}
                    	else if(overs>=2 && economy>=9 && economy<10)
                    	{   
                    	    Bowling_total = Batting_total-2;
                    	}
                    	else if(overs>=2 && economy>=10 && economy<11)
                    	{
                    	    Bowling_total = Batting_total-4;
                    	}
                    	else if(overs>=2 && economy>=11 && economy<12)
                    	{
                    	    Bowling_total = Batting_total-6;
                    	}
                    	else if(overs>=2 && economy>=12)
                    	{
                    	    Bowling_total = Batting_total-8;
                    	}
                    	else 
                    	{
                    	    Bowling_total = Batting_total;
                    	}
                    	if(wickets<3)    
                    	{
                    	    Final_total = Bowling_total;
                    	}
                    	else if(wickets==3)
                    	{
                    	    Final_total = Bowling_total+6;
                    	}
                    	else if(wickets==4)
                    	{
                    	    Final_total = Bowling_total+8;
                    	}
                    	else if(wickets==5)
                    	{
                    	    Final_total = Bowling_total+12;
                    	}
                    	else if(wickets>5)
                    	{
                    	    Final_total = Bowling_total+16;
                    	}
                    	
                    	//Display Strike Rate, Economy Rate and Total Fantasy Points in this match//
                    	printf("\n Strike Rate of %s is %f ",name,strike_rate);
                    	printf("\n Economy rate of %s is %f",name,economy);
                    	printf("\n\n The total Fantasy Points of %s in match number %d is:  %d", name,i, Final_total);
                	} 
		        	else
                	{
                	    printf("Error");
                	}
           
                }
            
        	}
        	else 
        	{
        	    printf("Error");
            }
        
    	}
            
    
    	else if(playing_or_not == 0)
    	{
    	    printf("\n The total Fantasy Points of %s in match number %d is = 0", name,i); 
    	}
    	else 
    	{
    	    printf("Error");
    	}
    	
    	printf("\n______________________________________________________________\n\n");
		fprintf(fptr,"\n\t\tMatch %d: %d\n",i,Final_total);
		Tournament_points += Final_total;    //Total Fantasy Points Calculation for this Tournament//
	} 
	
	//Display Total Fantasy Points in this Tournament//
	printf("\n\nTotal Fantasy Points of %s in the tournament is = %d",name,Tournament_points);
	fprintf(fptr,"\n\tTournament Points: %d\n",Tournament_points);
	fclose(fptr);
	return 0;
}
