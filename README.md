# Intal library

## Introduction:
	- Intal is an non negative number of arbitary length where the integers are represented as strings and we need to perform the arithmetic operations and other functionalities on these string represented numbers.
	Since the integers opeations in c is limited and  we cannot store large and the operations will be difficult but with strings we can do operations on each character and get the same result by applying appropriate algorithm
	
	### Application 
	It can be used to do large calculation on large numbers, less burden on the hardware compared to normal operations on integers  

### Intal include the follwing functionalities:
	-- Addition
	-- Subtraction
	-- Compare
	-- Multiplication
	-- Modulus
	-- GCD
	-- Power
	-- Fibonacci
	-- Factorial
	-- Binomial coefficient
	-- Max of array
	-- Min of array
	-- Linear Search
	-- Coin row Problem
	-- Sorting
	-- Binary Search


## Approach in implementing the functionalities:
	-- Addition 
		Adding 2 intals character by character 
		Time complexity: O(n)

	-- Subtraction
		Subtracting 2 intals character by character 
		Time complexity: O(n)

	-- Compare
		Remove the leading zeroes from both the intals then
		1. compare their lengths and return which is larger on length 
		2. 'strcmp()' compare whether they are same and return 0
		3. if both the lengths are same compare the characters from 0th index if one of is greater return accordingly
		Time complexity: O(n)

	-- Multiplication
		- Getting 1 term in the intal2 and multiplying with the whole intal1 and storing in the array repeatedly doing this and after everyting is consumed getting the element of arr and finding sum and adding the carry to next array element and storing the modulus in the same place 
		- After getting this storing this in the character array
		Time complexity: O(m*n)


	-- Modulus:
		Similar to dividing numerator by denominator
		1. If the intal1 is less than intal2 intal1 is returned 
		2. Dynamically created a character array i,e, p  
			- checking whether that array is less than the intal2 
			- if yes, appending individual character to that 'p' until it is numerically greater than the intal2 
			- and then repeatedly subtracting 'p' with the intal2 and storing it in the 'p' itself until 'p' is less than the intal2 
			- and after that next character of intal1 is again appended to 'p' 
			- and again the cycle repeats until all the characters are iterated in the intal1 
			- then the 'p' is returned which is the remainder
		

	-- GCD:
		Copied intal1 and intal2 in another array
		comparing copied_intal2 everytime with 0 
		- if equal return intal1
		- else store change intal1_copied to intal2_copied and intal2_copied with modulus of 2 intals repeatedly 


	-- Power:
		-If the intal2 is 0 return 1
		- else recurively compute pow(intal1, n/2) store it in temp varaible and multiply it with itself 
		- if n is odd again multiply the intal1 to that profuct
		Time complexity: O(logn)
		(Reference: geeksforgeeks)



	-- Fibonacci:
		Iteratively finding the fibonacci by taking the 3 character pointers 


	-- Factorial:
		Iteratively finding the factorial 

	-- Binomial coefficient:
		Dynamic programming
		-with C(n,k)=C(n-1,k)+C(n-1,k-1) implementation

	-- Max :
		Fixing the index 0 as max and comapring the elements in the index and updating the max 

	-- Min:
		Fixing the index 0 as min and comapring the elements in the index and updating the min

	-- Linear Search
		Linearly iterating over the list and comparing each element with  the key if match return index else return -1

	-- Coin row problem
		Taking 3 varaibles one with arr[0], one with '0' and comapring these 2 and storing the max in the 3rd variable nd changing the 1st variable to the sum of 2nd variable and the next element 2nd to the 3rd element and doing it iteratively

	-- Sorting:
		Used Merge Sort algorithm
		(Reference - geeksforgeeks)


	-- Binary Search:
		Used Binary Search algorithm
		(Reference - geeksforgeeks)


## Future Work
	a. Most the basic functionalities has already been included so anymore is further not needed according to me
	b. If there were no restrictions I would have used Python language for implementation
