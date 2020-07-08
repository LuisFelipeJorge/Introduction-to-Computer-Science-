## Description 

Make a program that reads an integer op that represents the option you should use to compare two words read from standard input. Any of the 5 criteria below can be chosen to compare them:

1. Which word is bigger
2. Alphabetical Order
3. Which word has the highest sum of the letter values ​​(A = 0 to Z = 25)
4. Which of the words has more repetitions of a given letter
5. In which of the words does a particular letter appear first (if the letter sought is the second of word 1 and the third of word 2, word 1 won the comparison)

The entry consists of an integer, corresponding to the option, and two words to be compared according to the option. If the option is 4 or 5, another letter will be read that will serve as a key for the operations. The output should be only "1" if the first word wins the comparison, "2" if the second word wins the comparison, and "0" if the comparison results in a tie.

## Input example :
### Input
```
Case 1) 
1
Arvore
Zebra

Case 2)
2
Arvore
Zebra

Case 3)
3
Arvore
Zebra

Case 4)
4
Arvore
Zebra
r

Case 5)
1
Arvore
Zebra
e
```
### Output

```
Case 1) 1
Case 2) 1
Case 3) 1 
Case 4) r
Case 5) 2
```