

// Choose which run to compile
#define RUN0 //RUN1 RUN2 RUN3 RUN4


#ifdef RUN0 

#include"list.h"
#include"studentinfo.h"
#include<iostream>
#include<string>




int main() {

	std::cout << StudentInfo::name() << std::endl;
	std::cout << StudentInfo::id() << std::endl;

	List<std::string> l; //List of integers

	std::cout << std::endl << std::endl;
	l.pop_at(2);
	l.print();
	l.pop_at(2);
	l.print();


	l.push_back("Hello");
	l.push_front("World");
	l.push_front("Bob");
	l.push_front("2");

	l.print(); // 2 Bob World Hello

	l.pop_rear();
	l.print(); // 2 Bob World 

	std::cout << l.front() << std::endl; // 2
	return 0;
}

#elif defined RUN1
#define MAKE_MEMBERS_PUBLIC
#include"list.h"
#include<assert.h>

//Unit test example for push_font on initially empty list

int main() {

	// Step 1: Initial state
	// Assume that constructor implemented properly
	// If you're not sure if the constructor is 
	// implemented properly, STOP, go back and make
	// sure. Luckily ther default constructor is 
	// done for you.  But the point remains, never,
	// ever, use a function in a test that isn't itself
	// verified to function to spec.
	List<int> l;


	// Step 2: Execute the function to test
	l.push_front(99);

	// Step 3: Verify what you expect to observe.
	// You must know what is suppose to happen in
	// order to analyze for correctness. Generally, 
	// you must permute all possible combinations
	// of all member variables.
	assert(l.head != nullptr);
	assert(l.tail != nullptr);
	assert(l.num_nodes == 1);
	assert(l.head->prev == nullptr);
	assert(l.head->next == nullptr);
	assert(l.head->item == 99);
	

}


#elif defined RUN2
#define MAKE_MEMBERS_PUBLIC
#include"list.h"
#include<assert.h>
#include<string>

//Unit test example for push_font on initially non empty list

int main() {

	// Step 1: Initial state
	// Same as above, except we must first populate the list
	// However, since we are testing push_front, we cannot
	// use it to generate the initial state of our list
	// to test.  So we have to manually set the initial state
	// in this case we are creating a list with three nodes.
	List<std::string>::Node* first = new List<std::string>::Node;
	List<std::string>::Node* second = new List<std::string>::Node;
	List<std::string>::Node* third = new List<std::string>::Node;
	
	// We have to manually linked everything together:
	first->item = "first";
	first->prev = nullptr;
	first->next = second;

	second->item = "second";
	second->prev = first;
	second->next = third;

	third->item = "third";
	third->prev = second;
	third->next = nullptr;

	// Now we create  List object and inject the initial control state:
	List<std::string> l;
	l.head = first;
	l.tail = third;
	l.num_nodes = 3;

	// Step 2: Now with the list given a complete and correct starting state
	// We can test various member functions for correctness.
	// For example we can use this as one test for push_front;
	l.push_front("Zero");

	// Step 3: Verify:  Technically, we should examine all 
	// member variables, and all nodes' item, next, prev pointers
	// to ensure that the push_front didn't mangle any of the
	// internal nodes.  But, this is mostly just to illustrate
	// how you might develop your own tests.  
	assert(l.num_nodes == 4);
	assert(l.head->prev == nullptr);
	assert(l.head == first->prev);
	assert(l.head->next == first);
	assert(l.head->item == "Zero");
	assert(l.tail == third);
}

#else

#endif