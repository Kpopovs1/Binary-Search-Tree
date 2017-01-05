#include <chrono>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>     
#include <time.h>    

#include "BST.cpp"
#include "TriTree.cpp"

using namespace std;

int main(int argc, char **argv) {

	TriTree<int> bal10;
	TriTree<int>unBal10;

	TriTree<int> bal15;
	TriTree<int>unBal15;

	TriTree<int> bal20;
	TriTree<int>unBal20;
	
	int randNum;
	

	std::chrono::time_point<std::chrono::system_clock> start, end;

	start = std::chrono::system_clock::now();//start time for balanced

	for (int i =0; i<10000; i++){//balanced tree
		randNum = rand() %10000;

		while(bal10.insert(randNum)==false){
			randNum = rand() %10000;
			
		}
		bal10.insert(randNum);
	}

	end = std::chrono::system_clock::now();//end time
	std::chrono::duration<double> elapsed_seconds = end-start;//elapsed time
    	std::cout <<"elapsed time for blanced 10,000: " << elapsed_seconds.count()<< " seconds" << endl;//display time

	//--------------------------------

	start = std::chrono::system_clock::now();//start time for unbalanced

	

	for(int i = 0; i <10000; i++){ //unbalanced tree

		unBal10.insert(i);

	}
	
	end = std::chrono::system_clock::now();//end time
	elapsed_seconds = end-start;//elapsed time
    	std::cout <<"elapsed time for unblanced 10,000: " << elapsed_seconds.count()<< " seconds" << endl;//display time

	//---------------------------------------
	start = std::chrono::system_clock::now();//start time for balanced

	for (int i =0; i<15000; i++){//balanced tree
		randNum = rand() %15000;

		while(bal15.insert(randNum)==false){
			randNum = rand() %15000;
			
		}
		bal15.insert(randNum);
	}

	end = std::chrono::system_clock::now();//end time
	elapsed_seconds = end-start;//elapsed time
    	std::cout <<"elapsed time for blanced 15,000: " << elapsed_seconds.count()<< " seconds" << endl;//display time
	
	
	//--------------------------------

	start = std::chrono::system_clock::now();//start time for unbalanced

	

	for(int i = 0; i <15000; i++){ //unbalanced tree

		unBal15.insert(i);

	}
	
	end = std::chrono::system_clock::now();//end time
	elapsed_seconds = end-start;//elapsed time
    	std::cout <<"elapsed time for unblanced 15,000: " << elapsed_seconds.count()<< " seconds" << endl;//display time

	//---------------------------------------
	start = std::chrono::system_clock::now();//start time for balanced

	for (int i =0; i<20000; i++){//balanced tree
		randNum = rand() %20000;

		while(bal20.insert(randNum)==false){
			randNum = rand() %20000;
			
		}
		bal20.insert(randNum);
	}

	end = std::chrono::system_clock::now();//end time
	elapsed_seconds = end-start;//elapsed time
    	std::cout <<"elapsed time for blanced 20,000: " << elapsed_seconds.count()<< " seconds" << endl;//display time
	
	
	//--------------------------------

	start = std::chrono::system_clock::now();//start time for unbalanced

	

	for(int i = 0; i <20000; i++){ //unbalanced tree

		unBal20.insert(i);

	}
	
	end = std::chrono::system_clock::now();//end time
	elapsed_seconds = end-start;//elapsed time
    	std::cout <<"elapsed time for unblanced 20,000: " << elapsed_seconds.count()<< " seconds" << endl;//display time

	//---------------------------------------
	cout << endl;

	start = std::chrono::system_clock::now();//start time for unbalanced

	for (int i=0; i<5000; i++){

		unBal10.find(i);
	}

	end = std::chrono::system_clock::now();//end time
	elapsed_seconds = end-start;//elapsed time
    	std::cout <<"elapsed time for unblanced 10,000: " << elapsed_seconds.count()<< " seconds" << endl;//display time

	//---------------------------------------

	start = std::chrono::system_clock::now();//start time for balanced

	for (int i=0; i<5000; i++){

		randNum = rand() %5000;

		bal10.find(randNum);
	}

	end = std::chrono::system_clock::now();//end time
	elapsed_seconds = end-start;//elapsed time
    	std::cout <<"elapsed time for blanced 10,000: " << elapsed_seconds.count()<< " seconds" << endl;//display time

	//---------------------------------------

	start = std::chrono::system_clock::now();//start time for unbalanced

	for (int i=0; i<7500; i++){

		unBal15.find(i);
	}

	end = std::chrono::system_clock::now();//end time
	elapsed_seconds = end-start;//elapsed time
    	std::cout <<"elapsed time for unblanced 15,000: " << elapsed_seconds.count()<< " seconds" << endl;//display time

	//---------------------------------------

	start = std::chrono::system_clock::now();//start time for balanced

	for (int i=0; i<7500; i++){

		randNum = rand() %7500;

		bal15.find(randNum);
	}

	end = std::chrono::system_clock::now();//end time
	elapsed_seconds = end-start;//elapsed time
    	std::cout <<"elapsed time for blanced 15,000: " << elapsed_seconds.count()<< " seconds" << endl;//display time

	//---------------------------------------

	start = std::chrono::system_clock::now();//start time for unbalanced

	for (int i=0; i<10000; i++){

		unBal20.find(i);
	}

	end = std::chrono::system_clock::now();//end time
	elapsed_seconds = end-start;//elapsed time
    	std::cout <<"elapsed time for unblanced 20,000: " << elapsed_seconds.count()<< " seconds" << endl;//display time

	//---------------------------------------

	start = std::chrono::system_clock::now();//start time for balanced

	for (int i=0; i<10000; i++){

		randNum = rand() %10000;

		bal20.find(randNum);
	}

	end = std::chrono::system_clock::now();//end time
	elapsed_seconds = end-start;//elapsed time
    	std::cout <<"elapsed time for blanced 20,000: " << elapsed_seconds.count()<< " seconds" << endl;//display time

	//---------------------------------------
	cout << endl;

	start = std::chrono::system_clock::now();//start time for unbalanced

	for (int i=0; i<4425; i++){

		unBal10.remove(i);
	}

	end = std::chrono::system_clock::now();//end time
	elapsed_seconds = end-start;//elapsed time
    std::cout <<"elapsed time for unblanced 10,000: " << elapsed_seconds.count()<< " seconds" << endl;//display time

	//---------------------------------------

	start = std::chrono::system_clock::now();//start time for balanced

	for (int i=0; i<4425; i++){

		randNum = rand() %5000;

		while(bal10.remove(randNum)==false){
			randNum = rand() %5000;
			
		}
		bal10.remove(randNum);
	}

	end = std::chrono::system_clock::now();//end time
	elapsed_seconds = end-start;//elapsed time
    	std::cout <<"elapsed time for blanced 10,000: " << elapsed_seconds.count()<< " seconds" << endl;//display time

	//---------------------------------------

	start = std::chrono::system_clock::now();//start time for unbalanced

	for (int i=0; i<5000; i++){

		unBal15.remove(i);
	}

	end = std::chrono::system_clock::now();//end time
	elapsed_seconds = end-start;//elapsed time
    	std::cout <<"elapsed time for unblanced 15,000: " << elapsed_seconds.count()<< " seconds" << endl;//display time

	//---------------------------------------

	start = std::chrono::system_clock::now();//start time for balanced

	for (int i=0; i<5000; i++){

		randNum = rand() %7500;

		while(bal15.remove(randNum)==false){
			randNum = rand() %7500;
			
		}
		bal15.remove(randNum);
	}

	end = std::chrono::system_clock::now();//end time
	elapsed_seconds = end-start;//elapsed time
    	std::cout <<"elapsed time for blanced 15,000: " << elapsed_seconds.count()<< " seconds" << endl;//display time

	//---------------------------------------

	start = std::chrono::system_clock::now();//start time for unbalanced

	for (int i=0; i<7000; i++){

		unBal20.remove(i);
	}

	end = std::chrono::system_clock::now();//end time
	elapsed_seconds = end-start;//elapsed time
    	std::cout <<"elapsed time for unblanced 20,000: " << elapsed_seconds.count()<< " seconds" << endl;//display time

	//---------------------------------------

	start = std::chrono::system_clock::now();//start time for balanced

	for (int i=0; i<7000; i++){

		randNum = rand() %10000;

		while(bal20.remove(randNum)==false){
			randNum = rand() %10000;
			
		}
		bal20.remove(randNum);
	}

	end = std::chrono::system_clock::now();//end time
	elapsed_seconds = end-start;//elapsed time
    std::cout <<"elapsed time for blanced 20,000: " << elapsed_seconds.count()<< " seconds" << endl;//display time












//	BST<int> bal10;
//	BST<int>unBal10;

//	BST<int> bal15;
//	BST<int>unBal15;

//	BST<int> bal20;
//	BST<int>unBal20;

//	
//	int randNum;
//	

//	std::chrono::time_point<std::chrono::system_clock> start, end;

//	start = std::chrono::system_clock::now();//start time for balanced

//	for (int i =0; i<10000; i++){//balanced tree
//		randNum = rand() %10000;

//		while(bal10.insert(randNum)==false){
//			randNum = rand() %10000;
//			
//		}
//		bal10.insert(randNum);
//	}

//	end = std::chrono::system_clock::now();//end time
//	std::chrono::duration<double> elapsed_seconds = end-start;//elapsed time
//    	std::cout <<"elapsed time for blanced 10,000: " << elapsed_seconds.count()<< " seconds" << endl;//display time

//	//--------------------------------

//	start = std::chrono::system_clock::now();//start time for unbalanced

//	

//	for(int i = 0; i <10000; i++){ //unbalanced tree

//		unBal10.insert(i);

//	}
//	
//	end = std::chrono::system_clock::now();//end time
//	elapsed_seconds = end-start;//elapsed time
//    	std::cout <<"elapsed time for unblanced 10,000: " << elapsed_seconds.count()<< " seconds" << endl;//display time

//	//---------------------------------------
//	start = std::chrono::system_clock::now();//start time for balanced

//	for (int i =0; i<15000; i++){//balanced tree
//		randNum = rand() %15000;

//		while(bal15.insert(randNum)==false){
//			randNum = rand() %15000;
//			
//		}
//		bal15.insert(randNum);
//	}

//	end = std::chrono::system_clock::now();//end time
//	elapsed_seconds = end-start;//elapsed time
//    	std::cout <<"elapsed time for blanced 15,000: " << elapsed_seconds.count()<< " seconds" << endl;//display time
//	
//	
//	//--------------------------------

//	start = std::chrono::system_clock::now();//start time for unbalanced

//	

//	for(int i = 0; i <15000; i++){ //unbalanced tree

//		unBal15.insert(i);

//	}
//	
//	end = std::chrono::system_clock::now();//end time
//	elapsed_seconds = end-start;//elapsed time
//    	std::cout <<"elapsed time for unblanced 15,000: " << elapsed_seconds.count()<< " seconds" << endl;//display time

//	//---------------------------------------
//	start = std::chrono::system_clock::now();//start time for balanced

//	for (int i =0; i<20000; i++){//balanced tree
//		randNum = rand() %20000;

//		while(bal20.insert(randNum)==false){
//			randNum = rand() %20000;
//			
//		}
//		bal20.insert(randNum);
//	}

//	end = std::chrono::system_clock::now();//end time
//	elapsed_seconds = end-start;//elapsed time
//    	std::cout <<"elapsed time for blanced 20,000: " << elapsed_seconds.count()<< " seconds" << endl;//display time
//	
//	
//	//--------------------------------

//	start = std::chrono::system_clock::now();//start time for unbalanced

//	

//	for(int i = 0; i <20000; i++){ //unbalanced tree

//		unBal20.insert(i);

//	}
//	
//	end = std::chrono::system_clock::now();//end time
//	elapsed_seconds = end-start;//elapsed time
//    	std::cout <<"elapsed time for unblanced 20,000: " << elapsed_seconds.count()<< " seconds" << endl;//display time

//	//---------------------------------------
//	cout << endl;

//	start = std::chrono::system_clock::now();//start time for unbalanced

//	for (int i=0; i<5000; i++){

//		unBal10.find(i);
//	}

//	end = std::chrono::system_clock::now();//end time
//	elapsed_seconds = end-start;//elapsed time
//    	std::cout <<"elapsed time for unblanced 10,000: " << elapsed_seconds.count()<< " seconds" << endl;//display time

//	//---------------------------------------

//	start = std::chrono::system_clock::now();//start time for balanced

//	for (int i=0; i<5000; i++){

//		randNum = rand() %5000;

//		bal10.find(randNum);
//	}

//	end = std::chrono::system_clock::now();//end time
//	elapsed_seconds = end-start;//elapsed time
//    	std::cout <<"elapsed time for blanced 10,000: " << elapsed_seconds.count()<< " seconds" << endl;//display time

//	//---------------------------------------

//	start = std::chrono::system_clock::now();//start time for unbalanced

//	for (int i=0; i<7500; i++){

//		unBal15.find(i);
//	}

//	end = std::chrono::system_clock::now();//end time
//	elapsed_seconds = end-start;//elapsed time
//    	std::cout <<"elapsed time for unblanced 15,000: " << elapsed_seconds.count()<< " seconds" << endl;//display time

//	//---------------------------------------

//	start = std::chrono::system_clock::now();//start time for balanced

//	for (int i=0; i<7500; i++){

//		randNum = rand() %7500;

//		bal15.find(randNum);
//	}

//	end = std::chrono::system_clock::now();//end time
//	elapsed_seconds = end-start;//elapsed time
//    	std::cout <<"elapsed time for blanced 15,000: " << elapsed_seconds.count()<< " seconds" << endl;//display time

//	//---------------------------------------

//	start = std::chrono::system_clock::now();//start time for unbalanced

//	for (int i=0; i<10000; i++){

//		unBal20.find(i);
//	}

//	end = std::chrono::system_clock::now();//end time
//	elapsed_seconds = end-start;//elapsed time
//    	std::cout <<"elapsed time for unblanced 20,000: " << elapsed_seconds.count()<< " seconds" << endl;//display time

//	//---------------------------------------

//	start = std::chrono::system_clock::now();//start time for balanced

//	for (int i=0; i<10000; i++){

//		randNum = rand() %10000;

//		bal20.find(randNum);
//	}

//	end = std::chrono::system_clock::now();//end time
//	elapsed_seconds = end-start;//elapsed time
//    	std::cout <<"elapsed time for blanced 20,000: " << elapsed_seconds.count()<< " seconds" << endl;//display time

//	//---------------------------------------
//	cout << endl;

//	start = std::chrono::system_clock::now();//start time for unbalanced

//	for (int i=0; i<4425; i++){

//		unBal10.remove(i);
//	}

//	end = std::chrono::system_clock::now();//end time
//	elapsed_seconds = end-start;//elapsed time
//    	std::cout <<"elapsed time for unblanced 10,000: " << elapsed_seconds.count()<< " seconds" << endl;//display time

//	//---------------------------------------

//	start = std::chrono::system_clock::now();//start time for balanced

//	for (int i=0; i<4425; i++){

//		randNum = rand() %5000;

//		while(bal10.remove(randNum)==false){
//			randNum = rand() %5000;
//			
//		}
//		bal10.remove(randNum);
//	}

//	end = std::chrono::system_clock::now();//end time
//	elapsed_seconds = end-start;//elapsed time
//    	std::cout <<"elapsed time for blanced 10,000: " << elapsed_seconds.count()<< " seconds" << endl;//display time

//	//---------------------------------------

//	start = std::chrono::system_clock::now();//start time for unbalanced

//	for (int i=0; i<5000; i++){

//		unBal15.remove(i);
//	}

//	end = std::chrono::system_clock::now();//end time
//	elapsed_seconds = end-start;//elapsed time
//    	std::cout <<"elapsed time for unblanced 15,000: " << elapsed_seconds.count()<< " seconds" << endl;//display time

//	//---------------------------------------

//	start = std::chrono::system_clock::now();//start time for balanced

//	for (int i=0; i<5000; i++){

//		randNum = rand() %7500;

//		while(bal15.remove(randNum)==false){
//			randNum = rand() %7500;
//			
//		}
//		bal15.remove(randNum);
//	}

//	end = std::chrono::system_clock::now();//end time
//	elapsed_seconds = end-start;//elapsed time
//    	std::cout <<"elapsed time for blanced 15,000: " << elapsed_seconds.count()<< " seconds" << endl;//display time

//	//---------------------------------------

//	start = std::chrono::system_clock::now();//start time for unbalanced

//	for (int i=0; i<7000; i++){

//		unBal20.remove(i);
//	}

//	end = std::chrono::system_clock::now();//end time
//	elapsed_seconds = end-start;//elapsed time
//    	std::cout <<"elapsed time for unblanced 20,000: " << elapsed_seconds.count()<< " seconds" << endl;//display time

//	//---------------------------------------

//	start = std::chrono::system_clock::now();//start time for balanced

//	for (int i=0; i<7000; i++){

//		randNum = rand() %10000;

//		while(bal20.remove(randNum)==false){
//			randNum = rand() %10000;
//			
//		}
//		bal20.remove(randNum);
//	}

//	end = std::chrono::system_clock::now();//end time
//	elapsed_seconds = end-start;//elapsed time
//    	std::cout <<"elapsed time for blanced 20,000: " << elapsed_seconds.count()<< " seconds" << endl;//display time
}