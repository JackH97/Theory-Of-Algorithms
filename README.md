# Theory-Of-Algorithms
## Description of this repository 
This repository on my github account is for the project for Theory of Algorithms, a module taught by Dr. Ian McLoughlin for 4th Year Software Development in Galway-Mayo Institute Of Technology(G.M.I.T).<br>
For this project we were asked to write must write a program in the C programming language to calculate the SHA512 value of an input file. This program must take the name or path of the file as a command line argument and output the SHA512 digest of it. We also could't use any external libraries other than the libraries that are included in the C standard library. The program must compile using `gcc` or `clang` and also have to include a `Makefile`. which compiles it upon make being called in the project folder.


## What is the SHA-512 algorithm?
The SHA-512 algorithm is a hashing algorithm that performs a hashing function on some data given to it while. It’s part of a group of hashing algorithms called SHA-2 which includes SHA-256 as well which is used in the bitcoin blockchain for hashing while operating on 8 64 bit words. This algorithm functions on a 1024-bit message block and a hash value of 512-bit. 
### Hashing Function
Hashing Functions are functions that take data as an input and then produce an output called a hash digest of a fixed length for the input data. There are however conditions that have to be met to satisfy this such as 1: Uniform distribution, 2: Fixed length and 3: Collision resistance. For uniform distribution, this should be for any value inputted, the outputted value of any possible result should be likely equally. For fixed length, the resulting values should be all of a certain length etc sha-512 has output size of 512 bits. For collision resistance, this means that no two inputted values in the hash function have the same outputted result. 

### Process of sha-512
Some of the main points to discuss about the sha-512 are, 
1. Input formatting 
2. Hash buffer initialization
3. Message processing 
4. Output.
 
With input formatting, the sha-512 can't hash a message input of any size as it has a size limit. Because of this, the formatted message has three parts, the original message, padding bits and size of original message and with this it should have a whole size of a multiple of 1024 bits. Because of this the message that has been formatted will then be processed as blocks of 1024 bits each then and with that each block then is able to work with 1024 bits each. We take the input message and it is then we add some padding bits to get it to the length needed. The padding is done with 0 bits and 1 bits and with this algorithm padding has to be done even if its only one bit. After this processing the message is giving to the algorithm to be appended and from here the size of the message is changed to 128 bits because of the limitations of the input message with the sha-512 algorithm. After this the padding bits and size of the message have been completed.

With Hash buffer initialization, it processes each part of 1024 bits from a message using the result from previous amount. But with this there's a problem with the first 1024 bits which we can't use results from previous processing. So what we do is use the default value for the first block to start the process off. 







## References
point 1 and 2 are about sha 512 algorithm

1. https://medium.com/@zaid960928/cryptography-explaining-sha-512-ad896365a0c1#:~:text=SHA%2D512%20is%20a%20hashing,some%20data%20given%20to%20it.&text=It's%20part%20of%20a%20group,the%20bitcoin%20blockchain%20for%20hashing.
2. http://www.iwar.org.uk/comsec/resources/cipher/sha256-384-512.pdf
