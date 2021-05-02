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

## Questions
### Why can't we reverse the SHA512 algorithm to retrieve the original message from a hash digest?
One of the main reasons we can't reverse the sha-512 algorithm because it is a hashing function and because of this it can't be reversed because it is a one-way function. other reasons for us not being able to reverse the algorithm are... 
- The `Avalanche effect` because any changes made to the input even if its adding or removing a comma will cause a huge effect in the internal part of the algorithm and also in the output of the final result. Because of this it stop people building up relatonships between inputs and outputs.
- The `hash speed` algorithm operates at a resonable speed and it works out the hash values quickly and this is a key part of the speed. With that being said in terms of the algorithm its not always ideal to be very fast and the speed all depends on what it's also being used for. If i wanted it to be fast hashing algorithm it would suit website connections and if i wanted it to be slower i'd use it for password hashing.
- `Bit Dependency` is also a huge factor of why it can't be reversed becuase a hash algorithm is designed to guarantee each bit of the output of the algorithm is dependent on each bit of the input. Because of this, it prevents the algorithm being split up and try to reverse the calculation of the input from each bit of the hash output. so if you want to solve one output bit, you need to know the entire input which can be a daunting task.

Another bit point to discuss about this is hash functions. These have a big purpose in cryptography. They take a plaintext input and generate a hash value of the output in a specific size in a way that can't allow for it to be reversed. Perks of a strong hash functions are...
- Ensuring data integrity
- Secure against unauthorized modifications
- Protect stored passwords
- Operate at different speeds to suit different purposes <br>

Most of the data that is taken in is discarded during the hash process stage. The user can make the input file and add whatever they would like to it but at the end of the day the output will stay the same because of the data that will be left over and not used. For this reason is usually never found as to what the data of the input file was from looking at the results after using the algorithm. <br>

### Can you design an algorithm that, given enough time, will find input message that give each of the possible 512-bit strings?
From my understanding of the question, there maybe a possibility of designing an algorithm for finding the input message of the 512-bit strings. First way i found is by using a brute force method which is a way on solving a problem by using computer power and trying to find every possibility rather than advanced techniques to improve efficiency. 
It usually iterates over all input messages to find a specific result. With that being said it is also a big ask as you would have to review all input messages for sha-512 and if you did you would probably find the the same matches. From what i have read then it all depends then on the input and distribution of messages within that domain to find the message for the sha-512 output. Example i found also is with 128 bits of the input can be regarded unknown and then brute forcing the sha-512 becomes impossible. 

## References
1. https://medium.com/@zaid960928/cryptography-explaining-sha-512-ad896365a0c1#:~:text=SHA%2D512%20is%20a%20hashing,some%20data%20given%20to%20it.&text=It's%20part%20of%20a%20group,the%20bitcoin%20blockchain%20for%20hashing.
2. http://www.iwar.org.uk/comsec/resources/cipher/sha256-384-512.pdf
3. https://core.ac.uk/download/pdf/186473296.pdf
4. https://blog.komodoplatform.com/en/sha-512/
5. https://security.stackexchange.com/questions/145284/why-cant-sha256-be-decrypted#:~:text=SHA256%20is%20a%20hashing%20function%2C%20not%20an%20encryption%20function.&text=In%20that%20case%2C%20SHA256%20cannot,which%20defeats%20its%20design%20goal.
6. https://crypto.stackexchange.com/questions/89690/sha-512-how-difficult-is-it-to-find-a-hash-digest-beginning-with-at-least-twel
7. https://bitcoin.stackexchange.com/questions/65478/which-is-the-smallest-hash-that-has-ever-been-hashed
8. https://crypto.stackexchange.com/questions/45377/why-cant-we-reverse-hashes
9. https://www.thesslstore.com/blog/what-is-a-hash-function-in-cryptography-a-beginners-guide/
10. https://www.quora.com/Is-it-possible-to-bruteforce-sha512-hash-function
11. https://www.freecodecamp.org/news/brute-force-algorithms-explained/#:~:text=Brute%20Force%20Algorithms%20are%20exactly,%2C%20each%20from%200%2D9.
