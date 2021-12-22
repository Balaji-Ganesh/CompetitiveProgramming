"""
*
MotorSport Ltd hosting a Racing Championship. 
Ajith is participating in car races. Each race start and end in perticular time
intervals.

You are given an array of racing time intervals consisting of
start and end times [[s1,e1],[s2,e2],...] (s < e ) of N races, in which Ajith 
has to participate.
Your task is to determine whether Ajith can participate in all the races or not.
 
NOTE: If a race starts at time 'a' ends at time 'b', 
another race can start at 'b'.
 
Input Format:
-------------
Line-1: An integer N, number of races Ajith has to participate.
Next N lines: Two space separated integers, start and end time of each race.
 
Output Format:
--------------
Print a boolean value.
 
 
Sample Input-1:
---------------
3
0 30
5 10
15 20
 
Sample Output-1:
----------------
false
 
Sample Input-2:
--------------
3
0 15
15 25
30 35
 
Sample Output-2:
----------------
true
*/

"""

def canAttendAllMeetings(meetings):
    meetings = sorted(meetings)     # sorts tuples, based on 1st value (start)
    #print(*meetings)
    prevStart, prevEnd = meetings[0]
    
    for i in range(1, len(meetings)):
        newStart, newEnd = meetings[i];
        if newStart < prevEnd:
            return False;
        prevStart, prevEnd = newStart, newEnd   # Get ready for next meeting turn..
    return True;
    
def main():
    numMeetings = int(input())
    
    meetings = []
    for i in range(numMeetings):
        start, end = map(int, input().split())
        meetings.append((start, end));
      
    if canAttendAllMeetings(meetings):
        print("true");
    else:
        print("false");

main();
