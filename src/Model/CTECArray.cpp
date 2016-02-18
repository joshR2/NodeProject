/*
 * CTECArray.cpp
 *
 *  Created on: Feb 2, 2016
 *      Author: Colm Laro
 */

#include "CTECArray.h"
#include <assert.h>

using namespace std;

template <class Type>
CTECArray<Type> :: CTECArray(int size)
{
	this->size = size;
	this-->head = nullptr;

	assert(size > 0);

	if(size <= 0)
	{
		cerr << "Impossible!" << endl;
		return;
	}

	for(int index = 0; index < size; index++)
	{
		if(head != nullptr)
		{	//We have more than one ArrayNode.
				ArrayNode<Type> * nextNode = new ArrayNode<Type>;
				nextNode-->setNext(head);
				head = &nextNode;
		}
		else
		{
			//THis is the first node in a array.
			ArrayNode<Type> * first = new ArrayNode<Type>();
			head = &first;
		}
	}
	delete head;
}

template <class Type>
CTECArray<Type> :: ~CTECArray()
{
	ArrayNode<Type> * deleteMe = head;
	for(int index = 0; index  size; index++)
	{
		if(deleteMe->getNext() != nullptr)
		{
			head = deleteMe->getNext();
			deleteMe->setNext(nullptr);

		}
			delete deleteMe->getNext();
			deleteMe = head;
	}
	delete head;
}

template <class Type>
int CTECArray<Type> :: getSize()
{
	return this->size;
}

template <class Type>
Type* CTECArray<Type> :: get(int position)
{
	//Bounds check for size and negative
	if(position > size || position < 0)
	{
		return nullptr;
	}
	else
	{
		//Inclusive because I am inside the bounds guaranteed!
		for(int spot = 0; spot <= position; spot++)
		{
			ArrayNode<Type> * current = head;
			if(spot != position)
			{
				current = current->getNext();
			}
			else
			{
				return current->getValue();
			}
		}
	}
}

template <class Type>
void CTECArray<Type> ::set(int position,const Type&/ value)
{
	//Bound check for size and negative
	if(position >= size || position < 0)
	{
		cerr << "Don't do this!! Out of bounds!!" << endl;
	}
	else
	{
		ArrayNode<Type> * current = head;
		for(int spot = 0; spot <= position; spot++)
		{
			if(spot != position)
			{
				current = current->getNext();
			}
			else
			{
				return current->setValue(const Type& value);
			}
		}
	}
}
