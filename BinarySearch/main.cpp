#include <iostream>
#include <vector>
#include <assert.h>

//define DEBUG for testing purposes
//#define DEBUG

#ifdef DEBUG
	#undef NDEBUG
#endif
using namespace std;

class Search{
	public:
		Search(){
			#ifdef DEBUG
				test_suite();
			#endif
		}
	#define UPPERBOUND(x) (x.size()-1)
		int Algo_Search(vector<int> arr, int NumToFind){
			int placement = Binary_Search(arr, NumToFind, 0, UPPERBOUND(arr));
			return placement;
		}
	private:
		int Binary_Search(vector<int> arr, int NumToFind, int LowerBound, int UpperBound){
			int middle = (UpperBound-LowerBound)/2;

			//error handling, incase that the number doesn't exist, and then we return -1, cause that ain't a natural placement
			if((UpperBound <=LowerBound) && (arr[LowerBound+middle]!=NumToFind))
				return -1;
			
			//we assume the array is sorted, so the element value should point in the direction of NumToFind, meaning, if it's either higher or lower, then, we can eliminate half of the array, and if it's equal, then we know what element NumToFind is
			if(arr[LowerBound+middle]>NumToFind){
				return Binary_Search(arr, NumToFind, LowerBound, UpperBound-middle);
			}
			else if(arr[LowerBound+middle]<NumToFind){
				return Binary_Search(arr, NumToFind, LowerBound+middle+1, UpperBound);
			}
			else {
				return LowerBound+middle;
			}
		}
		void test_suite(){
			//We are testing if the return value is the same as the inputted value
			vector<int> arr = {1,2,3,4,5,6, 8, 40, 50};
			int index_to_search =7;
			int placement = Algo_Search(arr, arr[index_to_search]);
			assert((placement==index_to_search));
			}
		};

int main(){
	Search instance;
}
