"""
/*
Swetha as a Subject teacher conducted a test of MCQ's to the students.
After the test completed, she came to know that some of the students copied the
answers from other students and both obtained the same marks.
For example, If a student 'A' obtained 7 marks, all the students who copied from
'A', also obtained '7' marks.
Now the students with the same marks are disqualified in the test.
Help Swetha to find marks of the Topper in the class from the Qualified students.
Return -1 if no such student exists.


Input Format:
-------------
Line-1: An Integer N represents number of students.
Line-2: N space separated integers represent marks of N students marks[].
  
Output Format:
--------------
 Print an integer.

Constraints:
 1 <= N <= 2000
 0 <= marks[i] <= 1000
   
Sample Input-1:
---------------
6
11 12 3 12 11 10
  
Sample Output-1:
----------------
10

Explanation:
------------
The marks with 12 and 11 are copied. so the topper is with marks 10.
   
Sample Input-2:
---------------
6
10 15 15 10 20 20
  
Sample Output-2:
----------------
-1

Explanation:
------------
Every one will get disqualified.
*/

"""
def findTopper(results):
	for result in marks:
		#print(results, end="      \n      ")
		results = [x for x in results if results.count(x) == 1]
		#print(results)
	if len(results) == 0:
		return -1
	return sorted(results)[-1]


if __name__ == "__main__":
	length = int(input())
	marks = [int(num) for num in input().split()][:length]
	print(findTopper(marks))

"""
Alternative solutiprint(length)print(length)on:
	Use sets.
	Use dictionary.. find its frequency..
		Pick the ones having frequency as 1, and filter the maximum one.
"""