//  CSE_110_500_Sean_Eriksson_Project_3
//  Meteor Detection System with Missile Intercept

#include <iostream>
#include <cstdlib>


using namespace std;

void data_request(double &meteorSize, double &meteorDistance, bool &canTrackandDetect);

void meteor_data_output(double meteorSize, double meteorSpeed, double timeToImpact, bool canTrackandDetect, double newMeteorDistance, double missleInterceptRange, int &mdsStatus);

void time_to_impact_calculation(double meteorSpeed, double &meteorDistance, double &timeToImpact, double time, double &distanceTraveled, double &newMeteorDistance);

void meteor_speed_calculation (double &meteorSize, double &meteorSpeed);

void missile_intercept_range_calculation (double meteorSpeed, double time, double &missleInterceptRange, double newMeteorDistance);

void mds_status_check (double missleIntereceptRange, int &mdsStatus, double newMeteorDistance, double timeToImpact, double time);



void distance_traveled_calculation(double meteorSpeed, double time, double &distanceTraveled);



int main()
{
    cout.setf(ios::fixed);  // use fixed point
    cout.setf(ios::showpoint);  //display the decimal
    cout.precision(2);  //display two decimal places
    
    double meteorSize = 0, meteorDistance = 0, meteorSpeed = 0, timeToImpact = 99, missleInterceptRange = 0, distanceTraveled = 0,newMeteorDistance = 0;  //set all variables to zero except for time to impact which is set to 99 so the below loop functions
    bool canTrackandDetect = false;  //set canTrackandDetect to false
    int mdsStatus = 1;  //initial status is zero
    double time = 0;  //variable to keep track of time passed

    data_request(meteorSize, meteorDistance, canTrackandDetect);  //request data from user
    meteor_speed_calculation(meteorSize, meteorSpeed);  //perform speed calculation
    cin.get();
    
    while (timeToImpact > 0)
    {
        //cout << "the time is: " << time << endl;
        
        distance_traveled_calculation(meteorSpeed, time, distanceTraveled);
        //cout << "the distance traveled is: " << distanceTraveled << endl;
        
        time_to_impact_calculation(meteorSpeed, meteorDistance, timeToImpact, time, distanceTraveled, newMeteorDistance);  //peform time to impact calculation
        missile_intercept_range_calculation (meteorSpeed, time, missleInterceptRange, newMeteorDistance);  //perform missile intercept calculation
        mds_status_check(missleInterceptRange, mdsStatus, newMeteorDistance, timeToImpact, time);  //perform mds status check
        meteor_data_output(meteorSize, meteorSpeed, timeToImpact, canTrackandDetect, newMeteorDistance, missleInterceptRange, mdsStatus);  //peform data output
        time = time + 1;
        
        cin.get();
        //system("CLS");
    }
    
    return 0;
}


void data_request(double &meteorSize, double &meteorDistance, bool &canTrackandDetect)

{
    //take input from the user
    cout << "Enter the meteor's size in meters: ";
    cin >> meteorSize;
    cout << "Enter the meteor's distance from Earth in miles: ";
    cin >> meteorDistance;
    cout << "" << endl;
    
    
    //check to see if the meteor can be tracked and detected
    if (meteorSize >= 3 && meteorDistance <= 440)
    {
        canTrackandDetect = true;
    }
    
    if (meteorSize >= 2 && meteorDistance <= 330)
    {
        canTrackandDetect = true;
    }
    
    if (meteorSize >= 1 && meteorDistance <= 220)
    {
        canTrackandDetect = true;
    }
    
    if (meteorSize < 1 && meteorDistance <= 110)
    {
        canTrackandDetect = true;
    }
    
}

void meteor_data_output(double meteorSize, double meteorSpeed, double timeToImpact, bool canTrackandDetect, double newMeteorDistance, double missleInterceptRange, int &mdsStatus)
{
    
    if (mdsStatus == 1)
    {
        if (canTrackandDetect == true)
        {
            cout << "Meteor Data: " << endl;
            cout << "   Diameter in meters: " << meteorSize << endl;
            cout << "   Distance from Earth: " << newMeteorDistance << " miles" << endl;
            cout << "   Speed in Miles per hour: " << meteorSpeed << " miles per hour" << endl;
            cout << "   Time to Impact: " << timeToImpact << " Minutes" << endl;
            cout << "" << endl;
        }
        
        else
        {
            cout << "Meteor Data: " << endl;
            cout <<    "Meteor cannot be tracked by the System" << endl;
            cout << "" << endl;
        }
        
        cout << "Engagment Data:" << endl;
        cout <<    "    Missle Intercept Range: " << missleInterceptRange << " Miles" << endl;
        cout <<    "    MDS Status:  Missle Interecept Probable" << endl;
        cout << "Meteor Status:" << endl;
        cout << "   Meteor Inbound" << endl;
        cout << "" << endl;
    }
    
    if (mdsStatus == 2)
    {
        if (newMeteorDistance < 0) newMeteorDistance = missleInterceptRange;
        if (timeToImpact < 0) timeToImpact = 0;
        meteorSpeed = 0;
        
        if (canTrackandDetect == true)
        {
            cout << "Meteor Data: " << endl;
            cout << "   Diameter in meters: " << meteorSize << endl;
            cout << "   Distance from Earth: " << newMeteorDistance << " miles" << endl;
            cout << "   Speed in Miles per hour: " << meteorSpeed << " miles per hour" << endl;
            cout << "   Time to Impact: " << timeToImpact << " Minutes" << endl;
            cout << "" << endl;
        }
        
        else
        {
            cout << "Meteor Data: " << endl;
            cout <<    "Meteor cannot be tracked by the System" << endl;
            cout << "" << endl;
        }
        cout << "Engagment Data:" << endl;
        cout <<    "    Missle Intercept Range: " << missleInterceptRange << " Miles" << endl;
        cout << "    MDS Status:  Missle Interecept Occurred" << endl;
        cout << "Meteor Status:" << endl;
        cout << "    Meteor Destroyed at " << missleInterceptRange << " miles" << endl;
        cout << "" << endl;
    }
    
    if (mdsStatus == 3)
    {
        cout << "Missle intercept range is: " << missleInterceptRange << endl;
        
        if (newMeteorDistance < 0) newMeteorDistance = missleInterceptRange;
        if (timeToImpact < 0) timeToImpact = 0;
        meteorSpeed = 0;
        
        if (canTrackandDetect == true)
        {
            cout << "Meteor Data: " << endl;
            cout << "   Diameter in meters: " << meteorSize << endl;
            cout << "   Distance from Earth: " << newMeteorDistance << " miles" << endl;
            cout << "   Speed in Miles per hour: " << meteorSpeed << " miles per hour" << endl;
            cout << "   Time to Impact: " << timeToImpact << " Minutes" << endl;
            cout << "" << endl;
        }
        
        else
        {
            cout << "Meteor Data: " << endl;
            cout <<    "Meteor cannot be tracked by the System" << endl;
            cout << "" << endl;
        }
        cout << "Engagment Data:" << endl;
        cout << "    Missle Intercept Range: 0.00 Miles" << endl;
        cout << "    MDS Status:  Missle Interecept Not Possible" << endl;
        cout << "    Earth Impact Imminent in " << timeToImpact << " minutes" << endl;
        cout << "Meteor Status:" << endl;
        cout << "    Inbound" << endl;
        cout << "" << endl;
    }
    
    if (mdsStatus == 4)
    {
        cout << "Missle intercept range is: " << missleInterceptRange << endl;
        
        if (newMeteorDistance < 0) newMeteorDistance = missleInterceptRange;
        if (timeToImpact < 0) timeToImpact = 0;
        meteorSpeed = 0;
        
        if (canTrackandDetect == true)
        {
            cout << "Meteor Data: " << endl;
            cout << "   Diameter in meters: " << meteorSize << endl;
            cout << "   Distance from Earth: " << newMeteorDistance << " miles" << endl;
            cout << "   Speed in Miles per hour: " << meteorSpeed << " miles per hour" << endl;
            cout << "   Time to Impact: " << timeToImpact << " Minutes" << endl;
            cout << "" << endl;
        }
        
        else
        {
            cout << "Meteor Data: " << endl;
            cout <<    "Meteor cannot be tracked by the System" << endl;
            cout << "" << endl;
        }
        cout << "Engagment Data:" << endl;
        cout << "    Missle Intercept Range: 0.00 Miles" << endl;
        cout << "    MDS Status:  Missle Interecept Not Possible" << endl;
        cout << "    Earth Impact Imminent in " << timeToImpact << " minutes" << endl;
        cout << "Meteor Status:" << endl;
        cout << "    Earth Impacted" << endl;
        cout << "" << endl;
    }
}

void time_to_impact_calculation(double meteorSpeed, double &meteorDistance, double &timeToImpact, double time, double &distanceTraveled, double &newMeteorDistance)

{
    timeToImpact = ((meteorDistance - distanceTraveled)/(meteorSpeed /60));  //calculate the time to impact
    newMeteorDistance = meteorDistance - distanceTraveled;  //calculate new meteor distance
}

void distance_traveled_calculation(double meteorSpeed, double time, double &distanceTraveled)
{
    distanceTraveled = (meteorSpeed * time) / 60;  //calculate how far the meteor has traveled so far
}

void meteor_speed_calculation (double &meteorSize, double &meteorSpeed)

{
    meteorSpeed = meteorSize * 120;
}

void missile_intercept_range_calculation (double meteorSpeed, double time, double &missleInterceptRange, double newMeteorDistance)
{
    missleInterceptRange = newMeteorDistance - (meteorSpeed * ((3.4-time)/60));
    if (missleInterceptRange <= 0) missleInterceptRange = 0;
}

void mds_status_check (double missleIntereceptRange, int &mdsStatus, double newMeteorDistance, double timeToImpact, double time)
{

    
    if (missleIntereceptRange > 0 && newMeteorDistance > missleIntereceptRange)  //missle intercept range is greater than zero, and meteor distance is greater than missle intercept range
    {
        mdsStatus = 1; //Missle Interecept Probable
    }
    
    if (newMeteorDistance <= missleIntereceptRange)
    {
        mdsStatus = 2; //Missle Interecept Occurred
    }
    
    if (missleIntereceptRange ==  0 && timeToImpact > 0)
    {
        mdsStatus = 3; //Missle Interecept Not Possible
        
        //create sub
    }
    
    if (missleIntereceptRange ==  0 && newMeteorDistance <= 0 && timeToImpact <= 0)
    {
        mdsStatus = 4; //Missle Interecept Not Possible
        
        //create sub
    }
    
}
