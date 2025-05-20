//LRUBufferPool.h
#pragma once
#include<iostream>
#include<fstream>
#include"BufferPoolADT.h"
#include"BufferBlock.h"
#include"constants.h"

class LRUBufferPool : public BufferPoolADT {
private:
	//The buffer pool consists of X number of buffer blocks
	BufferBlock* buffer;
	fstream input;
public:
	//Constructor gets the filename of the file to be buffered,
	//opens the file, and instantiates poolSize buffer blocks by
	//reading the file and filling the blocks in order.  When the constructor
	//is done the buffer pool blocks should be full with the beginning
	//contents of the input file.
	LRUBufferPool() {}
	LRUBufferPool(string filename, int poolSize = 5, int blockSize = 4096) {
		buffer = new BufferBlock[poolSize];
		input.open(filename.c_str(), fstream::in | fstream::binary);
		for (int i = 0; i < poolSize; i++) {
			input.seekg(i * blockSize);
			char* blk = getCharArray(blockSize);
			input.read(blk, blockSize);
			buffer[i].setBlock(blk);
			buffer[i].setBlockSize(blockSize);
			buffer[i].setID((input.tellg()/blockSize)-1);
		}
	}
	~LRUBufferPool() { input.close(); }

	// Copy "sz" bytes from position "pos" of the buffered
	//   storage to "space".
	void getBytes(char* space, int sz, int pos) {
		bool isLoaded = false;
		BufferBlock temp;
		//cheacks to see if the block is in the array already or not if found
		//sets isLoaded to true and moves it to the front of the array shifting every thing else down in the array
		for (int i = 0; i < 5; i++) {
			if (pos/buffer->getBlocksize() == buffer[i].getID()) {
				isLoaded = true;
				buffer[i].getData(pos, sz, space);
				temp = buffer[i];
				for (int j = i; j > 0; j--) {
					buffer[j] = buffer[j-1];
				}
				buffer[0] = temp;
			}
		}
		//if the block is not in the array then it is loaded to the array and 
		//placed in the front of the array after the array is shifted down removing the last item 
		//that was loaded in the array.
		if (isLoaded == false) {
			input.seekg((pos/buffer->getBlocksize())*buffer->getBlocksize());
			char* blk = getCharArray(buffer->getBlocksize());
			input.read(blk, buffer->getBlocksize());
			temp.setBlock(blk);
			temp.setBlockSize(4096);
			temp.setID((input.tellg() / buffer->getBlocksize()) - 1);
			for (int i = 4; i > 0; i--) {
				buffer[i] = buffer[i - 1];
			}
			buffer[0] = temp;
			buffer[0].getData(pos, sz, space);
		}
	}

	// Print the order of the buffer blocks using the block id
	//	 numbers.
	void printBufferBlockOrder() {
		std::cout << "buffer block order from most recently used to LRU is :" << std::endl;
		getLRUBlockID();
		std::cout << std::endl;
	}

	// Get the block id number of the least recently used 
	//	 buffer block and prints it out.
	int getLRUBlockID() {
		for (int i = 0; i < 5; i++) {
			std::cout << buffer[i].getID() << ", ";
		}
		return 0;
	}
};