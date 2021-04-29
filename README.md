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
 
With `Input Formatting`, the sha-512 can't hash a message input of any size as it has a size limit. Because of this, the formatted message has three parts, the original message, padding bits and size of original message and with this it should have a whole size of a multiple of 1024 bits. Because of this the message that has been formatted will then be processed as blocks of 1024 bits each then and with that each block then is able to work with 1024 bits each. We take the input message and it is then we add some padding bits to get it to the length needed. The padding is done with 0 bits and 1 bits and with this algorithm padding has to be done even if its only one bit. After this processing the message is giving to the algorithm to be appended and from here the size of the message is changed to 128 bits because of the limitations of the input message with the sha-512 algorithm. After this the padding bits and size of the message have been completed.<br>
![Message + Padding + Size](https://gyazo.com/ebd8834278486bf315f6beee5bbf88cd.png)


With `Hash Buffer Initialization`, it processes each part of 1024 bits from a message using the result from previous amount. But with this there's a problem with the first 1024 bits which we can't use results from previous processing. So what we do is use the default value for the first block to begin. With every result needed to be used in the processing stage, it's stored elsewhere to be used later in the process and this is done by the hash buffer and this is what holds the final hash value of the processing phase of the sha-512.

![Hash buffer and Initialization Vector values](https://gyazo.com/4cb5aee3c80905c83aae3f993f5f3a3c.png)

With `Message Processing`, it's done by taking one block of 1024 bits per go. To undergoes the process it needs the 1024 bit block and the results of previous processing. The algorithm consists of several rounds and the message block is expanded into words using a message sequencer

![Message Processing](https://gyazo.com/0dc97b188644d2dd38e1c24434616d03.png)

With `Output`, after every 1024 bit block goes into the message processing phase, we get the final 512 bit value of the original message. Then the results of all blocks are processed to the next block and finally when the final 1024 bit block is finished, we have the result of the algorithm and we recieve the hash value of the original message. 

The importance i find with the sha-512 is it having a larger internal state and more number of rounds and because of this has a higher bit strength. Security involved with this algorithm is also very good as there is no technology that is capable of breaking this algorithm or even the sha256 and compatibility is also a big factor of this algorithm.

## References
point 1 and 2 are about sha 512 algorithm

1. https://medium.com/@zaid960928/cryptography-explaining-sha-512-ad896365a0c1#:~:text=SHA%2D512%20is%20a%20hashing,some%20data%20given%20to%20it.&text=It's%20part%20of%20a%20group,the%20bitcoin%20blockchain%20for%20hashing.
2. http://www.iwar.org.uk/comsec/resources/cipher/sha256-384-512.pdf
3. https://core.ac.uk/download/pdf/186473296.pdf
4. https://blog.komodoplatform.com/en/sha-512/
