//BufferBlock.h
#pragma once
#include<iostream>
#include"BufferBlockADT.h"

class BufferBlock : public BufferblockADT {
private:
	//Instance variables:
	int blockID;
	char* block;
	int blockSize;

public:

	//sz is the size of the character array data
	//points to.
	BufferBlock() {}
	BufferBlock(char* data, int sz = 4096) {
		block = new char[sz];
		setBlockSize(sz);
	}
	~BufferBlock() {}

	//read the block from pos to pos + sz-1 (or to the end of the block)
	void getData(int pos, int sz, char* data) {
		for (int j = 0; j < sz; j++) {
			//cheacks for end of the block
			if (pos - (getID() * getBlocksize()) == getBlocksize()) { break; }

			data[j] = getBlock()[j + (pos - (getID() * getBlocksize()))];
		}
	}

	//setID
	void setID(int id) {
		blockID = id;
	}

	//getID
	int getID() const {
		return blockID;
	}

	//getBlocksize
	int getBlocksize() const {
		return blockSize;
	}

	//set blockSize
	void setBlockSize(int sz) {
		blockSize = sz;
	}

	//return the block
	char* getBlock() const {
		return block;
	}

	//set the block
	void setBlock(char* blk) {
		block = blk;
	}
};