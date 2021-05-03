# Theory-Of-Algorithms
## Description of this repository 
This repository on my GitHub account is for the project for Theory of Algorithms, a module taught by Dr. Ian McLoughlin for 4th Year Software Development in Galway-Mayo Institute Of Technology (G.M.I.T).<br>
For this project we were asked to write must write a program in the C programming language to calculate the SHA512 value of an input file. This program must take the name or path of the file as a command line argument and output the SHA512 digest of it. We also couldn’t use any external libraries other than the libraries that are included in the C standard library. The program must compile using `gcc` or `clang` and have to include a `Makefile`. which compiles it upon make being called in the project folder.

## How to run the project
To run the repository correctly, follow the steps below: <br>
P.S. You will need to use an Open-Source Linux software such as Debian or Ubuntu to run this repo. <br>
1. Clone the repository `Theory-Of-Algorithms` using the following command: ![Step 1](https://gyazo.com/d19898118c6be97873d9229b336ebdd8.png)
2. After completing step 1, go into the Theory of Algorithms folder: <br> ![Step 2](https://gyazo.com/06db2f65cf0a12d02e8211e6a97561e2.png)
3. After completing step 2, You then have to make the Sha-512.c file using the following command: <br>  ![Step 3](https://gyazo.com/fbfa9169f7bdebd1f4b96056fae177e6.png)
4. After completing step 3, You then can run the file you just created using the following command: <br> ![Step 4](https://gyazo.com/150c3d77b1f0d9ad41e8572056573e16.png)
5. After completing step 4, You can then run the tests using the makefile in the repository. The following commands will recreate the file again and run the tests: <br> ![Step 5 PT1](https://gyazo.com/642f9f4b9a963e3087d49c481d5892de.png) <br> ![Step 5 PT2](https://gyazo.com/a3d5a4cc4b69f6d80c7abffcd6f97f4f.png) <br> ![Step 5 PT3](https://gyazo.com/fb717d4552704d248969cb3eb60b81f8.png)


## What is the SHA-512 algorithm?
The SHA-512 algorithm is a hashing algorithm that performs a hashing function on some data given to it while. It’s part of a group of hashing algorithms called SHA-2 which includes SHA-256 as well which is used in the bitcoin blockchain for hashing while operating on 8 64-bit words. This algorithm functions on a 1024-bit message block and a hash value of 512-bit. 
### Hashing Function
Hashing Functions are functions that take data as an input and then produce an output called a hash digest of a fixed length for the input data. There are however conditions that must be met to satisfy this such as 1: Uniform distribution, 2: Fixed length and 3: Collision resistance. For uniform distribution, this should be for any value inputted, the outputted value of any possible result should be likely equally. For fixed length, the resulting values should be all a certain length etc sha-512 has output size of 512 bits. For collision resistance, this means that no two inputted values in the hash function have the same outputted result. 

### Process of sha-512
Some of the main points to discuss about the sha-512 are, 
1. Input formatting 
2. Hash buffer initialization
3. Message processing 
4. Output.
 
With `Input Formatting`, the sha-512 can't hash a message input of any size as it has a size limit. Because of this, the formatted message has three parts, the original message, padding bits and size of original message and with this it should have a whole size of a multiple of 1024 bits. Because of this the message that has been formatted will then be processed as blocks of 1024 bits each then and with that each block then is able to work with 1024 bits each. We take the input message and it is then we add some padding bits to get it to the length needed. The padding is done with 0 bits and 1 bit and with this algorithm padding must be done even if it’s only one bit. After this processing the message is giving to the algorithm to be appended and from here the size of the message is changed to 128 bits because of the limitations of the input message with the sha-512 algorithm. After this the padding bits and size of the message have been completed. <br>
![Message + Padding + Size](https://gyazo.com/ebd8834278486bf315f6beee5bbf88cd.png)

With `Hash Buffer Initialization`, it processes each part of 1024 bits from a message using the result from previous amount. But with this there's a problem with the first 1024 bits which we can't use results from previous processing. So, what we do is use the default value for the first block to begin. With every result needed to be used in the processing stage, it's stored elsewhere to be used later in the process and this is done by the hash buffer and this is what holds the final hash value of the processing phase of the sha-512.

![Hash buffer and Initialization Vector values](https://gyazo.com/4cb5aee3c80905c83aae3f993f5f3a3c.png)

With `Message Processing`, it's done by taking one block of 1024 bits per go. To undergoes the process, it needs the 1024-bit block and the results of previous processing. The algorithm consists of several rounds and the message block is expanded into words using a message sequencer

![Message Processing](https://gyazo.com/0dc97b188644d2dd38e1c24434616d03.png)

With `Output`, after every 1024-bit block goes into the message processing phase, we get the final 512-bit value of the original message. Then the results of all blocks are processed to the next block and finally when the final 1024-bit block is finished, we have the result of the algorithm and we receive the hash value of the original message. 

The importance I find with the sha-512 is it having a larger internal state and a greater number of rounds and because of this has a higher bit strength. Security involved with this algorithm is also very good as there is no technology that can break this algorithm or even the sha256 and compatibility is also a big factor of this algorithm.

## Questions
### Why can't we reverse the SHA512 algorithm to retrieve the original message from a hash digest?
One of the main reasons we can't reverse the sha-512 algorithm because it is a hashing function and because of this it can't be reversed because it is a one-way function. other reasons for us not being able to reverse the algorithm are... 
- The `Avalanche effect` because any changes made to the input even if it is adding or removing a comma will cause a huge effect in the internal part of the algorithm and in the output of the result. Because of this it stops people building up relationships between inputs and outputs.
- The `hash speed` algorithm operates at a reasonable speed and it works out the hash values quickly and this is a key part of the speed. Within terms of the algorithm it’s not always ideal to be very fast and the speed all depends on what it's also being used for. If I wanted it to be fast hashing algorithm it would suit website connections and if i wanted it to be slower, I’d use it for password hashing.
- `Bit Dependency` is also a huge factor of why it can't be reversed because a hash algorithm is designed to guarantee each bit of the output of the algorithm is dependent on each bit of the input. Because of this, it prevents the algorithm being split up and try to reverse the calculation of the input from each bit of the hash output. so, if you want to solve one output bit, you need to know the entire input which can be a daunting task.

Another bit point to discuss about this is hash functions. These have a big purpose in cryptography. They take a plaintext input and generate a hash value of the output in a specific size in a way that can't allow for it to be reversed. Perks of a strong hash functions are...
- Ensuring data integrity
- Secure against unauthorized modifications
- Protect stored passwords
- Operate at different speeds to suit different purposes <br>

Most of the data that is taken in is discarded during the hash process stage. The user can make the input file and add whatever they would like to it but at the end of the day the output will stay the same because of the data that will be left over and not used. For this reason, is usually never found as to what the data of the input file was from looking at the results after using the algorithm. <br>

### Can you design an algorithm that, given enough time, will find input message that give each of the possible 512-bit strings?
From my understanding of the question, there may be a possibility of designing an algorithm for finding the input message of the 512-bit strings. First way i found is by using a brute force method which is a way on solving a problem by using computer power and trying to find every possibility rather than advanced techniques to improve efficiency. 
It usually iterates over all input messages to find a specific result. With it is also a big ask as you would have to review all input messages for sha-512 and if you did you would probably find the same matches. From what i have read then it all depends then on the input and distribution of messages within that domain to find the message for the sha-512 output. Example I found also is with 128 bits of the input can be regarded unknown and then brute forcing the sha-512 becomes impossible. From my reading, an approved hash function is expected to have three properties [12]...
- Collision Resistance: It's impossible to find two different inputs to the hash function that have the same hash value. But only if the hash is a function. Collision Resistance is measured by the amount of work needed to find a collision for the hash function with a high probability.
- Preimage resistance: Given a randomly chosen hash value called hash value, it is computationally infeasible to find an x so that hash(x) = hash value. This property is also called the one-way property. This is measured by the amount of work that would be needed to have a big possibility of finding the preimage of a hash function.
- Second preimage resistance: Like the first time it's impossible to find a second input that has the same hash value as other inputs. For this it is measured by the amount of work that would be needed to have a high probability of finding a second preimage for a hash function. However, for some hash functions, the second preimage resistance strength also depends on the message length processed by the hash function. <br>

### How difficult is it to find a hash digest beginning with at least twelve zeros?
In my research on this question, there can be ways in which you can find a hash digest with at least twelve zeros at the beginning. <br>

A hash function is a process that takes input data and performs an operation on it and returns output data of a fixed size. In bitcoin, hash functions are part of the block hashing algorithm which is used to write new transactions into blockchain through mining. <br>

Regarding cryptocurrency mining, bitcoin uses cryptography with the hash function called double SHA-256(the sha-256 hash of the sha-256 hash of something). The hash then takes a large chunk of the data as inputs and shrinks it down into smaller hash values. With cryptographic, you can't get a hash value you want without trying a lot of inputs. The process then goes, we need to mine a block which we collect from a new transaction, then hash the block into 256-bit block hash value. Here we can be able to see if the hash has enough zeros and if so then it's successful and the hash becomes the identifier for the block. But most of the time this doesn't happen and then we must modify the block again and again and this process happens every 10 mins and when successful again you restart the process. From my research, the diagram below shows the structure of a block:
![Bitcoin Block Structure](https://gyazo.com/4360d51f3bd0965109fba8b901a807bf.png) 

The Yellow section is the block header, followed by the transaction that goes into the block. The first transaction is the Coinbase that grants a award to the person mining bitcoin. The rest of the transactions are standard transactions moving bitcoins around. If the hash header starts with enough zeros, the block is successful. <br>

To explain the different parts of the diagram. The first section is the protocol version. Second section is the hash value of the previous block in the chain to make certain all blocks come together to form an unbroken sequence in the chain. Third section is the Merkle root is the hash of all the hashes of all the transactions that are part of a block in a blockchain network and is very important in security because it makes sure that transactions cannot be changed when they become part of the block. Fourth section is the timestamp of the block which is a small piece of data stored in each block where its main function is to determine the moment in which the block has been mined and validated by the network. Fifth section is the difficulty value bits which is a measure of how difficult it is to find a hash below a given target and here the value changes after every 2016 blocks to keep security for it in good shape. Last section is the nonce which is some value that varies with time, to verify that specific values are not reused with the term itself standing for “number used once”.


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
11. https://www.freecodecamp.org/news/brute-force-algorithms-explained/#:~:text=Brute%20Force%20Algorithms%20are%20exactly,%2C%20each%20from%200%2D9
12. https://www.govinfo.gov/content/pkg/GOVPUB-C13-a90b666c792967c1ef7dc3f026c75f45/pdf/GOVPUB-C13-a90b666c792967c1ef7dc3f026c75f45.pdf
13. http://www.righto.com/2014/02/bitcoin-mining-hard-way-algorithms.html
