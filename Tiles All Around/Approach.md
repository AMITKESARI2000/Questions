If we observe carefully, the number of tile patterns is coming out to be a fibonnaci sequence which can be caluculated using simple logic/dp.

Since the constraints are of n=10^12 order you have to use matrix exponentiation for the nth finding factorial.

Start with F1={{1,1},{1,0}} and find F1^n. The value at (0,0) is the ans.

->use modulo operators correctly
->use long long
 