#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <string>
#include <iostream>
using namespace std;

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val)
{
	//Checks if empty -> creates new Item
	if(empty())
	{
		Item* newVal = new Item();
		newVal->first = 0;
		newVal->last = 1;
		head_ = newVal;
		tail_ = newVal;
		size_ = size_ + 1;
		newVal->val[0] = val;
	}
	//Checks if Item reached capcity -> if not, adds val to Item
	else if(tail_->last != 10)
	{
		tail_->last = tail_->last + 1;
		tail_->val[tail_->last - 1] = val;
		size_ = size_ + 1;
	}
	//Creates new Item and adds to back
	else
	{
		Item* newVal = new Item();
		newVal->prev = tail_;
		newVal->first = 0;
		newVal->last = 1;
		size_ = size_ + 1;
		newVal->val[0] = val;
		tail_ = newVal;
		if(size_ == 11)
		{
			head_->next = tail_;
			tail_->prev = head_;
		}
	}
}

void ULListStr::push_front(const std::string& val)
{
	//Checks if empty -> creates new Item
	if(empty())
	{
		Item* newVal = new Item();
		newVal->first = 9;
		newVal->last = 10;
		head_ = newVal;
		tail_ = newVal;
		size_ = size_ + 1;
		newVal->val[9] = val;
	}
	//Checks if Item reached capcity -> if not, adds val to Item
	else if(head_->first != 0)
	{
		head_->first = head_->first - 1;
		head_->val[head_->first] = val;
		size_ = size_ + 1;
	}
	//Creates new Item and adds to front
	else
	{
		Item* newVal = new Item();
		newVal->next = head_;
		newVal->first = 9;
		newVal->last = 10;
		size_ = size_ + 1;
		newVal->val[9] = val;
		head_ = newVal;
		
		if(size_ == 11)
		{
			head_->next = tail_;
			tail_->prev = head_;
		}
	}
}

void ULListStr::pop_front()
{
	//Checks if last item -> if not, updates first
	if(head_->first + 1 != 9)
	{
		head_->first = head_->first + 1;
	}
	else
	{
		//Checks if next Item exists
		if(head_->next == NULL)
		{
			head_ = NULL;
		}
		//Sets head to next Item
		else
		{
			head_ = head_->next;
			head_->prev = NULL;
		}
	}	
	size_ -= 1;
}

void ULListStr::pop_back()
{
	//Checks if last item -> if not, updates last
	if(tail_->last - 1 != 0)
	{
		tail_->last = tail_->last - 1;
	}
	else
	{
		//Checks if next Item exists
		if(tail_->prev == NULL)
		{
			tail_ = NULL;
		}
		//Sets tail to prev Item
		else
		{
			tail_ = tail_->prev;
			tail_->next = NULL;
		}
	}	
	size_ -= 1;
}

std::string const & ULListStr::back() const
{
	return tail_->val[tail_->last];
}

std::string const & ULListStr::front() const
{
	return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
	//Checks bounds
	if(size_ <= loc || loc < 0)
	{
		return NULL;
	}
	
	Item *temp = head_;
	//Checks if loc is found in first Item -> if not, decrements loc
	while(temp->last - temp->first <= loc)
	{
		loc -= temp->last - temp->first;
		temp = head_->next;
	}
	
	loc += temp->first;
	
	return &temp->val[loc];
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location 1");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location 2");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location 3");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
