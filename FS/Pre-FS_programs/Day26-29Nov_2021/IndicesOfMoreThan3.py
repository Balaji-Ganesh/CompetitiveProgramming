"""
/*
Nani has given a word in which some characters are consecutively repeated. 
He can form Batches for each consecutive repeated character by choosing start
and ending position of the character.

For example, a word like "pqrrrrrsstttu", Batches are [2,6] for 'r',[7,8] for s,
[9,11] for 't'.

 Nani wants to consider only the Batches with count of characters is atleast 3.
Help Nani to return the batches in the ascending order of the positions of each
batch.

Input Format:
-------------
Line-1: A string represents a word.
 
Output Format:
--------------
Print a 2-D array.
 
Constraints:
-----------
1 <= word.length  <= 2*10^4
word consists only lowercase letters.

 
Sample Input-1:
---------------
pqqrrrst
 
Sample Output-1:
----------------
[[3, 5]]

Explanation:
------------
rrr is the only batch with start index 3 and end index 5.
 
Sample Input-2:
---------------
pqqqrrrsssstvvxxyyzz

Sample Output-2:
----------------
[[1, 3], [4, 6], [7, 10]]

*/


"""
def getIndicesOfMoreThan3(word):
    freq = {word[0]: 1}
    for idx in range(1, len(word)):
        if word[idx] == word[idx-1]:                                # only if consecutive..
            freq[word[idx]] = freq.get(word[idx], 1)+1
    #print(freq)
    freq = {key:value for key, value in freq.items() if value>=3}   ## filter the keys, which had only value>=3..
    #print(freq)
    indices = []
    for key, value in freq.items():
        indices.append([ word.index(key), word.rindex(key) ])
        #print(word.index(key))
    #print(indices)
    return indices


def main():
    word = input()
    print(getIndicesOfMoreThan3(word))

main()
