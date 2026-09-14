#include <vector>
#include <assert.h>
#include <iostream>

using namespace std;


//to test the program, Define DEBUG, like seen under here, it also prints out an example of a sorted vector after sorting an unsorted vector
//#define DEBUG

//only run asserts if DEBUG is defined
#define NDEBUG
#ifdef DEBUG
#undef NDEBUG
#endif


class merge_sort{
	public:
		merge_sort(){
			#ifdef DEBUG
				test_sort();
			#endif
			
		};
	#define UPPERBOUND(x) (x.size()-1)
	#define LOWERBOUND 0
		static vector<int> sort(vector<int> arr){
			return MergeSort(arr, LOWERBOUND, UPPERBOUND(arr));
		}
	private:
		static vector<int> MergeSort(vector<int> arr, int StartSeperationPoint, int EndSeperationPoint){
			//if array is only 1 point then return that point
			if(StartSeperationPoint==EndSeperationPoint){
				return {arr[StartSeperationPoint]};
			}
			else{
			//we seperate the arr from the middle of our seperation points, and it's important that the points that we use don't overlap
			int NewSeperationPoint = (StartSeperationPoint+EndSeperationPoint)/2;
			vector<int> SortedVectorLeft = MergeSort(arr,StartSeperationPoint,NewSeperationPoint);
			vector<int> SortedVectorRight = MergeSort(arr,NewSeperationPoint+1, EndSeperationPoint);
			//we combine the arrays with the assumption that they are sorted, p.s. arrays with a size of 1 are always sorted.
			vector<int >SortedArr = Merge_SortedVector(SortedVectorLeft, SortedVectorRight);
			return SortedArr;
			}
		}
		static vector<int> Merge_SortedVector(vector<int> SortedVectorLeft, vector<int>SortedVectorRight){
			//merge the passed vectors into one big sorted vector
			//we assume the input is sorted, cause it allows for a faster combination
			assert(test_if_sorted_Low_To_High(SortedVectorLeft));
			assert(test_if_sorted_Low_To_High(SortedVectorRight));

			int leftindex =0;
			int rightindex = 0;
			int mergedArrIndex =0;
			//initialization of the array that we are goint to insert the Passed-data in an ordered way
			vector<int> mergedArr;
			mergedArr.resize((SortedVectorLeft.size()+SortedVectorRight.size()));
			//insert until we have inserted everything from one of the Passed-arrays
			while(leftindex<(SortedVectorLeft.size()) && rightindex<(SortedVectorRight.size())){
			if(SortedVectorLeft[leftindex]<=SortedVectorRight[rightindex]){

				mergedArr[mergedArrIndex] = SortedVectorLeft[leftindex];
				leftindex++;
			}else{
				mergedArr[mergedArrIndex] = SortedVectorRight[rightindex];
				rightindex++;
			}
			mergedArrIndex++;
			}
			//if there's any data left from the passed data then we insert it at the end
			while(leftindex<SortedVectorLeft.size()){
				mergedArr[mergedArrIndex] = SortedVectorLeft[leftindex];
				leftindex++;
				mergedArrIndex++;
			}
			while(rightindex<SortedVectorRight.size()){		
				mergedArr[mergedArrIndex] = SortedVectorRight[rightindex];
				rightindex++;
				mergedArrIndex++;
			}
			return mergedArr;
		}
		static void test_sort(){
			//we test the Merge part of the sorting algo, if it returns an sorted arr with the kind of input that it expects
			vector<int> merge_test = Merge_SortedVector({1,3}, {0,2});
			assert(test_if_sorted_Low_To_High(merge_test));
			//we test if the sorting algo returns an sorted arr
			vector<int> test_arr= {3, 2, -1,  6, 4, 7, 8, 10, 13, 99, -99, 17};
			vector<int> sorted_arr = sort(test_arr);
			assert(test_if_sorted_Low_To_High(sorted_arr));
			//the printing of the completed arr
			for(int i = 0; i<sorted_arr.size(); i++)
				cout<<"index "<<i<<": "<< sorted_arr[i]<<'\n';

		}
		static bool test_if_sorted_Low_To_High(vector <int> sorted_arr){
			//we check if the passed data is sorted by checking by going though the array and checking if the point before is larger
			for(int index=1; index<sorted_arr.size(); index++){
				if(sorted_arr[index]<sorted_arr[index-1]){
					return false;
				}
			}
			return true;
		}
		
};

int main(){
	merge_sort instance;
}
